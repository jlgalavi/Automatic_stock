void suscribirseATopics() {
  
  // TODO: añadir suscripciones a los topics MQTT ...
  mqtt_subscribe(HELLO_TOPIC);
  mqtt_subscribe(INFOPEDIDO_TOPIC);
  mqtt_subscribe(STOCK_TOPIC);
  mqtt_subscribe(TEMPERATURE_TOPIC);
  mqtt_subscribe(EMERGENCY_TOPIC);
  mqtt_subscribe(CONTROLBOX_TOPIC);

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
    add_order(incomingMessage);
    print_orders();
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
  if (strcmp(topic, TEMPERATURE_TOPIC) == 0 ) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      JsonArray array = doc.as<JsonArray>();
      for(JsonVariant v : array) {
        JsonObject obj = v.as<JsonObject>();

        String ID_SENSOR_T = obj["ID_SENSOR"];
        float data = obj["DATA"];

        Serial.println(ID_SENSOR_T);
        Serial.println(data);
        
      }
    }
    else warnln("**>> Solicitud no reconocida!");
  }
  if (strcmp(topic, EMERGENCY_TOPIC) == 0 ) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String EMERGENCY = doc["EMERGENCY_TYPE"];
      Serial.println(EMERGENCY);
    }
    else warnln("**>> Solicitud no reconocida!");
  }
  if (strcmp(topic, CONTROLBOX_TOPIC) == 0 ) {
      JsonDocument doc;
      DeserializationError err = deserializeJson(doc, incomingMessage);
      if (!err) {
        String ID_BOX = doc["ID_BOX"];
        Serial.println(ID_BOX);
      }
      else warnln("**>> Solicitud no reconocida!");
    }


}

void enviarMensajePorTopic(const char* topic, String outgoingMessage) {

  mqtt_publish(topic, outgoingMessage.c_str());

}





