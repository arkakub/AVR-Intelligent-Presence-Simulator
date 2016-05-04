
#include <avr/io.h>
#include <avr/interrupt.h>

#include "lcd.h"

#define LOAD_DDR DDRC
#define LOAD_PORT PORTC
#define LOAD_POS0 PC0
#define LOAD_POS1 PC1

volatile unsigned int clock_millisecond=0;
volatile int8_t	clock_second=0;
volatile int8_t clock_minute=0;
volatile int8_t clock_hour=0;

volatile int8_t	hr1,min1;
volatile int8_t	hr2, min2;
volatile int8_t	hr3,min3;
volatile int8_t	hr4, min4;
volatile uint8_t selection=1;
volatile uint8_t old_pinb;

void Wait(uint8_t n) {

	uint8_t i,temp;
	temp=n*28;

	for(i=0;i<temp;i++)
	_delay_loop_2(0);
	
}

void LoadOn1() {
	
	LOAD_PORT|=(1<<LOAD_POS0);
	
}

void LoadOff1() {
	
	LOAD_PORT&=(~(1<<LOAD_POS0));
	
}

void LoadOn2() {
	
	LOAD_PORT|=(1<<LOAD_POS1);
	
}

void LoadOff2() {
	
	LOAD_PORT&=(~(1<<LOAD_POS1));
	
}

void SetDevice1() {
	
	LCDClear();
	
	LCDWriteString("On00:00 Off00:00");
	LCDWriteStringXY(0,1," Ustaw  Urzadz_1");
	
	selection=0;
	old_pinb=PINB;
	
	while(1) {
		
		while((PINB & 0b00000111) == (old_pinb & 0b00000111));

		if(!(PINB & (1<<PINB2)) && (old_pinb & (1<<PB2))) {
			
			selection++;
			if(selection==5)
			selection =0;
			
		}
		
		if(!(PINB & (1<<PINB1)) && (old_pinb & (1<<PB1))) {
			
			if(selection == 0) {
				
				hr1++;
				if(hr1 == 24)
				hr1 =0;
				
			}

			if(selection == 1) {

				min1++;
				if(min1 == 60)
				min1 =0;
				
			}

			if(selection == 2) {
				
				hr2++;
				if(hr2 == 24)
				hr2 =0;
				
			}

			if(selection == 3) {
				
				min2++;
				if(min2 == 60)
				min2 =0;
				
			}
			
			if(selection == 4) {
				
				break;
				
			}
		}

		if(!(PINB & (1<<PINB0)) && (old_pinb & (1<<PB0))) {
			
			if(selection == 0) {


				hr1--;
				if(hr1== -1)
				hr1 =23;
				
			}

			if(selection == 1) {

				min1--;
				if(min1 == -1)
				min1 =59;
				
			}

			if(selection == 2) {
	
				hr2--;
				if(hr2== -1)
				hr2 =23;
				
			}
			
			if(selection == 3) {

				min2--;
				if(min2 == -1)
				min2 =59;
				
			}
			
			if(selection == 4) {

				break;
				
			}
		}
		
		old_pinb=PINB;
		
		LCDClear();
		LCDWriteString("On00:00 Off00:00");
	
		LCDWriteStringXY(0,1," Ustaw  Urzadz_1");
		
		LCDWriteIntXY(2,0,hr1,2);

		LCDWriteIntXY(5,0,min1,2);
		
		LCDWriteIntXY(11,0,hr2,2);

		LCDWriteIntXY(14,0,min2,2);

		if(selection == 0)
		LCDWriteStringXY(3,1,"^");
		
		if(selection == 1)
		LCDWriteStringXY(5,1,"^");

		if(selection == 2)
		LCDWriteStringXY(11,1,"^");
		
		if(selection == 3)
		LCDWriteStringXY(14,1,"^");
		
		if(selection == 4)
		LCDWriteStringXY(0,1,">");


		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);

		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
		
	}
	
	selection=0;
	old_pinb=PINB;
	
}

