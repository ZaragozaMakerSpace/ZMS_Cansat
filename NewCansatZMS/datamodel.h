struct SensorData {
  uint16_t idPacket;
  float accelX, accelY, accelZ;
  float pressure;
  float altitude;
} data;

void eepromGet() {
  for (uint8_t i = 0; i < 1024 / sizeof(data); i++) {
    EEPROM.get(i * sizeof(data), data);
    DUMP( PACKET_MSG, data.idPacket);
    DUMP( ACCX_MSG, data.accelX)
    DUMP( ACCY_MSG, data.accelY)
    DUMP( ACCZ_MSG, data.accelZ)
    DUMP( PRESSURE_MSG, data.pressure)
    DUMP( ALTITUDE_MSG, data.altitude)
  }
}

void eepromSave() {
  EEPROMWrite(eeAddress, data);
  eeAddress = ((data.idPacket) / 4) * sizeof(data);

  // EEPROM.put(eeAddress, miniPaquete);
  // eeAddress = ((miniPaquete.idPaquete) / 4) * sizeof(miniPaquete);
  // DUMPSLN("grabando");

  // DUMPSLN("No se graba");
}
