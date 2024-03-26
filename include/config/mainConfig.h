#ifndef MAIN_CONFIG_H
#define MAIN_CONFIG_H

/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include <Arduino.h>

/***************************************************************************************************
*                                              PINOUT                                              *
***************************************************************************************************/
// /********************* Soil Moisture Sensor **********************/
// #define PIN_DATA_SMS                A0
// //TODO ampliable a hasta 8 sensores de humedad de sustrato? Necesario ADC de varios canales o arduino

/********************** OLED Display (I2C) ***********************/
#define PIN_SCL_OLED                A5
#define PIN_SDA_OLED                A4

/************************** DHT22 Sensor *************************/
#define PIN_GND_DHT22               3
#define PIN_DATA_DHT22              4

// /************************* Water Pump ****************************/
// #define PIN_WATER_PUMP              D4
// //TODO ampliable a hasta 8 bombas de agua?

// /***************************** SD ********************************/
// //TODO cambiar pines SD
// #define PIN_SCK_SD                  D5
// #define PIN_MISO_SD                 D6
// #define PIN_MOSI_SD                 D7
// #define PIN_CS_SD                   D8

/***************************************************************************************************
*                                     PARAMETER CONFIGURATION                                      *
***************************************************************************************************/
// /****************************** SMS ******************************/
// /* Minimum percentage tolerance for humidity variations */
// #define SMS_HUMIDITY_TOLERANCE      1
// #define SMS_DRY_CALIBRATION_VALUE   644
// #define SMS_WET_CALIBRATION_VALUE   283

/************************* OLED DISPLAY **************************/
/* Screen dimensions */
#define OLED_WIDTH                  128
#define OLED_HEIGHT                 64
#define OLED_RESET                  4

/* I2C Address */
#define DIR_I2C_OLED                0x3C

/* Error indicators */
#define TEMPERATURE_ERROR           10000.0
#define HUMIDITY_ERROR              10000.0

/***************************************************************************************************
*                                       OTHER PARAMETERS                                         *
***************************************************************************************************/
/********************************* STATE MACHINE ******************************/
#define IDLE_STATE                  0
#define FACE_STATE                  1
#define DEBUG_STATE                 2

/************************************* DELAYS *********************************/
#define DELAY_INIT_SCREEN           2000

#endif /* MAIN_CONFIG_H */