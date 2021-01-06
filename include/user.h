#include <Arduino.h>

// 20,000us 를 2,500us 로 총 8개의 구간으로 분할한 방식
#define SERVO_DDR   DDRB
#define SERVO_PORT  PORTB

#define MAX          2450    // 180도 유지시간
#define MIN          550     // 0도 유지시간
#define PS           64      // preScale
#define TICK         (PS/16)  // 전처리기 사용시 주의!!!!!!!!!
//위는 정확히 얘기해서 1TICK 당 걸리는 시간을 의미
#define OVF          0x3FF    // overflow
#define PERIOD_SERV  2500
#define BOTTOM       (OVF-PERIOD_SERV/TICK)  // 전처리기 사용시 주의!!!!!!!!!
//2500US 를 채우기 위한 첫 번째 계단(TICK) 위치