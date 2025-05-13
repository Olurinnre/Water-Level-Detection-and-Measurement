#include <xc.h>
#include <math.h>
#pragma config FOSC = HS        
#pragma config WDTE = ON       
#pragma config PWRTE = OFF      
#pragma config BOREN = OFF      
#pragma config LVP = OFF        
#pragma config CPD = OFF        
#pragma config WRT = OFF 
#pragma config CP = OFF

#define _XTAL_FREQ 20000000
#define trigger RB1
#define echo RB2



int timet;
float distance; 
int percent;

void send_ppp(int txnum){
   
    RC6=1;
    __delay_ms(10);
    
     
    if(txnum & 0b10000000) {
        RC6=1;
    }else{
        RC6=0;
    }
    __delay_ms(4);
    if(txnum & 0b01000000) {
        RC6=1;
    }else{
        RC6=0;
    }
    __delay_ms(4);
    if(txnum & 0b00100000) {
        RC6=1;
    }else{
        RC6=0;
    }
    __delay_ms(4);
    if(txnum & 0b00010000) {
        RC6=1;
    }else{
        RC6=0;
    }
    __delay_ms(4);
    if(txnum & 0b00001000) {
        RC6=1;
    }else{
        RC6=0;
    }
    __delay_ms(4);
    if(txnum & 0b00000100) {
        RC6=1;
    }else{
        RC6=0;
    }
    __delay_ms(4);
     if(txnum & 0b00000010) {
        RC6=1;
    }else{
        RC6=0;
    }
    __delay_ms(4);
     if(txnum & 0b00000001) {
        RC6=1;
    }else{
        RC6=0;
    }
    __delay_ms(4);
    RC6 =0;
}


void main(void) {
    PSA = 1;
    PS0 = 1;
    PS1 = 1;
    PS2 = 1;
    TRISA = TRISB = TRISC = TRISD = TRISE = 0;
    PORTA = PORTB = PORTC = PORTD = PORTE = 0;
    INTCON = 0b11000000;
    T1CON=0b00100000;
    TRISA0=0;
    TRISB0 = 1;
    TRISB1 = 0;
    TRISB2 = 1;
    
    percent = 0;
    while(1){
        TMR1L = 0; 
        TMR1H = 0;
          RA0 = 1;        
        trigger = 1;
        __delay_us(10);
        trigger = 0;
        while(!echo);
        TMR1ON = 1;
       while(echo);
        TMR1ON = 0;
        RA0 = 0;
        timet = TMR1L|(TMR1H<<8);
       distance = 0.0136*timet;
        percent = round((18-distance)*5.5556);
        send_ppp(percent);
        }
    return;
}