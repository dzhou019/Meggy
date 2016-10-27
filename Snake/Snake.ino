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

#include <MeggyJrSimple.h>
int x=0;                    // Required code, line 1 of 2.
int y=0;
int xapple=random(8);
int yapple=random(8);  
boolean gotapple = true;
int binary= 0;
int speed =750;
     
                                
struct Point
{
  int x;
  int y;
};

Point p1 = {2,4};
Point p2 = {3,4};
Point p3 = {4,4};
Point p4 = {5,4};
Point snakeArray[64] = {p1,p2,p3,p4};
int marker = 4;                // Index of the first empty segement of array
int direction = 0;

void drawSnake();

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}



void loop()                     // run over and over again
{
  updateSnake();
  DrawPx(xapple,yapple,Red);
  //Have eaten apple
  if (ReadPx(snakeArray[0].x,snakeArray[0].y)==Red)
  {
    xapple = random(8);         // Roll new values for apple
    yapple = random(8);  
    Tone_Start(18182,50);
    if (binary < 128)
    {
      binary = binary * 2 + 1;
    }
    else   
    {
      binary = 0; 
      marker = marker + 1;
      speed = speed - 25;
      
        
    }
  }
  
  drawSnake();
  SetAuxLEDs(binary);
  DisplaySlate();                  // Write the drawing to the screen.
  delay(speed);                     // waits for a second 
  CheckButtonsDown();                              
  ClearSlate();                 // Erase drawing
  
  if (Button_Right)
  {
    direction=90;
  }
  if (Button_Up)
  {
     direction=0;
  }
  if (Button_Down)
  {
     direction=180;
  }
  if (Button_Left)
  {
     direction=270;
  }
}


// Checks the direction and updates the x or y value
void updateSnake()
{
                                      //Move body
  
  for (int i = marker - 1; i > 0; i--)
  {
    // Copy values at i-1 into i
     snakeArray[i]= snakeArray[i-1];
  }
  // Move head
  if (direction == 0)
  {
    // Updates y
    snakeArray[0].y = snakeArray[0].y+1;
    // Corrects for out of bounds
    if (snakeArray[0].y >7)
     {
      snakeArray[0].y=0;
     }
    }
 if (direction ==90)
  {
    // Updates x
    snakeArray[0].x = snakeArray[0].x+1;
    // Corrects for out of bounds
    if (snakeArray[0].x >7)
    {
      snakeArray[0].x=0;
    }
  }
 if (direction ==180)
  {
    // Updates y
     snakeArray[0].y = snakeArray[0].y-1;
    // Corrects for out of bounds
    if (snakeArray[0].y <0)
    {
     snakeArray[0].y=7;
    }
  }
  
 if (direction ==270)
  {
    // Updates x
     snakeArray[0].x=snakeArray[0].x-1;
     // Corrects for out of bounds
     if (snakeArray[0].x<0)
     {
      snakeArray[0].x=7;
     }
   }
}


void drawSnake()
{
  // Iterate through entire array and draw each segement
    for (int i = 0; i < marker; i++)
    {  
      DrawPx(snakeArray[i].x, snakeArray[i].y, Blue); // Draw the snake.                                       
    }
}


