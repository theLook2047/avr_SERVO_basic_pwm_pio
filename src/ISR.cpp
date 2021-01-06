#include "user.h"

int ovfCnt, increment{ 5 };

// 20,000us 를 2,500us 로 총 8개의 구간으로 분할한 방식
SIGNAL(TIMER1_COMPA_vect)
{
    if(ovfCnt%8==0)
         SERVO_PORT &= ~(1<<PB5);
         
}

SIGNAL(TIMER1_OVF_vect) 
{
    TCNT1=BOTTOM;
    
    if(ovfCnt%8==7) { // 총 4us * 625 * 8 = 20,000usus
        SERVO_PORT |= 1<<PB5;
        OCR1A +=increment;
    Serial.println(OCR1A);
        if(OCR1A<=MIN/TICK-1+BOTTOM || OCR1A>=MAX/TICK-1+BOTTOM) 
            increment*=-1;
    }
    ++ovfCnt %= 32768;
}