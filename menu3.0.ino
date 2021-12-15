#include <M5Core2.h>
#include <Fonts/EVA_20px.h>
#include <stdio.h>
#include <stdlib.h>
#include "CUF_24px.h"
uint32_t m = 0;
uint32_t r = 0;
uint32_t s = 0;
uint32_t t = 0;
  void togglecontrol1()// controll center
  {
    m++;
    if(m>2) m=0;
  }

    void togglecontrol2()
  {
    r++;
    if(r>2) r=0;
  }

    void togglecontrol3()
  {
    s++;
    if(s>2) s=0;
  }

    void togglecontrol4()
  {
    t++;
    if(t>2) t=0;
  }
void initback()        // initialize background
{
  for(int i=0;i<=320;i++)
  {   
      int rx = random(320);
      int ry = random(60);
      for(int j=0;j<=240;j++)
      {
        if(j<20&&j%3==0)
        { 
          M5.Lcd.drawPixel(i,j,BLUE); 
          }
          else if(j<40)
          {
            M5.Lcd.drawPixel(rx,ry,BLUE);
          }
        else if(j>200)
        { M5.Lcd.drawPixel(i,j,GREEN);} 
      }
     m5.Lcd.setCursor(30,120);
     M5.Lcd.setTextSize(2);
     M5.Lcd.print("Remote  ⛨       ✙ rescue"); 
     m5.Lcd.setCursor(80,205);
     M5.Lcd.setTextSize(1);
     M5.Lcd.print("  ⛰       ⛳ "); 
   
  }
}

  void wemenu()     //welcome menu
  {
    M5.Lcd.clear();
    M5.Lcd.setTextColor(GREEN,BLACK);
    m5.Lcd.setCursor(50,110);
    m5.Lcd.setTextSize(1);
    m5.Lcd.print("Welcome To Menu!");
    delay(800);
  }
  
void menu()        //menu
  {
    int i=1,j=1,k=1,o=1,p=1;
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
        m5.Lcd.setCursor(42,62);
        m5.Lcd.setTextSize(1);
        m5.Lcd.print(" Car");   
      }  
    }

       for(i=1;i<= 120;i++)
    { 
      M5.Lcd.fillRect(180,20, i, k, BLACK);
      if(i%2==0)
      {
        k++;
      }
      delay(3);
      if(i==120)
      {
        m5.Lcd.setCursor(202,62);
        m5.Lcd.setTextSize(1);
        m5.Lcd.print(" siren");//a burglar alarm
      }  
      }

   for(i=1;i<= 120;i++)
    { 
      M5.Lcd.fillRect(20,160, i, p, BLACK);
      if(i%2==0)
      {
        p++;
      }
      delay(3);
      if(i==120)
      {
        m5.Lcd.setCursor(42,202);
        m5.Lcd.setTextSize(1);
        m5.Lcd.print("spolight");
      }  
    }   
    
    for(i=1;i<= 120;i++)
    { 
      M5.Lcd.fillRect(180,160, i, o, BLACK);
      if(i%2==0)
      {
        o++;
      }
      delay(3);
      if(i==120)
      {
        m5.Lcd.setCursor(202,202);
        m5.Lcd.setTextSize(1);
        m5.Lcd.print("carema");
      }  
      }

       M5.Lcd.fillEllipse(160, 120 , 50 , 75, random(0xFFFF));
       m5.Lcd.setCursor(142,140);
       M5.Lcd.setTextSize(2);
       M5.Lcd.print("⛨"); 
      
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
  M5.Lcd.setTextSize(1);
  M5.Lcd.drawRect(80,50,110,80,RED);
  M5.Lcd.print("Runing"); 
  }

 void part1()
  {
    if(m==1)
    {
     TouchPoint_t pos= M5.Touch.getPressPoint(); 
    if (pos.x>20&&pos.x<120&&pos.y>20&&pos.y<80)
    {
      togglecontrol1();
    }
     }
    if(m==2)
    {
    reset();
    vbutton();
    togglecontrol1();
    }
  }
  void part2()
  {
    if(r==1)
    {
      TouchPoint_t pos= M5.Touch.getPressPoint(); 
    if (pos.x>180&&pos.x<360&&pos.y>20&&pos.y<80)
    {
      togglecontrol2();
    }
     } 
    if(r==2)
    {
    reset();
    vbutton();
    togglecontrol2();
    }
  }

   void part3()
  {
      if(s==1)
    {
      TouchPoint_t pos= M5.Touch.getPressPoint(); 
    if (pos.x>20&&pos.x<120&&pos.y>160&&pos.y<240)
    {
      togglecontrol3();
    }

    }
    
    if(s==2)
    {
    reset();
    vbutton();
    togglecontrol3();
    }
  }

    void part4()
  {
    if(t==1)
    {
      TouchPoint_t pos= M5.Touch.getPressPoint(); 
    if (pos.x>180&&pos.x<360&&pos.y>160&&pos.y<240)
    {
      togglecontrol4();
    }

    }
    if(t==2)
    {
    reset();
    vbutton();
    togglecontrol4();
    }
  }
  
  
void setup() {
  M5.begin();
  M5.Lcd.setFreeFont(&unicode_24px);//设置要使用的GFX字体（#include "CUF_24px.h"）
  M5.Lcd.setTextDatum(TC_DATUM);//设置文本对齐方式为居中向上对齐
  M5.Lcd.setTextColor(GREEN,WHITE); 
  M5.Lcd.fillScreen(WHITE);
  initback();

}

void loop() {
      m5.update();
      if (M5.BtnA.isPressed())
    {
      delay(300);
      m5.update();
      if(!M5.BtnA.isPressed())
      {menu();
      togglecontrol1();
      togglecontrol2();
      }
      if(m!=1)m=1;
      if(r!=1)r=1;
      if(s!=1)s=1;
      if(t!=1)t=1;
    }
    part1();
    part2();
    part3();
    part4();

    
}
