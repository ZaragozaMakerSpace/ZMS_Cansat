
/*
 * Creamos una unidad de información con formato de estructura 
 * Se crea GLOBAL para evitar tener que pasar datos y solo se actualizan en su función 
 * 
 */
//El tamaño de la estructura es de muy grande (18 Bytes)
struct dato
{
  uint16_t idPaquete;
  float temperatura;
  float altitud;
  float acMaxima;
  float acMinima;
}paquete;

struct miniDato
{
  int16_t idPaquete;
  int8_t temperatura;
  int8_t altitud;
  int8_t acMaxima;
  int8_t acMinima;
}miniPaquete;

uint8_t acMaxima4=0;
uint8_t acMinima4=255;

uint8_t acLauncher=0;

void setupDatos()
{
  paquete.acMaxima=0;
  paquete.acMinima=2000;
}
uint32_t flag=millis();
bool salvar=true;
