#ifndef _CANSAT_CONFIG_H
#define _CANSAT_CONFIG_H
/*******************************************************/
/************ Configuración de la Radio  ***************/
/*******************************************************/

// Hay que indicar la frecuenca de nuestra radio
#define RF69_FREQ       868.0
#define RFM69_CS        10  // Pin CS (NSS)
#define RFM69_INT       3   // Pin de interrupción (DIO0)
#define RFM69_RST       9
#define INTERRUPT_PIN   2
#define CANSAT_ID       2   // Cada emisor deberá tener una dirección única
#define BASE_ID         1   // Esta es el identificador de la estación base.
#define interval        1000


/*******************************************************/
/**************** Configuración EEPROM  *******************/
/*******************************************************/

#define EEPROM_SAVEDATA

/*******************************************************/
/**************** Configuración IMU  *******************/
/*******************************************************/

#define IMU_INTERRUPTION
#define IMU_INTERRUPT_PIN 2 // Avoid Pin 2 connected to Radio

// ------------------ SERIAL CONFIG --------------------//
#define DEBUG false
#define PRINTDEBUG false
#define SERIALDEBUG Serial
#define SERIALBAUDS 9600

#if DEBUG

    #define MSG_INIT_FAILED      "init failed"
    #define MSG_MODULE_OK        "Modulo funcionando correctamente ✅"
    #define MSG_MODULE_ERROR     "Version inesperada. ❌"
    #define MSG_RADIO_INIT       "Radio Cansat Initialized"
    #define MSG_RADIO_VERSION    "Version RFM69: 0x"
    #define MSG_DMP_INITIALIZING "Initializing DMP..."
    #define MSG_DMP_STATUS       "Status "
    #define MSG_DMP_ENABLING     "Enabling DMP..."
    #define MSG_DMP_READY        "DMP ready! Waiting for first interrupt..."
    #define MSG_DMP_FAIL         "DMP Initialization failed : "
    #define MSG_DMP_INT          "Enabling interrupt detection "
    #define MSG_BMP_FAIL         "No sensor BMP280!"
    #define MSG_IMU_TITLE        "Cansat MPU6050"
    #define MSG_BMP_TITLE        "Cansat BMP280 + IMU"
    #define MSG_SEND_FAILED      "sendtoWait failed"
    #define MSG_SEND_SUCCESS     "Paquete enviado: "
    #define TEMP_MSG             "Temperature = "
    #define TEMP_UNIT            " *C"
    #define PRESSURE_MSG         "Pressure = "
    #define PRESSURE_UNIT        " Pa"
    #define ALTITUDE_MSG         "Altitude = "
    #define ALTITUDE_UNIT        " m"
    #define PACKET_MSG           "#Packet: "
    #define ACCX_MSG             " accX: "
    #define ACCY_MSG             " accY: "
    #define ACCZ_MSG             " accZ: "
    
    #define DUMPS(s)                                                               \
      {                                                                          \
        SERIALDEBUG.print(F(s));                                               \
      }
    #define DUMPSLN(s)                                                             \
      {                                                                          \
        SERIALDEBUG.println(F(s));                                             \
      }
    #define DUMPPRINTLN()                                                          \
      {                                                                          \
        SERIALDEBUG.println();                                                 \
      }
    #define DUMPV(v)                                                               \
      {                                                                          \
        SERIALDEBUG.print(v);                                                  \
      }
    #define DUMPLN(s, v)                                                           \
      {                                                                          \
        DUMPS(s);                                                              \
        DUMPV(v);                                                              \
        DUMPPRINTLN();                                                         \
      }
    #define DUMP(s, v)                                                             \
  {                                                                          \
    DUMPS(s);                                                              \
    DUMPV(v);                                                              \
  }
  #else
    #define MSG_INIT_FAILED      ""
    #define MSG_MODULE_OK        ""
    #define MSG_MODULE_ERROR     ""
    #define MSG_RADIO_INIT       ""
    #define MSG_RADIO_VERSION    ""
    #define MSG_DMP_INITIALIZING ""
    #define MSG_DMP_STATUS       ""
    #define MSG_DMP_ENABLING     ""
    #define MSG_DMP_READY        ""
    #define MSG_DMP_FAIL         ""
    #define MSG_DMP_INT          ""
    #define MSG_BMP_FAIL         ""
    #define MSG_IMU_TITLE        ""
    #define MSG_BMP_TITLE        ""
    #define MSG_SEND_FAILED      ""
    #define MSG_SEND_SUCCESS     ""
    #define TEMP_MSG             ""
    #define TEMP_UNIT            ""
    #define PRESSURE_MSG         ""
    #define PRESSURE_UNIT        ""
    #define ALTITUDE_MSG         ""
    #define ALTITUDE_UNIT        ""
    #define PACKET_MSG           ""
    #define ACCX_MSG             ""
    #define ACCY_MSG             ""
    #define ACCZ_MSG             ""
    
    #define DUMPS(s) {}
    #define DUMPSLN(s) {}
    #define DUMPPRINTLN() {}
    #define DUMPV(v) {}
    #define DUMPLN(s, v) {}
    #define DUMP(s, v) {}
  #endif

#endif
