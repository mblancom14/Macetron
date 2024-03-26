/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include "..\include\peripherals\OLED.h"

/***************************************************************************************************
*                                     DEFINITIONS AND MACROS                                       *
***************************************************************************************************/

/***************************************************************************************************
*                                       GLOBAL PARAMETERS                                          *
***************************************************************************************************/

/***************************************************************************************************
*                                          FUNCTIONS                                               *
***************************************************************************************************/
/* Start configuration */
void OLED::startConfig (void) {
    Adafruit_SSD1306::begin(SSD1306_SWITCHCAPVCC, DIR_I2C_OLED);
    Adafruit_SSD1306::setTextColor(SSD1306_WHITE);
    Adafruit_SSD1306::clearDisplay ();
}

/* Display in the screen the Moisture %, the temperature ºC and humidity % */
void OLED::displayInit (void) {
    clearDisplay();

    setTextSize(5);
    setCursor(10, 10);
    print("M");

    setTextSize(2);
    setCursor(37, 27);
    print("acetron");
    
    drawFastHLine(34, 43, 90, WHITE);
    drawFastHLine(34, 44, 90, WHITE);

    display();
}

/* Display in the screen the Moisture %, the temperature ºC and humidity % */
void OLED::displayMoistureTemperatureHumidity (uint16_t moisture, float temperature, 
                                               float humidity) {
    clearDisplay();

    /* Print Soil Moisture */
    setTextSize(2);
    setCursor(0, 2);
    print("Soil:  ");
    print(moisture);
    print("%");
    setCursor(98, 10);
    setTextSize(1);
    print("\n");

    /* Print temperature */
    print("Temperature: ");
    if (temperature == TEMPERATURE_ERROR)
    {
        print("Error");
    }
    else
    {
        print(temperature);
        print(" C");
    }
    print("\n");

    /* Print humidity */
    print("Humidity:    ");
    if (humidity == HUMIDITY_ERROR)
    {
        print("Error");
    }
    else
    {
        print(humidity);
        print(" %");
    }
    print("\n");

    display();
}

/* TODO */
void OLED::displayMoistureCalibration (uint16_t moisture, int analogRead) {
    clearDisplay();

    /* Print Soil Moisture */
    setTextSize(2);
    setCursor(0, 2);
    print("Soil: ");
    print(moisture);
    print("%\n");
    setTextSize(1);
    print("AnalogRead: ");
    print(analogRead);
    print("\n");

    display();
}