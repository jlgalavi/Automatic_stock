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

}
//leer sensor temperatura

//leer qr
