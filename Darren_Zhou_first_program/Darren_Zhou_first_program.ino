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

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  
  DrawPx(0,1,Green);           // Draw a dot at x=3, y=4, in yellow.
  DrawPx(0,2,Green);
  DrawPx(0,3,Green);
  DrawPx(0,4,Green);
  DrawPx(0,5,Green);
  DrawPx(0,6,Green);
  DrawPx(1,6,Blue);
  DrawPx(2,6,Blue);
  DrawPx(3,5,Red);
  DrawPx(3,4,Red);
  DrawPx(3,3,Red);
  DrawPx(3,2,Red);
  DrawPx(2,1,Yellow);
  DrawPx(1,1,Yellow);
  DrawPx(4,6,Orange);
  DrawPx(5,6,Orange);
  DrawPx(6,6,Orange);
  DrawPx(7,6,Orange);
  DrawPx(6,5,Green);
  DrawPx(5,4,Green);
  DrawPx(4,3,Green);
  DrawPx(5,3,Red);
  DrawPx(6,3,Red);
  DrawPx(7,3,Red);
  

  
}