void SetDevice2() {
	
	LCDClear();
	
	LCDWriteString("On00:00 Off00:00");
	
	LCDWriteStringXY(0,1," Ustaw  Urzadz_2");
	
	selection=0;
	old_pinb=PINB;
	
	while(1) {
		
		while((PINB & 0b00000111) == (old_pinb & 0b00000111));
		

		if(!(PINB & (1<<PINB2)) && (old_pinb & (1<<PB2))) {

			selection++;
			if(selection==5)
			selection =0;
			
		}
		
		if(!(PINB & (1<<PINB1)) && (old_pinb & (1<<PB1))) {
			
			if(selection == 0) {
				
				hr3++;
				if(hr3 == 24)
				hr3 =0;
				
			}

			if(selection == 1) {

				min3++;
				if(min3 == 60)
				min3 =0;
				
			}

			if(selection == 2) {
				
				hr4++;
				if(hr4 == 24)
				hr4 =0;
				
			}

			if(selection == 3) {
				
				min4++;
				if(min4 == 60)
				min4 =0;
				
			}
			
			if(selection == 4) {
				
				break;
				
			}
		}

		if(!(PINB & (1<<PINB0)) && (old_pinb & (1<<PB0))) {

			if(selection == 0) {

				hr3--;
				if(hr3== -1)
				hr3 =23;
				
			}

			if(selection == 1) {

				min3--;
				if(min3 == -1)
				min3 =59;
				
			}

			if(selection == 2) {

				hr4--;
				if(hr4== -1)
				hr4 =23;
				
			}
			
			if(selection == 3) {
				
				min4--;
				if(min4 == -1)
				min4 =59;
				
			}
			
			if(selection == 4) {
				
				break;
				
			}
			
		}
		
		old_pinb=PINB;
		
		LCDClear();
		LCDWriteString("On00:00 Off00:00");
		
		LCDWriteStringXY(0,1," Ustaw  Urzadz_2");
		
		LCDWriteIntXY(2,0,hr3,2);

		LCDWriteIntXY(5,0,min3,2);
		
		LCDWriteIntXY(11,0,hr4,2);

		LCDWriteIntXY(14,0,min4,2);

		if(selection == 0)
		LCDWriteStringXY(3,1,"^");
		
		if(selection == 1)
		LCDWriteStringXY(5,1,"^");

		if(selection == 2)
		LCDWriteStringXY(11,1,"^");
		
		if(selection == 3)
		LCDWriteStringXY(14,1,"^");
		
		if(selection == 4)
		LCDWriteStringXY(0,1,">");

		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);

		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
		
	}
	
	selection=0;
	old_pinb=PINB;
	
}

ISR(TIMER1_COMPA_vect) {
	
	clock_millisecond++;
	if(clock_millisecond==1000) {
		
		clock_second++;
		clock_millisecond=0;
		if(clock_second==60) {
			
			clock_minute++;
			clock_second=0;

			if(clock_minute==60) {
				
				clock_hour++;
				clock_minute=0;
				
				if(clock_hour==24) {
					
					clock_hour=0;	
					
				}
			}
		}
	}
}

