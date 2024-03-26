/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "..\include\peripherals\SMS.h"
#include "..\include\peripherals\OLED.h"
#include "..\include\config\mainConfig.h"
#include "..\include\peripherals\DHT22s.h"
#include "..\include\dataProcessing\stateMachine.h"

/***************************************************************************************************
*                                     DEFINITIONS AND MACROS                                       *
***************************************************************************************************/

/***************************************************************************************************
*                                             GLOBAL                                               *
***************************************************************************************************/
DHT22S sensorDHT (PIN_DATA_DHT22);
OLED oled(OLED_WIDTH, OLED_HEIGHT);
SMS sms (PIN_DATA_SMS, SMS_DRY_CALIBRATION_VALUE, SMS_WET_CALIBRATION_VALUE);

/***************************************************************************************************
*                                          FUNCTIONS                                               *
***************************************************************************************************/
/* Start configuration */
void StateMachine::begin (void) {
    _state = IDLE_STATE;
}

/* Update private state with the new state and the last private state with the previous state */
void StateMachine::_updateState (uint8_t newState)
{
    _lastState = _state;
    _state = newState;
}

/* State Machine implementation */
void StateMachine::processStateMachine (void) {

    switch (_state)
    {
        case IDLE_STATE:
            oled.startConfig ();
            oled.displayInit();
            delay(DELAY_INIT_SCREEN);

#ifdef NORMAL_MODE
            _updateState(FACE_STATE);    /* Change state to FACE_STATE */
#elif DEBUG_MODE
            _updateState(DEBUG_STATE);
#else /* CALIBRATION_MODE */
            _updateState(CALIBRATION_STATE);

#endif
        break;
        case FACE_STATE:

        break;
        case DEBUG_STATE:
            oled.displayMoistureTemperatureHumidity(sms.getMoisture(), 
                                                    sensorDHT.getTemperature(), 
                                                    sensorDHT.getHumidity());
        break;
        case CALIBRATION_STATE:
            oled.displayMoistureCalibration(sms.getMoisture(), sms.getAnalogRead());
        break;
        default:
            _updateState(IDLE_STATE);
        break;
    }
}