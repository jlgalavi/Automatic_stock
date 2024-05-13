uint8_t ledStatus = 0;

void setInternalLed(uint8_t status) {
  if ( ledStatus == status ) // Nothing to do
    return;
    
  ledStatus = status;
  if ( status ) {
    infoln("Led: on");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    infoln("Led: off");
    digitalWrite(LED_BUILTIN, LOW);
  }

  // TODO: Deberíamos publicar el estado del dispositivo cada vez que cambie
}

void readbutton()  //leera en el w_loop el boton todo el rato en caso de estar pulsado envia señal
{
  String emergency_msg;
  delay(200);
  if(digitalRead(PIN_BUTTON) == LOW) //Si el boton esta pulsado
  {
    emergency_msg = String("Para la ejecución.") + deviceID; //crea el mensaje
    enviarMensajePorTopic(EMERGENCY_TOPIC, emergency_msg); //envia por el topic el mensaje
  }
}
//leer sensor temperatura
void ilumination()
{
  char* str_valor="";  //Cadena donde almacenaremos el valor convertido

  int adcVal = analogRead(PIN_ANALOG_IN); //lee el valor del sensor ldr
  if(adcVal > 700)  //si el ldr capta poca luz
  {
    String ilumination_msg = String("Luces apagadas.") + deviceID; //crea el mesnaje
    enviarMensajePorTopic(ILUMINATION_TOPIC, ilumination_msg);   //envia por el topic el mensaje
  }
  
  delay(100);
}
//leer qr
void cameraqr()
{
  
  String emergency_msg;
  struct QRCodeData qrCodeData;

  while (true)
  {
    //Serial.println("buscando código QR");
    if (reader.receiveQrCode(&qrCodeData, 100))
    {
      Serial.println("Found QRCode");
      if (qrCodeData.valid)
      { 
        //emergency_msg = String((const char *)qrCodeData.payload);
        //enviarMensajePorTopic(CONTROLBOX_TOPIC, emergency_msg);
        Serial.println((const char *)qrCodeData.payload);
      }
      else
      {
        Serial.print("Invalid: ");
      }
    }
    delay(200);
  }
}

