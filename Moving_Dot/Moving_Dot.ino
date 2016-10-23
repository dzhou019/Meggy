/*
  MeggyJr_Blink.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */
// Moving_Dot by Darren Zhou
#include <MeggyJrSimple.h>    // Required code, line 1 of 2.
int x=0;
int y=0;
int xapple=random(8);
int yapple=random(8);
boolean gotApple_false;
void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  // put your main code here, to rune repeatedly
  DrawPx(x,y,Yellow);           // Draw a dot at x=3, y=4, in yellow
  DrawPx(xapple,yapple,Red);
  DrawPx(1,0,Blue);
  DrawPx(2,0,Blue);
  DrawPx(4,0,Blue);
  DrawPx(6,0,Blue);
  DrawPx(7,0,Blue);
  DrawPx(1,3,Blue);
  DrawPx(1,4,Blue);
  DrawPx(1,6,Blue);
  DrawPx(2,5,Blue);
  DrawPx(2,3,Blue);
  DrawPx(2,2,Blue);
  DrawPx(2,1,Blue);
  DrawPx(3,3,Blue);
  DrawPx(5,4,Blue);
  DrawPx(7,2,Blue);
  ClearSlate();
  DisplaySlate();               // Write the drawing to the screen
  ClearSlate();
  // Check to see if a button was pressed
 CheckButtonsPress();
  // If the right arrow was pressed, add one to x.
  if (Button_Right && ReadPx(x+1,y)==0)
  { 
        x=x+1;
  }
  // If the left arrow was pressed, take one away from x.
  
    if(Button_Left)
  {
    x=x-1;
  }
 
  // If up arrow was pressed, add one to y
  if(Button_Up) 
  {
    y=y+1;
  }
  // If down arrow was pressed, take one away from y
  if(Button_Down)
  {
    y=y-1;
  }
  if (ReadPx(x,y)==1)
  {
    Tone_Start(18182,50);
    xapple=random(8);
    yapple=random(8);
  }
  if (y>7)
    y=7;
  if (y <0)
    y=0;
  if (x<0)
    x=0;
  if (x>7)
   x=7;
}


