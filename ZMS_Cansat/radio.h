
#include <SPI.h>
#include <RH_RF69.h>
#include <RHDatagram.h>


/*//Tamaño del mensaje
  #define RH_RF69_MAX_ENCRYPTABLE_PAYLOAD_LEN 64 //tamaño del mensaje codificable
  #define RH_RF69_HEADER_LEN 4 //tamaño de la cabecera
  #define RH_RF69_MAX_MESSAGE_LEN (RH_RF69_MAX_ENCRYPTABLE_PAYLOAD_LEN - RH_RF69_HEADER_LEN)
*/


/************ Configuración de la Radio  ***************/

//Hay que indicar la frecuenca de nuestra radio
#define RF69_FREQ 433.0 //esto es un comentario 868//915.0

// Cada radio tiene un identificador
#define DEST_ADDRESS   1//Esta es el identificador de la estación base. 

// Cada emisor deberá tener una dirección única
#define MY_ADDRESS     2


//Pines donde están conectadas nuestras placas, definidos por el fabricante

#define RFM69_INT     3  // 
#define RFM69_CS      10  //
#define RFM69_RST     4  // 
#define LED           13

// Creamos un "objeto" radio con el trabajaremos.
RH_RF69 rf69(RFM69_CS, RFM69_INT);

// Control de los mensajes, entrantes y salientes
//Solo acepta los de su dirección.
RHDatagram rf69_manager(rf69, MY_ADDRESS);


int16_t packetnum = 0;  // Contador de mensajes recibidos


//declaracion variables

bool setupRadio()
{
  bool radioOk = false;

  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, LOW);

  Serial.println("Transmisón desde el satélite");
  Serial.println("");

  // manual reset para activar la radio.
  digitalWrite(RFM69_RST, HIGH);
  delay(10);
  digitalWrite(RFM69_RST, LOW);
  delay(10);

  if (rf69_manager.init())
  {
    radioOk = true;
  }

  if (!rf69.setFrequency(RF69_FREQ))
  {
    Serial.println("setFrequency failed \n CHECK RADIO TX/RX");
  }

  rf69.setTxPower(20);//rango de 14-20 arg must be true for 69HCW

  // Tenemos una clave de cifrado para los mensajes, debe ser la misma en el emisor y el receptor
  uint8_t key[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
                  };
  rf69.setEncryptionKey(key);

  pinMode(LED, OUTPUT);

  Serial.print("RFM69 radio @");
  Serial.print ((int)RF69_FREQ);  Serial.println(" MHz");


}


String datosRadio()
{
  String s = "";
  //Construimos un mensaje de texto sumando los valores interpretados como un objeto String (NOTA: String NO ES IGUAL cadena de texto)
  s = s + paquete.idPaquete + ";" + paquete.temperatura + ";" + paquete.altitud + ";" + paquete.acMaxima + ";" + paquete.acMinima +"\n";
  return s;
}
