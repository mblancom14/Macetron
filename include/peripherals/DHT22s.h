#ifndef DHT22S_H
#define DHT22S_H

/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include "DHT.h"
#include "..\include\config\mainConfig.h"

/***************************************************************************************************
*                                     DEFINITIONS AND MACROS                                       *
***************************************************************************************************/
/* Time between connection and desconnection of the sensor to restart it (ms) */
#define DHT22_TIME_FOR_RESET            50

/***************************************************************************************************
*                                    TYPEDEFS AND STRUCTURES                                       *
***************************************************************************************************/

/***************************************************************************************************
*                                       GLOBAL PARAMETERS                                          *
***************************************************************************************************/

/***************************************************************************************************
*                                       CLASS DECLARATIONS                                         *
***************************************************************************************************/
//TODO herencia del DHT y reset del sensor si no lee bien
/*!
 *  \class      SMS
 *
 *  \brief      Class that stores state and functions of the Soil Moisture Sensor
 */
class DHT22S : public DHT {
public:
/* TODO Se puede hacer el constructor en otro fichero */
    DHT22S (uint8_t resetPin) : DHT (resetPin, DHT22) {
        _resetPin = resetPin;
        pinMode (PIN_GND_DHT22, OUTPUT);
        digitalWrite (PIN_GND_DHT22, LOW);
        begin ();
    }

    float getHumidity (void);
    float getTemperature (void);

private:
    void _resetSensor (void);

    uint8_t _resetPin;
    uint16_t _humidity, _temperature;
};

#endif /* DHT22S_H */