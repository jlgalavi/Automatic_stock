void suscribirseATopics() {
  
  // TODO: añadir suscripciones a los topics MQTT ...
  mqtt_subscribe(HELLO_TOPIC);
  mqtt_subscribe(INFOPEDIDO_TOPIC);
  mqtt_subscribe(DESPALETIZADO_TOPIC);
  mqtt_subscribe(ASIGNACION_TOPIC);
  mqtt_subscribe(STOCK_TOPIC);

}

void alRecibirMensajePorTopic(char* topic, String incomingMessage) {

  // TODO: Controlador que gestiona la recepción de datos

  // A partir de aquí debemos gestionar los mensajes
  //  recibidos por los diferentes topics (canales)
  //

  // If a message is received on the topic ...
  if (strcmp(topic, HELLO_TOPIC) == 0 ) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String msg = doc["msg"];
      Serial.println(msg);
    }
    else warnln("**>> Solicitud no reconocida!");
  }
   if (strcmp(topic, INFOPEDIDO_TOPIC) == 0 ) {
    const size_t capacity = 768;
    DynamicJsonDocument doc(capacity);
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
        const char* ID_PEDIDO = doc["ID_PEDIDO"];
        Serial.println(ID_PEDIDO);

        int N_CONT = doc["N_CONT"].as<int>();
        Serial.println(N_CONT);

        int N_BOX = doc["N_BOX"].as<int>();
        Serial.println(N_BOX);

        JsonArray CONTAINER = doc["CONTAINER"];
        for(JsonVariant v : CONTAINER) {
            const char* ID_CONT = v["ID_CONT"];
            Serial.println(ID_CONT);

            JsonArray Positions = v["Positions"];
            for(JsonVariant w : Positions) {
                const char* ID_BOX = w["ID_BOX"];
                Serial.println(ID_BOX);

                const char* POSE = w["POSE"];
                Serial.println(POSE);
            }
        }
        size_t requiredSize = measureJson(doc);
        Serial.println(requiredSize);
    }
    else warnln("**>> Solicitud no reconocida!");
  }
   if (strcmp(topic, DESPALETIZADO_TOPIC) == 0 ) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String msg = doc["msg"];
      Serial.println(msg);
    }
    else warnln("**>> Solicitud no reconocida!");
  }
   if (strcmp(topic, ASIGNACION_TOPIC) == 0 ) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String msg = doc["msg"];
      Serial.println(msg);
    }
    else warnln("**>> Solicitud no reconocida!");
  }
  if (strcmp(topic, STOCK_TOPIC) == 0 ) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String msg = doc["msg"];
      Serial.println(msg);
    }
    else warnln("**>> Solicitud no reconocida!");
  }

}

void enviarMensajePorTopic(const char* topic, String outgoingMessage) {

  mqtt_publish(topic, outgoingMessage.c_str());

}





