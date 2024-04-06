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
#include "..\include\peripherals\physicalInput.h"

/***************************************************************************************************
*                                     DEFINITIONS AND MACROS                                       *
***************************************************************************************************/

/***************************************************************************************************
*                                             GLOBAL                                               *
***************************************************************************************************/
DHT22S sensorDHT (PIN_DATA_DHT22);
OLED oled(OLED_WIDTH, OLED_HEIGHT);
SMS sms (PIN_DATA_SMS, SMS_DRY_CALIBRATION_VALUE, SMS_WET_CALIBRATION_VALUE);
PhysicalInput pInput (7);

/***************************************************************************************************
*                                          FUNCTIONS                                               *
***************************************************************************************************/
/* Start configuration */
void StateMachine::begin (void) {
    _state = IDLE_STATE;
}

/* Restart the input */
void StateMachine::_restartInput (void) {
    _input = BUTTON_NO_PRESS;
}

/* Update private mode with the new input mode */
void StateMachine::updateInput (uint8_t input) {
    _input = input;
}

/* Update private state with the new state and the last private state with the previous state */
void StateMachine::_updateState (uint8_t newState) {
    _lastState = _state;
    _state = newState;
}

/* State Machine implementation */
void StateMachine::processStateMachine (void) {
    pInput.read();
    
    switch (_state)
    {
        case IDLE_STATE:
            DEBUG_SERIAL_PRINTLN("[State machine] IDLE_STATE");

            oled.startConfig ();

            oled.displayInitScreen();
            delay(DELAY_INIT_SCREEN);
            
            /* Change state */
            _updateState(FRONT_SCREEN_STATE);
        break;
        case FRONT_SAD_SCREEN_STATE:
            if (_state != _lastState) {
                DEBUG_SERIAL_PRINTLN("[State machine] FRONT_SAD_SCREEN_STATE");
                _restartInput();

                oled.displaySadPlantScreen();
                delay(DELAY_INIT_SCREEN);

                /* Change state */
                _updateState(FRONT_SAD_SCREEN_STATE);
            }
            else {    /* Same state */
                switch (_input)
                {
                    case BUTTON_NO_PRESS:
                        if (round(sms.getMoisture() / 10.0) * 10 > 60) {
                            /* Change state */
                            _updateState(FRONT_HAPPY_SCREEN_STATE);
                        }
                    break;
                    case BUTTON_LONG_CLICK:
                        _restartInput();

                        /* Change mode */
                        _updateState(VALUES_SCREEN_STATE);
                    break;
                    default:
                        _restartInput();
                    break;
                }
            }
        break;
        case FRONT_HAPPY_SCREEN_STATE:
            DEBUG_SERIAL_PRINTLN("[State machine] FRONT_HAPPY_SCREEN_STATE");

                oled.displayHappyPlantScreen();
                delay(DELAY_HAPPY_PLANT_SCREEN);

            /* Change state */
            _updateState(FRONT_SCREEN_STATE);
        break;
        case FRONT_SCREEN_STATE:
            if (_state != _lastState) {
                DEBUG_SERIAL_PRINTLN("[State machine] FRONT_SCREEN_STATE");
                _restartInput();

                /* Change state */
                _updateState(FRONT_SCREEN_STATE);
            }
            else {    /* Same state */
                switch (_input)
                {
                    case BUTTON_NO_PRESS:
                        if (round(sms.getMoisture() / 10.0) * 10 < 30) {
                            /* Change state */
                            _updateState(FRONT_SAD_SCREEN_STATE);
                        }
                        else {
                            oled.displayFrontScreen(sms.getMoisture(), sensorDHT.getTemperature(),
                                                    sensorDHT.getHumidity());
                        }

                    break;
                    case BUTTON_LONG_CLICK:
                        _restartInput();

                        /* Change mode */
                        _updateState(VALUES_SCREEN_STATE);
                    break;
                    default:
                        _restartInput();
                    break;
                }
            }
        break;
        case VALUES_SCREEN_STATE:
            if (_state != _lastState) {
                DEBUG_SERIAL_PRINTLN("[State machine] VALUES_SCREEN_STATE");
                _restartInput();
                
                oled.displayValuesInitScreen();
                delay(DELAY_INIT_SCREEN);

                /* Change state */
                _updateState(VALUES_SCREEN_STATE);
            }
            else {    /* Same state */
                switch (_input)
                {
                    case BUTTON_NO_PRESS:
                        oled.displayMoistureTemperatureHumidity(sms.getMoisture(),
                                                                sensorDHT.getTemperature(),
                                                                sensorDHT.getHumidity());
                    break;
                    case BUTTON_LONG_CLICK:
                        _restartInput();

                        /* Change mode */
                        _updateState(CALIBRATION_SCREEN_STATE);
                    break;
                    default:
                        _restartInput();
                    break;
                }
            }
        break;
        case CALIBRATION_SCREEN_STATE:
            if (_state != _lastState) {
                DEBUG_SERIAL_PRINTLN("[State machine] CALIBRATION_SCREEN_STATE");
                _restartInput();

                oled.displayMoistureCalibrationInitScreen();
                delay(DELAY_INIT_SCREEN);

                /* Change state */
                _updateState(CALIBRATION_SCREEN_STATE);
            }
            else {    /* Same state */
                switch (_input)
                {
                    case BUTTON_NO_PRESS:
                        oled.displayMoistureCalibration(sms.getMoisture(), sms.getAnalogRead());
                    break;
                    case BUTTON_CLICK:
                        _restartInput();
                    break;
                    case BUTTON_LONG_CLICK:
                        _restartInput();
                        
                        /* Change mode */
                        _updateState(FRONT_SCREEN_STATE);
                    break;
                    default:
                        _restartInput();
                    break;
                }
            }
        break;
        default:
            _updateState(IDLE_STATE);
        break;
    }
}