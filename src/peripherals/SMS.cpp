/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include "..\include\peripherals\SMS.h"

/***************************************************************************************************
*                                     DEFINITIONS AND MACROS                                       *
***************************************************************************************************/

/***************************************************************************************************
*                                    TYPEDEFS AND STRUCTURES                                       *
***************************************************************************************************/

/***************************************************************************************************
*                                       GLOBAL PARAMETERS                                          *
***************************************************************************************************/

/***************************************************************************************************
*                                          FUNCTIONS                                               *
***************************************************************************************************/
/* Setup sensor pins and sensor configuration */
void SMS::begin (void)
{
    /* Pin Configuration */
    pinMode (_pin, INPUT);
    _moisture = 0;
}

/* Get the value of the Soil Moisture Sensor */
uint16_t SMS::getMoisture (void)
{
    /* Analog value is obtained */
    int sensorVal = analogRead (_pin);
    sensorVal = (sensorVal > SMS_DRY_CALIBRATION_VALUE) ? SMS_DRY_CALIBRATION_VALUE : sensorVal;
    sensorVal = (sensorVal < SMS_WET_CALIBRATION_VALUE) ? SMS_WET_CALIBRATION_VALUE : sensorVal;

    /* Humidity value is calculated */
    uint16_t moisture = map (sensorVal, _dry, _wet, 0, 100);
    if (moisture >= 100)
    {
        moisture = 100;
    }
    else if (moisture <= 0)
    {
        moisture = 0;
    }

    if ((moisture == _moisture + SMS_HUMIDITY_TOLERANCE) ||
        (moisture == _moisture - SMS_HUMIDITY_TOLERANCE))
    {
        /* The value obtained is very similar to the previous one. This value is ignored */
        moisture = _moisture;
    }

    return moisture;
}

/* Get the analog value of the Soil Moisture Sensor */
int SMS::getAnalogRead (void)
{
    /* Analog value is obtained */
    int sensorVal = analogRead (_pin);

    return sensorVal;
}