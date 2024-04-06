#ifndef MAIN_CONFIG_H
#define MAIN_CONFIG_H

/***************************************************************************************************
*                                        IMPORTED MODULES                                          *
***************************************************************************************************/
#include <Arduino.h>

/***************************************************************************************************
*                                            DEBUG MODE                                            *
***************************************************************************************************/
// #define debug_serial_print /* Uncomment for serial print (Serial print can cause display glitches)*/

#ifdef debug_serial_print
#define DEBUG_SERIAL_BEGIN(...) Serial.begin(__VA_ARGS__)
#define DEBUG_SERIAL_PRINT(...) Serial.print(__VA_ARGS__)
#define DEBUG_SERIAL_PRINTLN(...) Serial.println(__VA_ARGS__)
#else
#define DEBUG_SERIAL_BEGIN(...)
#define DEBUG_SERIAL_PRINT(...)
#define DEBUG_SERIAL_PRINTLN(...)
#endif


/***************************************************************************************************
*                                              PINOUT                                              *
***************************************************************************************************/
/********************* Soil Moisture Sensor **********************/
#define PIN_DATA_SMS                A0

/********************** OLED Display (I2C) ***********************/
#define PIN_SCL_OLED                A5
#define PIN_SDA_OLED                A4

/************************** DHT22 Sensor *************************/
#define PIN_GND_DHT22               3
#define PIN_DATA_DHT22              4

/************************* Physical Input*************************/
#define PIN_BUTTON                  7

// /***************************** SD ********************************/
// //TODO cambiar pines SD
// #define PIN_SCK_SD                  D5
// #define PIN_MISO_SD                 D6
// #define PIN_MOSI_SD                 D7
// #define PIN_CS_SD                   D8

/***************************************************************************************************
*                                     PARAMETER CONFIGURATION                                      *
***************************************************************************************************/
/****************************** SMS ******************************/
/* Minimum percentage tolerance for humidity variations */
#define SMS_HUMIDITY_TOLERANCE      1
#define SMS_DRY_CALIBRATION_VALUE   492
#define SMS_WET_CALIBRATION_VALUE   283

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

/* UI SIZES */
#define ICON_WATERDROP_W            19
#define ICON_WATERDROP_H            30
#define ICON_WATERDROP_XPOS         0
#define ICON_WATERDROP_YPOS         3

#define SPACE_WATERDROP_SOIL_BAR    10

#define SOIL_BAR_H                  20
#define SOIL_BAR_W                  (OLED_WIDTH - ICON_WATERDROP_W - SPACE_WATERDROP_SOIL_BAR)
#define SOIL_BAR_RADIUS             7
#define SOIL_BAR_XPOS               (ICON_WATERDROP_W + SPACE_WATERDROP_SOIL_BAR)
#define SOIL_BAR_YPOS               ((ICON_WATERDROP_H - SOIL_BAR_H) / 2 + ICON_WATERDROP_YPOS)

#define TWO_DIGIT_DATA_SIZE_2_H     14
#define TWO_DIGIT_DATA_SIZE_2_W     22
#define DATA_PLUS_PCT_SIZE_2_H      TWO_DIGIT_DATA_SIZE_2_H
#define DATA_PLUS_PCT_SIZE_2_W      40
#define DATA_YPOS                   47

#define TEMPERATURE_DATA_XPOS       0
#define CELSIUS_RADIUS              2
#define CELSIUS_CIRCLE_XPOS         (TWO_DIGIT_DATA_SIZE_2_W + CELSIUS_RADIUS + 2)
#define CELSIUS_XPOS                (CELSIUS_CIRCLE_XPOS + 5)

#define HUMIDITY_DATA_XPOS          (OLED_WIDTH / 2)
#define PERCENTAGE_XPOS             (HUMIDITY_DATA_XPOS + TWO_DIGIT_DATA_SIZE_2_W + 4)
#define HUM_ICON_XPOS               (HUMIDITY_DATA_XPOS + DATA_PLUS_PCT_SIZE_2_W + 3)
#define HUM_ICON_H                  6
#define HUM_ICON_W                  21

/***************************************************************************************************
*                                       OTHER PARAMETERS                                           *
***************************************************************************************************/
/********************************* STATE MACHINE ******************************/
#define IDLE_STATE                  0
#define FRONT_SCREEN_STATE          1
#define FRONT_SAD_SCREEN_STATE      2
#define FRONT_HAPPY_SCREEN_STATE    3
#define VALUES_SCREEN_STATE         4
#define CALIBRATION_SCREEN_STATE    5

/************************************** MODE **********************************/
#define NORMAL_MODE                 0
#define DEBUG_MODE                  1
#define CALIBRATION_MODE            2

/************************************* DELAYS *********************************/
#define DELAY_INIT_SCREEN           2000
#define DELAY_CALIBRATION_SCREEN    1000
#define DELAY_HAPPY_PLANT_SCREEN    5000

/******************************** PHYSICAL INPUTS *****************************/
#define BUTTON_NO_PRESS             0
#define BUTTON_CLICK                1
#define BUTTON_DOUBLE_CLICK         2
#define BUTTON_LONG_CLICK           3

#endif /* MAIN_CONFIG_H */