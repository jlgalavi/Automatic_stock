struct Buffer_Circ {
  int data[100];
  int bufIN, bufOUT, contador;
};

// Instancia del buffer
Buffer_Circ Buffer;

// Declaraciones de funciones
int get_item(int* x, Buffer_Circ* buff);
int put_item(int x, Buffer_Circ* buff);
bool vacia(Buffer_Circ* buff);
bool llena(Buffer_Circ* buff);
void list(Buffer_Circ* buff);
int tam(Buffer_Circ* buff);

// Implementación de las funciones
int get_item(int* x, Buffer_Circ* buff) 
{
  if (vacia(buff))
    return -1;
  else 
  {
    *x = buff->data[buff->bufOUT];
    buff->contador--;
    buff->bufOUT = (buff->bufOUT + 1) % 100;
    return 0;
  }
}

int put_item(int x, Buffer_Circ* buff) 
{
  if (llena(buff))
    return -1;
  else 
  {
    buff->data[buff->bufIN] = x;
    buff->contador++;
    buff->bufIN = (buff->bufIN + 1) % 100;
    return 0;
  }
}

bool vacia(Buffer_Circ* buff) 
{
  return buff->contador == 0;
}

bool llena(Buffer_Circ* buff) 
{
  return buff->contador == 100;
}

void list(Buffer_Circ* buff) 
{
  for (int i = 0; i < buff->contador; i++) 
    Serial.println(buff->data[(buff->bufOUT + i) % 10]);
  
}

int tam(Buffer_Circ* buff) 
{
  return buff->contador;
}



void readbutton( void * pvParameters )  //leera en el w_loop el boton todo el rato en caso de estar pulsado envia señal
{
  while(1)
  { 
    if(digitalRead(PIN_BUTTON) == LOW) //Si el boton esta pulsado
    {
      StaticJsonDocument<200> doc; //crea el mensaje en formato json
      doc["EMERGENCY_TYPE"] = "stop";
      String state_json;
      serializeJson(doc, state_json);

      enviarMensajePorTopic(EMERGENCY_TOPIC, state_json); //envia por el topic el mensaje
    }
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}
//leer sensor temperatura
void ilumination( void * pvParameters )
{
  while(1)
  {
    int adcVal = analogRead(PIN_ANALOG_IN); //lee el valor del sensor ldr

    //Serial.println(adcVal);

    if(adcVal > 2200)  //si el ldr capta poca luz
    {    
      StaticJsonDocument<200> doc; //crea el mensaje en formato json
      doc["ID_SENSOR"] = "ldr001";
      doc["DATA"] = "lightoff";
      String state_json;
      serializeJson(doc, state_json);
      enviarMensajePorTopic(ILUMINATION_TOPIC, state_json);   //envia por el topic el mensaje
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);

  }
}