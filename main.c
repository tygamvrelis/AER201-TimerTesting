#include <xc.h>
#include <stdio.h>
#include "configBits.h"
#include "constants.h"
#include "main.h"
#include "macros.h"
#include "I2C.h"
#include "RTC.h"
#include "lcd.h"

void main(void) {
    machineConfig();
    initLCD();
    initTime(0x42, 0x32, 0x13, 0x04, 0x09, 0x02, 0x17);
    loadRTC();
    int k=0;
    
    // <editor-fold defaultstate="collapsed" desc="Timer0 Test">
    __lcd_clear();
    __lcd_home();
    __lcd_newline();
    printf("Test: Timer0");
    count=0;
    
    __lcd_home();printf("3");
    __delay_1s();__lcd_home();printf("2");
    __delay_1s();__lcd_home();printf("1");
    
    /* 1 s */
    T0CON = 0b00010111;
    TMR0H = 0b10000101;
    TMR0L = 0b11101110;
    T0CON = T0CON | 0b10000000;
    
    // You should watch the time on the LCD increase by 10 seconds.
    for(k=0; k<10; k++){__delay_1s();}
    
    __lcd_clear();
    __lcd_home();
    printf("Timer0 Done");
    __delay_1s();
    __lcd_clear();
    __lcd_home();
    printf("Timer1 test...");
    __lcd_newline();
    printf("Push to start"); 
    while(PORTBbits.RB1==0){
        // Wait for user input
    }
    // </editor-fold>
    
    // <editor-fold defaultstate="collapsed" desc="Timer1 Test">
    __lcd_clear();
    __lcd_home();
    __lcd_newline();
    printf("Test: Timer1");
    count=0;
    
    __lcd_home();printf("3");
    __delay_1s();__lcd_home();printf("2");
    __delay_1s();__lcd_home();printf("1");
    
    /* 20 ms */
    T1CON = 0b10110000;
    TMR1H = 0b10110001;
    TMR1L = 0b11100000;
    TMR1ON = 1;
    
    // You should watch the time on the LCD increase by 10 seconds.
    for(k=0; k<10; k++){__delay_1s();}

    __lcd_clear();
    __lcd_home();
    printf("Timer1 Done");
    __delay_1s();
    __lcd_clear();
    __lcd_home();
    printf("Timer2 test...");
    __lcd_newline();
    printf("Push to start"); 
    while(PORTBbits.RB1==0){
        // Wait for user input
    }
    // </editor-fold>

    // <editor-fold defaultstate="collapsed" desc="Timer2 Test">
    __lcd_clear();
    __lcd_home();
    __lcd_newline();
    printf("Test: Timer2");
    count=0;
    
    __lcd_home();printf("3");
    __delay_1s();__lcd_home();printf("2");
    __delay_1s();__lcd_home();printf("1");
    
    /* 1 s */
    T2CON = 0b01111011; // 1:16 postscale (not taken into account for comp. with PR2), 16x prescaler
    //TMR2 = 0x00;
    PR2 = 0xFF;
    T2CON = T2CON | 0b00000100;
    
   // You should watch the time on the LCD increase by 10 seconds.
    for(k=0; k<10; k++){__delay_1s();}

    __lcd_clear();
    __lcd_home();
    printf("Timer2 Done");
    __delay_1s();
    __lcd_clear();
    __lcd_home();
    printf("Timer3 test...");
    __lcd_newline();
    printf("Push to start"); 
    while(PORTBbits.RB1==0){
        // Wait for user input
    }
    // </editor-fold> 
    
    // <editor-fold defaultstate="collapsed" desc="Timer3 Test">
    __lcd_clear();
    __lcd_home();
    __lcd_newline();
    printf("Test: Timer3");
    count=0;
    
    __lcd_home();printf("3");
    __delay_1s();__lcd_home();printf("2");
    __delay_1s();__lcd_home();printf("1");
    
    /* 20 ms */
    T3CON = 0b10110000;
    TMR3H = 0b10110001;
    TMR3L = 0b11100000;
    T3CON = T3CON | 0b00000001;
    
   // You should watch the time on the LCD increase by 10 seconds.
    for(k=0; k<10; k++){__delay_1s();}

    __lcd_clear();
    __lcd_home();
    printf("Timer3 Done");
    __delay_1s();
    __lcd_clear();
    __lcd_home();
    printf("Tests complete");
    __lcd_newline();
    printf("You may reset"); 
    while(1){
        // Do nothing
    }
    // </editor-fold> 
}