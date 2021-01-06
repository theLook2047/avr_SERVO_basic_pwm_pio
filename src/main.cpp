#include "user.h"

void setup() {
    //Serial.begin(9600);
    SERVO_DDR=1<<DDB5;
    SERVO_PORT = 1<<PB5;
    
//  16BIT TIMER1
    TCCR1A = TCCR1B = 0;
    TCCR1A=1<<WGM11 | 1<<WGM10;               //FAST PWM 10BIT
    TCCR1B=1<<WGM12 | 1<<CS11 | 1<<CS10;      //64분주 : 4us
    TCNT1=BOTTOM, OCR1A=MIN/TICK-1+BOTTOM;
    TIMSK1=1<<OCIE1A | 1<<TOIE1;
}

void loop() {}



