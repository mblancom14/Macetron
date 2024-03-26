/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include <math.h>

#include "..\include\config\mainConfig.h"
#include "..\include\peripherals\DHT22s.h"

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
/* Read data from the DHT sensor */
float DHT22S::getHumidity (void) {
    float humidity = readHumidity();

    /* Read value is checked to see if it is valid */
    if (isnan(humidity)) {
        /* Sensor reset */
        _resetSensor ();

        humidity = readHumidity();

        if (isnan(humidity)) {
            /* Sensor reset */
            _resetSensor ();

            humidity = HUMIDITY_ERROR;
        }

        if (humidity == 100.0) {
            humidity = 99.9;
        }
    }

    return humidity;
}

/* Read data from the DHT sensor */
float DHT22S::getTemperature (void) {
    float temperature = readTemperature();

    /* Read value is checked to see if it is valid */
    if (isnan(temperature)) {
        /* Sensor reset */
        _resetSensor ();

        temperature = readTemperature();

        if (isnan(temperature)) {
            /* Sensor reset */
            _resetSensor ();

            temperature = TEMPERATURE_ERROR;
        }
    }

    return temperature;
}

/* Reset the DHT22 sensor */
void DHT22S::_resetSensor (void) {
    digitalWrite(_resetPin, HIGH);
    delay(DHT22_TIME_FOR_RESET);
    digitalWrite(_resetPin, LOW);
}