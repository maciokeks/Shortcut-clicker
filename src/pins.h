#define P1 10
#define P2 6
#define P3 8
#define P4 9
//screen
#define Sda 2
#define Scl 3
//conections
/*
 * screen:
 * SDA-2
 * SCL-3
 * GND-GND
 * VCC-VCC/3.3v/5v
 * buttons:
 * /FIRST OPTION for advanced message/
 * NOTE: if you are going to use advanced mode add pull down resisor if you are using digitalRead() for button state, and change for pinMode(pin,INPUT)
 * With resistor like 10KOHM:
 *   5V 
 *   |
 * *------*------*------*
 * |<R>GND|<R>GND|<R>GND|<R>GND
 * |      |      |      |
 * ADC   ADC    ADC    ADC
 * Normal:
 *   5V 
 *   |
 * *---*----*----*
 * |   |    |    |
 * ADC ADC  ADC ADC
 * /SECOND OPTION for basic message/
 *   GND 
 *   |
 * *---*----*----*
 * |   |    |    |
 * N   N    N    N
 * *N <-normal pin mean you can connect to any pin if you want
 * 
 * Reset butts:
 *    ||
 *   ||||
 *  ||||||
 * *      *
 * |      |
 * GND    RST pin
 * Knowledge:
 *  *If you want to get ADC value from votage use this scheme*
 *  
 *  Resolution ADC       ADC reading
 *  -------------- = ------------------
 *  System voltage    Analog V measured
 */
