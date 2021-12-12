#include <M5Core2.h>
#include <Fonts/EVA_20px.h>
#include <stdio.h>
#include <stdlib.h>
uint32_t m = 0;
  void togglecontrol()
  {
    m++;
    if(m>2) m=0;
  }
void rubber(unsigned int startx,unsigned int starty,int sizx,int sizy,uint32_t color)
  {
    M5.Lcd.fillRect( startx, startx, sizx, sizy, color);
  }
 
  void reset()
  {
  rubber(0,0,320,240,BLACK);
  }
void vbutton()
  {
  M5.Lcd.setTextColor(GREEN,BLACK);
  m5.Lcd.setCursor(100,120);
  M5.Lcd.setTextSize(2);
  M5.Lcd.drawRect(80,90,110,80,RED);
  M5.Lcd.print("Runing"); 
  }
  
  void wemenu()
  {
    M5.Lcd.clear();
    M5.Lcd.setTextColor(GREEN,BLACK);
    m5.Lcd.setCursor(80,110);
    m5.Lcd.setTextSize(2);
    m5.Lcd.print("Welcome To Menu!");
    delay(400);
  }
  
void menu()
  {
    int i=1,j=1;
    wemenu();
    M5.Lcd.clear();
    M5.Lcd.fillScreen(WHITE);
    for(i=1;i<= 120;i++)
    { 
      M5.Lcd.fillRect(20,20, i, j, BLACK);
      if(i%2==0)
      {
        j++;
      }
      delay(3);
      if(i==120)
      {
        m5.Lcd.setCursor(42,42);
        m5.Lcd.setTextSize(1);
        m5.Lcd.print("Car function!");
        
      }
    }
  }
  

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(WHITE); //Set the screen background color to white.  设置屏幕背景色为白色
  M5.Lcd.setTextColor(GREEN,BLACK);
  m5.Lcd.setCursor(80,120);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print("distant rescue"); 
}
void loop() {
      m5.update();
      if (M5.BtnA.isPressed())
    {
      delay(300);
      m5.update();
      if(!M5.BtnA.isPressed())
      {menu();
      togglecontrol();}
      if(m!=1)m=1;
    }
    
    if(m==1)
    {
      TouchPoint_t pos= M5.Touch.getPressPoint(); 
    if (pos.x>20&&pos.x<120&&pos.y>20&&pos.y<60)
    {
      togglecontrol();
    }

    }
    
    if(m==2)
    {
    reset();
    vbutton();
    togglecontrol();
    }
    
}
