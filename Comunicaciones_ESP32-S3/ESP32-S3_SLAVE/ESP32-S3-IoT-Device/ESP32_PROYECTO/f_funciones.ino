/*TaskHandle_t ilumination_Task; 
TaskHandle_t readbutton_Task; 
//TaskHandle_t readbutton_Task; 

void on_setup() {
    pinMode(LED_BUILTIN, OUTPUT);;
    pinMode(PIN_BUTTON, INPUT);

    String hello_msg = String("Hola Mundo! Desde dispositivo ") + deviceID;
    enviarMensajePorTopic(HELLO_TOPIC, hello_msg);

    
  xTaskCreatePinnedToCore(ilumination, "ilumination_Task", 10000, NULL, 1, &ilumination_Task, 0);
  xTaskCreatePinnedToCore(readbutton, "readbutton_Task", 10000, NULL, 1, &readbutton_Task, 0);
//  xTaskCreatePinnedToCore(QRCodeReader, "QRCodeReader_Task", 10000, NULL, 1, &QRCodeReader_Task, 0);
}*/

void readbutton( void * pvParameters )  //leera en el w_loop el boton todo el rato en caso de estar pulsado envia señal
{
  delay(200);
  
  StaticJsonDocument<200> doc; //crea el mensaje en formato json
  doc["EMERGENCY_TYPE"] = "stop";
  String state_json;
  serializeJson(doc, state_json);

  if(digitalRead(PIN_BUTTON) == LOW) //Si el boton esta pulsado
  {
     enviarMensajePorTopic(EMERGENCY_TOPIC, state_json); //envia por el topic el mensaje
     vTaskDelete(ilumination_Task);
     vTaskDelete(QRCodeReader_Task);
     vTaskDelete(readbutton_Task);
  }
}
//leer sensor temperatura
void ilumination( void * pvParameters )
{
  int adcVal = analogRead(PIN_ANALOG_IN); //lee el valor del sensor ldr
 
  StaticJsonDocument<200> doc; //crea el mensaje en formato json
  doc["ID_SENSOR"] = "ldr001";
  doc["DATA"] = "lightoff";
  String state_json;
  serializeJson(doc, state_json);

  if(adcVal > 700)  //si el ldr capta poca luz
  {
    enviarMensajePorTopic(ILUMINATION_TOPIC, state_json);   //envia por el topic el mensaje
  }
}