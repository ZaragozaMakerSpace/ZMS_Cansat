
char radioBuffer[RH_RF69_MAX_MESSAGE_LEN];
unsigned int counter = 0;

void resetRadio() {
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, LOW); delay(100);
  digitalWrite(RFM69_RST, HIGH); delay(100);
  digitalWrite(RFM69_RST, LOW); delay(100);
}

bool setupRadio() {
  resetRadio();

  if (!rf69.init()) return false;

  rf69.setTxPower(20, true);
  rf69.setFrequency(RF69_FREQ);
  rf69.setModemConfig(RH_RF69::GFSK_Rb250Fd250);
  rf69.setCADTimeout(50);
 
    uint8_t version = rf69.spiRead(0x10);
    DUMPS( MSG_RADIO_VERSION );
    Serial.println(version, HEX);
    if (version == 0x24) {
      DUMPSLN( MSG_MODULE_OK );
    } else {
      DUMPSLN(MSG_MODULE_ERROR );
  }

  DUMPSLN( MSG_RADIO_INIT );
  delay(2000);
   return true;
}


void sendRadioPacket(){
  snprintf(radioBuffer, sizeof(radioBuffer), "CNT:%u", counter++);

  if (rf69.send((uint8_t*)radioBuffer, sizeof(radioBuffer))) {
    Serial.println((char*)radioBuffer);
  } else
    DUMPSLN( MSG_SEND_FAILED );
  delay(interval);
}
