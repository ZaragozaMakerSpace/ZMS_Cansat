#include <Arduino.h>

#include "config.h"

#ifdef EEPROM_SAVEDATA
#include "eeprom.h"
#include "datamodel.h"
#endif

#include <RH_RF69.h>
RH_RF69 rf69(RFM69_CS, RFM69_INT);

#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>

#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps612.h"

#include "radio.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

Adafruit_BMP280 bmp;

#define OUTPUT_READABLE_YAWPITCHROLL
#define INTERRUPT_PIN 2
MPU6050 mpu;

#include "bmp_utils.h"
#include "imu_utils.h"

void setup() {
  if (PRINTDEBUG)
    SERIALDEBUG.begin(SERIALBAUDS);
  DUMPSLN(MSG_BMP_TITLE);

  setupRadio();
  
  bool status = bmp.begin(0x76);
  if (status) {
    bmp.setSampling(
      Adafruit_BMP280::MODE_NORMAL,  /* Operating Mode. */
      Adafruit_BMP280::SAMPLING_X2,  /* Temp. oversampling */
      Adafruit_BMP280::SAMPLING_X16, /* Pressure oversampling */
      Adafruit_BMP280::FILTER_X16,   /* Filtering. */
      Adafruit_BMP280::STANDBY_MS_500);
  } else {
    DUMPSLN(MSG_BMP_FAIL);
  }

  // IMU Initialization
  setupIMU();
  
}

void loop() {
  sendRadioPacket();
  readBMP();
  readIMU();
}
