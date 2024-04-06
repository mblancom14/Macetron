/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include "..\include\config\mainConfig.h"
#include "..\include\peripherals\physicalInput.h"
#include "..\include\dataProcessing\stateMachine.h"

/***************************************************************************************************
*                                     DEFINITIONS AND MACROS                                       *
***************************************************************************************************/

/***************************************************************************************************
*                                    TYPEDEFS AND STRUCTURES                                       *
***************************************************************************************************/

/***************************************************************************************************
*                                             GLOBAL                                               *
***************************************************************************************************/
extern StateMachine sm;
OneButton *button;

/***************************************************************************************************
*                                          FUNCTIONS                                               *
***************************************************************************************************/
void buttonLongClick () {
    sm.updateInput(BUTTON_LONG_CLICK);
}

void buttonClick () {
    /* Not implemented */
}

void buttonDoubleClick () {
    /* Not implemented */
}

/* Constructor */
PhysicalInput::PhysicalInput (int buttonPin) {
    button = new OneButton(buttonPin, true, true);
    button->attachLongPressStart(buttonLongClick);
    button->attachClick(buttonClick);
    button->attachDoubleClick(buttonDoubleClick);
}

/* Read the physical inputs */
void PhysicalInput::read (void) {
    button->tick();
}