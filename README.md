# Macetron 🪴

Sensors the humidity of the substrate, the temperature and the ambient humidity of a pot and displays the information obtained through an OLED screen.

## Pinout
![alt text](Doc/ArduinoNanoPinout.png)

| **Pin** | **Conected to** |
|:--------:|:---------------|
| A0 | DATA Soil moisture Sensor |
| A4 | SDA OLED |
| A5 | SCL OLED |
| D4 | GND DHT22 |
| D5 | DATA DHT22 |

## Calibration

The Soil Moisture Sensor (SMS) calibration values will be adjusted in the [mainConfig.h](include/config/mainConfig.h):
1. Uncomment the **"#define CALIBRATION_MODE"** and comment the other modes to start the calibration.
2. Leave the SMS out of the soil or a water source, and modify the define **"#define SMS_DRY_CALIBRATION_VALUE"** with the average value of analogRead read from the screen.
3. Insert the sensor up the line into a water source, and modify the define **"#define SMS_WET_CALIBRATION_VALUE"** with the average value of analogRead read from the screen.
4. The **"#define SMS_HUMIDITY_TOLERANCE"** allows establishing stable moisture values, since only register a change in the read data if the data exceed this margin.