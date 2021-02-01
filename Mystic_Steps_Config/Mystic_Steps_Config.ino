// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//--------------------------------------------------------------------
#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  11, 0,                  // Button Count, Hat Switch Count
  false, false, false,     //no X and Y, no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  // Initialize Button Pins
  //2-9 = ExtIO
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  //arrows
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
  //Joystick.setXAxisRange(-1, 1);
  //Joystick.setYAxisRange(-1, 1);
}

// Last state of the buttons
int lastButtonState[17] = {0,0,0,0,0,
                           0,0,0,0,0,
                           0,0,0,0,0,
                           0,0};

void loop() {

  // Read pin values
  for (int index = 0; index < 17; index++)
  {
    int currentButtonState = !digitalRead(index + 2);
    if (currentButtonState != lastButtonState[index])
    {
      switch (index) {
//EXT-IO
        case 0: // pin2
          Joystick.setButton(0, currentButtonState);
          break;
        case 1: // 3
          Joystick.setButton(0, currentButtonState);
          break;        
        case 2: // 4
          Joystick.setButton(1, currentButtonState);
          break;        
        case 3: // 5
          Joystick.setButton(2, currentButtonState);
          break;       
        case 4: // 6
          Joystick.setButton(3, currentButtonState);
          break;
        case 5: // 7
          Joystick.setButton(4, currentButtonState);
          break;
        case 6: // 8
          Joystick.setButton(5, currentButtonState);
          break;
        case 7: // 9
          Joystick.setButton(6, currentButtonState);
          break;
//ARROWS
        case 8: // pin10
          Joystick.setButton(7, currentButtonState);
          break;      
        case 9: // 11 not used
          //Joystick.setButton(9, currentButtonState);
          break;     
        case 10: // 12 not used
          //Joystick.setButton(10, currentButtonState);
          break;
        case 11: // 13 not used
          //Joystick.setButton(11, currentButtonState);
          break;  
        case 12: // 14
          Joystick.setButton(8, currentButtonState);
          break;      
        case 13: // 15
          Joystick.setButton(9, currentButtonState);
          break;     
        case 14: // 16
          Joystick.setButton(10, currentButtonState);
          break;
        case 15: // 17 not used
          //Joystick.setButton(11, currentButtonState);
          break;          
      }
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(10);
}
