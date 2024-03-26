#ifndef OLED_H
#define OLED_H

/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "..\include\config\mainConfig.h"
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
*                                       CLASS DECLARATIONS                                         *
***************************************************************************************************/
class OLED : public Adafruit_SSD1306 {
public:
    OLED (uint8_t width, uint8_t height) : Adafruit_SSD1306 (width, height, &Wire, OLED_RESET) {}

    void startConfig (void);
    void displayInitScreen(void);
    void displayMoistureTemperatureHumidity (uint16_t moisture, float temperature, float humidity);
    void displayMoistureCalibration (uint16_t moisture, int analogRead);
    void displayMoistureCalibrationInitScreen (void);
private:

};

#endif /* OLED_H */