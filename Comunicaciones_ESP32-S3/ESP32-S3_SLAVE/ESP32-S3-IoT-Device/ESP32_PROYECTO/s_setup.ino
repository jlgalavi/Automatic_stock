//TaskHandle_t ilumination_Task; 
//TaskHandle_t readbutton_Task; 
//TaskHandle_t readbutton_Task; 

void on_setup() {
    pinMode(LED_BUILTIN, OUTPUT);;
    pinMode(PIN_BUTTON, INPUT);

    String hello_msg = String("Hola Mundo! Desde dispositivo ") + deviceID;
    enviarMensajePorTopic(HELLO_TOPIC, hello_msg);

    
  xTaskCreate(ilumination, "ilumination", 2048, NULL, 1, &ilumination_Task);
  xTaskCreate(readbutton, "readbutton", 2048, NULL, 1, &readbutton_Task);
//  xTaskCreatePinnedToCore(QRCodeReader, "QRCodeReader_Task", 10000, NULL, 1, &QRCodeReader_Task, 0);
}
