#ifdef __BMP280_H__

void readBMP() {
  DUMP( TEMP_MSG , bmp.readTemperature());
  DUMPSLN( TEMP_UNIT );

  DUMP( PRESSURE_MSG , bmp.readPressure());
  DUMPSLN( PRESSURE_UNIT );

  DUMP(ALTITUDE_MSG, bmp.readAltitude(1013.25));
  DUMPSLN( ALTITUDE_UNIT );
}

#endif
