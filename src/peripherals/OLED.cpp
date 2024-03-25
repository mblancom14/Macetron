/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include "..\include\peripherals\OLED.h"
#include "..\include\config\mainConfig.h"

/***************************************************************************************************
*                                     DEFINITIONS AND MACROS                                       *
***************************************************************************************************/

/***************************************************************************************************
*                                       GLOBAL PARAMETERS                                          *
***************************************************************************************************/

/***************************************************************************************************
*                                          FUNCTIONS                                               *
***************************************************************************************************/
/* Class constructor for the OLED screen */
OLED::OLED (uint8_t width, uint8_t height) : Adafruit_SSD1306 (width, height, &Wire, OLED_RESET) {
    // Start OLED screen with 0x3C address
    // if (!Adafruit_SSD1306::begin(SSD1306_SWITCHCAPVCC, DIR_I2C_OLED))
    // {
    //     Serial.println("[OLED] Screen not detected");
    // }
}

/* Start configuration */
void OLED::startConfig (void) {
    Adafruit_SSD1306::begin(SSD1306_SWITCHCAPVCC, DIR_I2C_OLED);
    Adafruit_SSD1306::setTextColor(SSD1306_WHITE);
    Adafruit_SSD1306::clearDisplay ();
}

/*  */
void OLED::displayMoistureTemperatureHumidiy (void) {
    
    /* Se imprime el valor de humedad */
    setTextSize (2);
    setCursor (2, 2);

    print ("Soil:");
    print ("%");
    setCursor (98, 10);
    setTextSize (1);
    print ("(");
    print (")\n");

    print ("DHT Temperature:");
    print ("\n");
    print ("DHT Humidity:   ");
    print ("\n");

    display();
}

