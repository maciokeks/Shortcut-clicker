int ADC_bits = 1024; //for connecting button to 5V
int ADC_voltage = 5;
/*
 * Table of action key:
 * 1-This PC
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
void write_action(int action_mode,byte wait){
  switch(action_mode){
    case 1:
    Keyboard.press(135);//right_gui
    delay(10);
    Keyboard.press(194);
    delay(wait);
    Keyboard.releaseAll();
    break;
    case 2:
    Keyboard.press(135);
    delay(10);
    Keyboard.press(195);
    delay(wait);
    Keyboard.releaseAll();
    break;
    case 3:
    Keyboard.press(135);
    delay(10);
    Keyboard.press(196);
    delay(wait);
    Keyboard.releaseAll();
    break;
    case 4:
    Keyboard.press(135);
    delay(10);
    Keyboard.press(197);
    delay(wait);
    Keyboard.releaseAll();
    break;
    case 5:
    Keyboard.press(135);
    delay(10);
    Keyboard.press(198);
    delay(wait);
    Keyboard.releaseAll();
    break;
    case 6:
    Keyboard.press(135);
    delay(10);
    Keyboard.press(199);
    delay(wait);
    Keyboard.releaseAll();
    break;
    case 7:
    Keyboard.press(135);
    delay(10);
    Keyboard.press(200);
    delay(wait);
    Keyboard.releaseAll();
    break;
    case 8:
    Keyboard.press(135);
    delay(10);
    Keyboard.press(201);
    delay(wait);
    Keyboard.releaseAll();
    break;
    case 9:
    Keyboard.press(135);
    delay(10);
    Keyboard.press(202);
    delay(wait);
    Keyboard.releaseAll();
    break;
    case 10:
    Keyboard.press(135);
    delay(10);
    Keyboard.press(203);
    delay(wait);
    Keyboard.releaseAll();
    break;
    case 11:
    Keyboard.press(135);
    delay(10);
    Keyboard.press(204);
    delay(wait);
    Keyboard.releaseAll();
    break;
  } 
}
void write_connection(int code1,int code2, int code3,int code4, byte wait){
    Keyboard.press(code1);
    delay(10);
    Keyboard.press(code2);
    delay(10);
    Keyboard.press(code3);
    delay(10);
    Keyboard.press(code4);
    delay(wait);
    Keyboard.releaseAll();
  if(post == true){
    Serial.println("Connection of keys pressed:");
    Serial.println(code1);
    Serial.println(char(code1));
    Serial.println(code2);
    Serial.println(char(code2));
    Serial.println(code3);
    Serial.println(char(code3));
    Serial.println(code4);
    Serial.println(char(code4));
  }
}
void write_single(int code, byte wait){
  Keyboard.write(code);
  delay(wait);
  Keyboard.releaseAll();
  if(post == true){
    Serial.println("Single key pressed:");
    Serial.println(code);
    Serial.println(char(code));
  }
}
void draw_box(){
  u8g2.drawFrame(1,1,50,31);
  u8g2.drawHLine(1,16,50); 
  u8g2.drawLine(25,1,25,31); 
}

void draw_box_1(){
   u8g2.drawBox(2,2,24,15);
   u8g2.setFontMode(1);
   u8g2.setDrawColor(2);
   u8g2.setFont(u8g2_font_roentgen_nbp_tf);    
   u8g2.drawStr(10,12,"1");
}
void draw_box_2(){
   u8g2.drawBox(26,2,24,15);
   u8g2.setFontMode(1);
   u8g2.setDrawColor(2);
   u8g2.setFont(u8g2_font_roentgen_nbp_tf);    
   u8g2.drawStr(35,12,"2");
}
void draw_box_3(){
   u8g2.drawBox(2,17,24,15);
   u8g2.setFontMode(1);
   u8g2.setDrawColor(2);
   u8g2.setFont(u8g2_font_roentgen_nbp_tf);    
   u8g2.drawStr(10,27,"3");
}
void draw_box_4(){
   u8g2.drawBox(26,17,24,15);
   u8g2.setFontMode(1);
   u8g2.setDrawColor(2);
   u8g2.setFont(u8g2_font_roentgen_nbp_tf);    
   u8g2.drawStr(35,27,"4");
}

void draw_start(){
  //start screen
  u8g2.drawFrame(0,0,128,32);
  u8g2.drawFrame(22,24,88,5);
  u8g2.setFont(u8g2_font_VCR_OSD_mu);    
  u8g2.drawStr(24,18,"WELCOME");
  //u8g2.setFont(u8g2_font_unifont_t_symbols);
  //u8g2.drawGlyph(4,20, 0x23F3);
  u8g2.sendBuffer(); 
  for(int counter = 0;counter<=88;counter++){
    u8g2.drawBox(22,24,counter,5);
    u8g2.sendBuffer();
    delay(5);
  }
  delay(800); 
}
void message_verbose(int lvl,String button){
  switch(lvl){
    //FOR SECOND OPTION look pins.h
    case 1: 
      if(button == "BTN1"){
        Serial.println("*lvl=1* BTN1 pressed");
      }
      if(button == "BTN2"){
        Serial.println("*lvl=1* BTN2 pressed");      
      }
      if(button == "BTN3"){
        Serial.println("*lvl=1* BTN3 pressed");
      }
      if(button == "BTN4"){
        Serial.println("*lvl=1* BTN4 pressed");
      }
    break;
    //FOR FIRST OPTION look pins.h
    case 2: 
      if(button == "BTN1"){
        Serial.println("*lvl=2* BTN1 pressed");
        int ADC_value = analogRead(P1);
        Serial.println(ADC);
        int V = (ADC_value*ADC_voltage)/(ADC_bits);
        Serial.println(V);
        Serial.println("\t");        
      }
      if(button == "BTN2"){
        Serial.println("*lvl=2* BTN2 pressed");
        int ADC_value = analogRead(P2);
        Serial.println(ADC);
        int V = (ADC_value*ADC_voltage)/(ADC_bits);
        Serial.println(V);
        Serial.println("\t");   
      }
      if(button == "BTN3"){
        Serial.println("*lvl=2* BTN3 pressed");
        int ADC_value = analogRead(P3);
        Serial.println(ADC);
        int V = (ADC_value*ADC_voltage)/(ADC_bits);
        Serial.println(V);
        Serial.println("\t");
      }
      if(button == "BTN4"){
        Serial.println("*lvl=2* BTN4 pressed");
        int ADC_value = analogRead(P4);
        Serial.println(ADC);
        int V = (ADC_value*ADC_voltage)/(ADC_bits);
        Serial.println(V);
        Serial.println("\t");
      }
    break;
  }
}
