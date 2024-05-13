void on_setup() {
    int result;
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);;
    pinMode(PIN_BUTTON, INPUT);

    setInternalLed(0);
    result=reader.setup();
    //reader.setDebug(true);
    //Serial.print("modo_debug ");
    Serial.println(reader.debug);
    if (result==SETUP_CAMERA_INIT_ERROR) Serial.println("Error init camara");
    else Serial.println("camara iniciada");
    Serial.println("Setup QRCode Reader");
    

    reader.beginOnCore(1);

    String hello_msg = String("Hola Mundo! Desde dispositivo ") + deviceID;
    enviarMensajePorTopic(HELLO_TOPIC, hello_msg);

}

