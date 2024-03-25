/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
// #include <SPI.h>
// #include <math.h>
// #include <stdint.h>
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
// DHT22S sensorDHT (PIN_DATA_DHT22);
// SMS sensorSMS (PIN_DATA_SMS, SMS_DRY_CALIBRATION_VALUE, SMS_WET_CALIBRATION_VALUE);
// SDcard sd;
// WPump WPump_1 (PIN_WATER_PUMP, 10);
// NTP ntp;


void setup(void) {
    sm.begin();
    //TODO Se obtiene la instancia única de sensorData
    // sensorData& data = sensorData::getInstance ();

    //TODO cambiar las entradas
    // pinMode (PIN_WATER_PUMP, OUTPUT);
    // digitalWrite (PIN_WATER_PUMP, HIGH);

    // Serial.begin (9600);
    // Serial.println ();
    // wifiInitialization ();

    // testOpenWeatherMap ();

    // sd.begin ();

    // ntp.begin ();

    pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
    sm.processStateMachine();

    delay (1000);
    //NOTE se leen los valores de humedad, temperatura y humedad del sustrato
    // sensorDHT.readDataDHT ();
    // sensorSMS.readDataSMS ();

    // //NOTE se imprimen en pantalla los valores de SOIL MOISTURE, temperatura y humedad
    // oled.displayLayout_Sth ();

    // // ntp.readTime ();
    // // sd.writeData ();

    // //TODO no funsiona
    // ntp.printHour ();

// while (1){
//     Serial.print ("contadoraso: ");
//     Serial.print (contadoraso);
//     Serial.print ("\n");

//     if (contadoraso >= 4)
//     {
//         Serial.print ("ActivatePump\n");
//         WPump_1.activatePump ();

//         Serial.print ("pumpStatus: ");
//         Serial.print (WPump_1.pumpStatus ());
//         Serial.print ("\n");

//         if (WPump_1.pumpStatus () == false)
//         {
//             Serial.print ("DesactivaPump\n");
//             contadoraso = 0;
//         }
//         else
//         {
//             Serial.print ("Bomba activa\n");
//         }
//     }
//     else
//     {
//         contadoraso++;
//     }

// }
    // delay (1000);
    // Serial.println ("PIN_WATER_PUMP LOW ");
    // digitalWrite (PIN_WATER_PUMP, LOW);
    // delay (1000);
    // Serial.println ("PIN_WATER_PUMP HIGH ");
    // digitalWrite (PIN_WATER_PUMP, HIGH);
}