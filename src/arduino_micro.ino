/*
  MIT License
  
  Copyright (c) 2021 110 101 118 101 114 032 117 115 101 032 116 104 105 115 032 105 110 032 112 114 111 102 105 108 101
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 */
#include "pins.h"
#include <Keyboard.h>
#include <U8g2lib.h>
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0,U8X8_PIN_NONE,Sda,Scl);   //For ep8266 but working with pro micro 
bool post = false; //change if you don't want to show messages on Serial monitor
#include "FastLED.h"
#define NUM_LEDS 4 
#define DATA A3
CRGB leds[NUM_LEDS];
#include "void.h"
#include "class.h"

//temporary variables 
bool inverted = true; //switch to true if button is inverted
int lvl = 1; //change if you want to get more information lvl=1 <-- basic state information lvl=2 <-- advanced information like voltage if you connect button to 5v 
unsigned int button_delay = 50;
byte wait = 40;//wait between click and release button
int button;
//available modes:
/*
 * 1->'single'<- just write char with DEC code
 * 2->'connection'<- in this mode you need to specify key and modifier (support up to 4 key code sent in the same time)
 * 3->'action'<- this mode write HID codes like(skip,stop vol up, vol down)codes....
 */
int mode = 2; // change for specific combination of key codes
//Single mode ASCII DEC key
int BTN1_key = 194;
int BTN2_key = 195;
int BTN3_key = 115;
int BTN4_key = 100;

//connection mode for up to 4 keys
int BTN1_connection[] = {194,NULL,NULL,NULL};
int BTN2_connection[] = {195,NULL,NULL,NULL};
int BTN3_connection[] = {128,122,NULL,NULL};
int BTN4_connection[] = {128,129,97,NULL};

//action mode <- predefined action keys
/*
 * Table of action key:
 * 1-This pc
 * 2-web browser
 * 3-calculator
 * 4-music
 * 5-playback
 * 6-skip 
 * 7-play
 * 8-stop
 * 9-music off
 * 10-volume down
 * 11-volume up
 */
int BTN1_action = 10;
int BTN2_action = 11;
int BTN3_action = 5;
int BTN4_action = 7;

//Declaration of objects for 4 buttons
  Button BTN1(P1, inverted, "1");
  Button BTN2(P2, inverted, "2");
  Button BTN3(P3, inverted, "3");
  Button BTN4(P4, inverted, "4");

//Declaration of WS-leds
Led LED1;
Led LED2;
Led LED3;
Led LED4;


bool led_mode = false;//false<- hue animation true <- change color for each LED
int hue_time = 1000;//time to chage the hue value
  
void setup(){
 FastLED.addLeds<NEOPIXEL, DATA>(leds,NUM_LEDS); 
 Keyboard.begin();
 Serial.begin(115200);
 u8g2.begin();
 u8g2.clear();
 u8g2.setContrast(255);
 draw_start();
}


void loop(){
  u8g2.clearBuffer();
  draw_box();
  //  draw_box_1();
  //  draw_box_2();
  //  draw_box_3();
  //  draw_box_4();

  if(BTN1.getstate() == 1){
    draw_box_1();
      switch(mode){
        case 1:
        write_single(BTN1_key,wait);
        break;
        case 2:
        write_connection(BTN1_connection[0],BTN1_connection[1],BTN1_connection[2],BTN1_connection[3],wait);
        break;
        case 3:
        write_action(BTN1_action,wait);
        break;      
      }    
    if(post == true){
      message_verbose(lvl,"BTN1");
    }else{}
    delay(button_delay);
  }else{
    u8g2.setFont(u8g2_font_roentgen_nbp_tf);
    u8g2.setCursor(10,12);    
    u8g2.print("1");
  }
  
  if(BTN2.getstate() == 1){
    draw_box_2();
      switch(mode){
        case 1:
        write_single(BTN2_key,wait);
        break;
        case 2:
        write_connection(BTN2_connection[0],BTN2_connection[1],BTN2_connection[2],BTN2_connection[3],wait);
        break;
        case 3:
        write_action(BTN2_action,wait);
        break;
        
      }  
    if(post == true){
      message_verbose(lvl,"BTN2");
    }else{}
    delay(button_delay);
  }else{
    u8g2.setFont(u8g2_font_roentgen_nbp_tf);
    u8g2.setCursor(35,12);    
    u8g2.print("2");
  }
  if(BTN3.getstate() == 1){
    draw_box_3();
      switch(mode){
        case 1:
        write_single(BTN3_key,wait);
        break;
        case 2:
        write_connection(BTN3_connection[0],BTN3_connection[1],BTN3_connection[2],BTN3_connection[3],wait);
        break;
        case 3:
        write_action(BTN3_action,wait);
        break;
        
      }  
    if(post == true){
      message_verbose(lvl,"BTN3");
    }else{}
    delay(button_delay);
  }else{    
    u8g2.setFont(u8g2_font_roentgen_nbp_tf);
    u8g2.setCursor(10,27);    
    u8g2.print("3");
  }
  if(BTN4.getstate() == 1){
    draw_box_4();
      switch(mode){
        case 1:
        write_single(BTN4_key,wait);
        break;
        case 2:
        write_connection(BTN4_connection[0],BTN4_connection[1],BTN4_connection[2],BTN4_connection[3],wait);
        break;
        case 3:
        write_action(BTN4_action,wait);
        break;
      }  
    if(post == true){
      message_verbose(lvl,"BTN4");
    }else{}
    delay(button_delay);
  }else{
    u8g2.setFont(u8g2_font_roentgen_nbp_tf);
    u8g2.setCursor(35,27);    
    u8g2.print("4");
  }
   u8g2.sendBuffer();
  switch(led_mode){
    case true:
      //change color of each WS2812B rgb diodes
      LED1.rgb_led(0,255,255,255);
      LED2.rgb_led(1,255,255,255);
      LED3.rgb_led(2,255,255,255);
      LED4.rgb_led(3,255,255,255);
    break;
    case false:
      unsigned long start = millis();
      static uint8_t hue = 0;
        if(start=hue_time){
          FastLED.showColor(CHSV(hue++,255,255)); //(odcień,biel,ilość czarnego)
        }
      start = 0;
    break;
  }


    
}
