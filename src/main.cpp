/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include <Arduino.h>

#include "..\include\config\mainConfig.h"
#include "..\include\dataProcessing\stateMachine.h"

/***************************************************************************************************
*                                     DEFINITIONS AND MACROS                                       *
***************************************************************************************************/

/***************************************************************************************************
*                                             GLOBAL                                               *
***************************************************************************************************/
StateMachine sm;

/***************************************************************************************************
*                                          FUNCTIONS                                               *
***************************************************************************************************/
#define BUTTON_PIN 7
int prev_button_state = LOW;  // The previous state from the input pin
int button_state;
const int ledPin = 13;    // the number of the LED pin

void setup(void) {
    DEBUG_SERIAL_BEGIN(9600);
    sm.begin();
}

void loop() {
    sm.processStateMachine();

    delay (200);
}