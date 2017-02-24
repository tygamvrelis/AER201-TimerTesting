#include <xc.h>
#include <stdio.h>
#include "configBits.h"
#include "constants.h"
#include "main.h"
#include "macros.h"
#include "I2C.h"
#include "RTC.h"
#include "lcd.h"

// Interrupt handler
void interrupt handler(void) {   
    //** 1 SECOND TIMER THAT CALLS printRTC() using Timer0 **
    di();
    if(TMR0IF){
        TMR0IF = 0;
        count++;
        TMR0ON = 0;
        // Print out test #
        printRTC();
        __lcd_newline();
        printf("Test %d: Timer0", count);
        
        if(count<9){
            // Initialize timer again!
            T0CON = 0b00010111;
            TMR0H = 0b10000101;
            TMR0L = 0b11101110;
            T0CON = T0CON | 0b10000000;
        }
    }
    
    //** 20 ms TIMER THAT CALLS printRTC() using Timer1 **
    if(TMR1IF){
        TMR1IF = 0;
        count++;
        TMR1ON = 0;
        // Print out test #
        printRTC();
        __lcd_newline();
        printf("Test %d: Timer1", count);

        if(count<500){
            // Initialize timer again!
            T1CON = 0b10110000;
            TMR1H = 0b10110001;
            TMR1L = 0b11100000;
            TMR1ON = 1;
        }
    }
    
    //** TIMER THAT CALLS printRTC() using Timer2 **
    if(TMR2IF){
        TMR2IF = 0;
        count++;
        TMR2ON = 0;
        
        // Print out test #
        printRTC();
        __lcd_newline();
        printf("Test %d: Timer2", count);

        if(count<1200){
            // Initialize timer again!
            T2CON = 0b01111011; // 1:16 postscale (not taken into account for comp. with PR2), 16x prescaler
            PR2 = 0xFF;
            T2CON = T2CON | 0b00000100;
        }
    }
    
    //** 20 ms TIMER THAT CALLS printRTC() using Timer3 **
    if(TMR3IF){
        TMR3IF = 0;
        count++;
        TMR3ON = 0;
        // Print out test #
        printRTC();
        __lcd_newline();
        printf("Test %d: Timer3", count);
        
        if(count<500){
            // Initialize timer again!
            T3CON = 0b10110100;
            TMR3H = 0b10110001;
            TMR3L = 0b11100000;
            T3CON = T3CON | 0b00000001;
        }
    }
    ei();
}