int main(void) {
	
	LOAD_DDR|=(1<<LOAD_POS0);
	LOAD_DDR|=(1<<LOAD_POS1);

	LoadOff1();
	LoadOff2();
	
	PORTB|=((1<<PB2)|(1<<PB1)|(1<<PB0));

	int8_t hr,min;
	
	hr=min=hr1=min1=hr2=min2=0;

	InitLCD(0);
	LCDClear();

	TCCR1B=(1<<WGM12)|(1<<CS11)|(1<<CS10);
	OCR1A=250;

	TIMSK|=(1<<OCIE1A);

	sei();

	while(1) {
		
		LCDClear();
		LCDWriteString("  Symulator     ");
		LCDWriteStringXY(0,1,"    Domownikow  ");

		Wait(4);

		LCDClear();
		LCDWriteString("Ustaw czas 00:00");
		LCDWriteStringXY(0,1," Dalej     ^");

		old_pinb=PINB;

		while(1) {
			
			while((PINB & 0b00000111) == (old_pinb & 0b00000111));
			
			if(!(PINB & (1<<PINB2)) && (old_pinb & (1<<PB2))) {
				
				selection++;
				if(selection==3)
				selection =0;
				
			}

			if(!(PINB & (1<<PINB1)) && (old_pinb & (1<<PB1))) {
				
				if(selection == 1) {
					
					hr++;
					if(hr == 24)
					hr =0;
					
				}

				if(selection == 2) {

					min++;
					if(min == 60)
					min =0;
					
				}

				if(selection == 0) {
					
					break;
					
				}
				
			}

			if(!(PINB & (1<<PINB0)) && (old_pinb & (1<<PB0))) {
				
				if(selection == 1) {

					hr--;
					if(hr == -1)
					hr =23;
					
				}

				if(selection == 2) {

					min--;
					if(min == -1)
					min =59;
					
				}

				if(selection == 0) {
					
					break;
					
				}

			}

			old_pinb=PINB;

			LCDClear();
			LCDWriteString("Ustaw czas 00:00");
			LCDWriteStringXY(0,1," Dalej    ");

			LCDWriteIntXY(11,0,hr,2);

			LCDWriteIntXY(14,0,min,2);

			if(selection == 0)
			LCDWriteStringXY(0,1,">");
			
			if(selection == 1)
			LCDWriteStringXY(11,1,"^");

			if(selection == 2)
			LCDWriteStringXY(14,1,"^");

			_delay_loop_2(0);
			_delay_loop_2(0);
			_delay_loop_2(0);
			_delay_loop_2(0);

			_delay_loop_2(0);
			_delay_loop_2(0);
			_delay_loop_2(0);
			_delay_loop_2(0);
			
		}
		
		clock_hour = hr;
		clock_minute = min;
		clock_second =0;
		
		LCDClear();
		LCDWriteString(" Urzadz_1  Start");
		LCDWriteStringXY(0,1," Urzadz_2   ");
		
		selection=0;
		old_pinb=PINB;
		
		while(1) {
			
			while((PINB & 0b00000111) == (old_pinb & 0b00000111));
			
			if(!(PINB & (1<<PINB2)) && (old_pinb & (1<<PB2))) {
				
				selection++;
				if(selection==3)
				selection =0;
				
			}
			
			if(!(PINB & (1<<PINB1)) && (old_pinb & (1<<PB1))) {
			
				if(selection == 0) {
			
					SetDevice1();
					
				}

				if(selection == 1) {
					
					SetDevice2();
					
				}
				
				if(selection == 2) {
					
					break;
					
				}

			}

			if(!(PINB & (1<<PINB0)) && (old_pinb & (1<<PB0))) {

				if(selection == 0) {

					SetDevice1();
					
				}

				if(selection == 1) {
					
					SetDevice2();
					
				}
				
				if(selection == 2) {
					
					break;
					
				}

			}
				
			old_pinb=PINB;
			
			LCDClear();
			LCDWriteString(" Urzadz_1  Start");
			LCDWriteStringXY(0,1," Urzadz_2 ");

			if(selection == 0)
			LCDWriteStringXY(0,0,">");
			
			if(selection == 1)
			LCDWriteStringXY(0,1,">");
			
			if(selection == 2)
			LCDWriteStringXY(10,0,">");

			_delay_loop_2(0);
			_delay_loop_2(0);
			_delay_loop_2(0);
			_delay_loop_2(0);

			_delay_loop_2(0);
			_delay_loop_2(0);
			_delay_loop_2(0);
			_delay_loop_2(0);
			
		}
		
		LCDClear();
		LCDWriteString(" Aktualny czas: ");

		while(1) {
			
			LCDWriteIntXY(4,1,clock_hour,2);
			LCDWriteString(":");
			LCDWriteIntXY(7,1,clock_minute,2);
			LCDWriteString(":");
			LCDWriteIntXY(10,1,clock_second,2);

			if((clock_hour == hr1) && (clock_minute == min1) && (clock_second == 0)) {
			
				LoadOn1();
				
			}
			
			if((clock_hour == hr2) && (clock_minute == min2) && (clock_second == 0)) {
				
				LoadOff1();
				
			}
			
			if((clock_hour == hr3) && (clock_minute == min3) && (clock_second == 0)) {
				
				LoadOn2();
				
			}
			
			if((clock_hour == hr4) && (clock_minute == min4) && (clock_second == 0)) {
				
				LoadOff2();
				
			}	
				
			_delay_loop_2(0);
			_delay_loop_2(0);
			_delay_loop_2(0);
			_delay_loop_2(0);
			
		}
		
	}

}


