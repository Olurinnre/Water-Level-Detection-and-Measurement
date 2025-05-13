#include <xc.h>
#include <math.h>
#pragma config FOSC = HS       
#pragma config WDTE = OFF       
#pragma config PWRTE = OFF      
#pragma config BOREN = OFF      
#pragma config LVP = OFF        
#pragma config CPD = OFF        
#pragma config WRT = OFF        
#pragma config CP = OFF  
#define _XTAL_FREQ 20000000
#include "LCDLIBRARY1.h"
int num = 0;
int distance;
int transfer(){
    
    num=0;
    wait:
    if(RB0) __delay_ms(1);
    else goto wait;
    if(RB0) __delay_ms(1);
    else goto wait;
    if(RB0) __delay_ms(1);
    else goto wait;
    if(RB0) __delay_ms(1);
    else goto wait;
    if(RB0) __delay_ms(1);
    else goto wait;
    if(RB0) __delay_ms(1);
    else goto wait;
    if(RB0) __delay_ms(1);
    else goto wait;
    if(RB0) __delay_ms(1);
    else goto wait;
    if(RB0) __delay_ms(1);
    else goto wait;
    if(RB0) __delay_ms(1);
    else goto wait;
    
    __delay_ms(2);
    if(RB0) num += 128;
    __delay_ms(4);
     if(RB0) num += 64;
    __delay_ms(4);
     if(RB0) num += 32;
    __delay_ms(4);
     if(RB0) num += 16;
    __delay_ms(4);
     if(RB0) num += 8;
    __delay_ms(4);
     if(RB0) num += 4;
    __delay_ms(4);
     if(RB0) num += 2;
    __delay_ms(4);
     if(RB0) num += 1;
    return num;
}


long freq;

int PWM_Max_Duty()
{
  return(_XTAL_FREQ/(freq*4));
}

PWM1_Init(long fre)
{
  PR2 = (_XTAL_FREQ/(fre*16)) - 1;
  freq = fre;
}

PWM1_Duty(unsigned int duty)
{
  if(duty<1024)
  {
    duty = ((float)duty/1023)*PWM_Max_Duty();
    CCP1X = duty & 2;
    CCP1Y = duty & 1;
    CCPR1L = duty>>2;
  }
}


PWM1_Start()
{
  CCP1M3 = 1;
  CCP1M2 = 1;
  T2CKPS0 = 1;
  T2CKPS1 = 0;
  TMR2ON = 1;
  TRISC2 = 0;
}

PWM1_Stop()
{
  CCP1M3 = 0;
  CCP1M2 = 0;
}
void __interrupt() ISR(){
    if(INTF){
       distance = transfer();
  
       if(distance > 85){
        PWM1_Start();
       }
       else{
           PWM1_Stop();
       }
       
       INTF = 0;
    }

}
void main(void) {
    GIE = 1;
    PEIE =1;
    INTE = 1;
    INTEDG = 1;
    TRISA=0;
    TRISB=0b00000001;
    TRISD=0;
    PORTB=0;
    PORTD=0;
    TRISC=0;
    PWM1_Init(2300);
    PWM1_Duty(50);
    config();
    CLRDISP();
    while(1){
     CURSOR(FIRSTROW,0);
     LCDWRITE("Your tank is:");
     CURSOR(SECONDROW,0);
     NUMDISP(distance);
     LCDWRITE("% full");

   }   
    return;
}