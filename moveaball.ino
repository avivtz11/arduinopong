#include "LedControl.h"
LedControl lc=LedControl(7,6,5,1);

void setup() {
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,4);
  /* and clear the display */
  lc.clearDisplay(0);

}
/* gets start position*/
void move_a_ball(int x , int y)
{
  while (x<8 && y<8)
  {
    lc.setLed ( 0,x,y,true );
    delay(100);
    lc.setLed ( 0,x,y,false );
    x++;
    y++;
  }
  
  if (x==8 && y!=8)
  {
    downright(x,y);
  }
  
  if ( x==8 && y==8)
  {
    upright(x,y);
  }

  if (x!=8 && y==8)
  {
    upleft(x,y);
  }
}

void downright (int x, int y)
{
  x=x-2;
    while (x>0 && y<8)
  {
    lc.setLed ( 0,x,y,true );
    delay(100);
    lc.setLed ( 0,x,y,false );
    x--;
    y++;
  }
}

void downleft (int x, int y)
{
  while (x<8 && y<8)
  {
    lc.setLed ( 0,x,y,true );
    delay(100);
    lc.setLed ( 0,x,y,false );
    x++;
    y++;
  }
}

void upright(int x, int y)
{
  x=x-2;
    y=y-2;
  while (x>=0 && y>=0)
  {
    lc.setLed ( 0,x,y,true );
    delay(100);
    lc.setLed ( 0,x,y,false );
    x--;
    y--;
  }
}

void upleft(int x,int y)
{
  y=y-2;
    while (y>0 && x<8)
  {
    lc.setLed ( 0,x,y,true );
    delay(100);
    lc.setLed ( 0,x,y,false );
    y--;
    x++;
  }
}

void loop() {
  move_a_ball(2,0);

}
