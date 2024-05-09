String bDespaletizado = "";
box bAsignacion[100];

void suscribirseATopics() {

  // TODO: añadir suscripciones a los topics MQTT ...
  mqtt_subscribe(HELLO_TOPIC);
  mqtt_subscribe(INFOPEDIDO_TOPIC);
  mqtt_subscribe(STOCK_TOPIC);
  //mqtt_subscribe(TEMPERATURE_TOPIC);
  //mqtt_subscribe(EMERGENCY_TOPIC);
  //mqtt_subscribe(CONTROLBOX_TOPIC);
  mqtt_subscribe(STATION_STATUS_TOPIC);
  mqtt_subscribe(ASIGNACION_STATUS_TOPIC);
  mqtt_subscribe(DESPALETIZADO_STATUS_TOPIC);
  mqtt_subscribe(CONVEYOR1_STATUS_TOPIC);
  mqtt_subscribe(SENSOR1_STATUS_TOPIC);
}

void alRecibirMensajePorTopic(char* topic, String incomingMessage) {

  // TODO: Controlador que gestiona la recepción de datos

  // A partir de aquí debemos gestionar los mensajes
  //  recibidos por los diferentes topics (canales)
  //

  // If a message is received on the topic ...
  if (strcmp(topic, HELLO_TOPIC) == 0) {
  }
  if (strcmp(topic, STATION_STATUS_TOPIC) == 0) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String state = doc["STATE"];
      if (state == "ready") {
        StaticJsonDocument<200> doc;
        doc["STATE"] = "ready";
        String state_json;
        serializeJson(doc, state_json);
        enviarMensajePorTopic(CONVEYOR1_STATUS_TOPIC, state_json);
        enviarMensajePorTopic(DESPALETIZADO_STATUS_TOPIC, state_json);
        enviarMensajePorTopic(ASIGNACION_STATUS_TOPIC, state_json);
        enviarMensajePorTopic(SENSOR1_STATUS_TOPIC, state_json);
      }
    } else warnln("**>> Solicitud no reconocida!");
  }
  if (strcmp(topic, DESPALETIZADO_STATUS_TOPIC) == 0) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String state = doc["STATE"];
      if (state == "ready") {
        String order = "Despaletizado_";
        for (int i = 0; i < bDespaletizado.length(); i++) {
          if (bDespaletizado[i] != 'F') {
            StaticJsonDocument<200> doc;
            order = order + bDespaletizado[i];
            doc["ACTION"] = order;
            String action_json;
            serializeJson(doc, action_json);
            enviarMensajePorTopic(DESPALETIZADO_COMMANDS_TOPIC, action_json);
            bDespaletizado[i] = 'F';
            i = bDespaletizado.length();
            // TODO: Reiniciar cadena de texto
          }
        }
      }
      Serial.println(bDespaletizado);
    }
  }
  if (strcmp(topic, CONVEYOR1_STATUS_TOPIC) == 0) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String state = doc["STATE"];
      StaticJsonDocument<200> doc;
      String action_json;
      if (state == "ready") {
        doc["ACTION"] = "start";
        serializeJson(doc, action_json);
        enviarMensajePorTopic(CONVEYOR1_COMMANDS_TOPIC, action_json);
      } else if (state == "object") {
        doc["ACTION"] = "stop";
        serializeJson(doc, action_json);
        enviarMensajePorTopic(CONVEYOR1_COMMANDS_TOPIC, action_json);
      }
    }
  }
  if (strcmp(topic, ASIGNACION_STATUS_TOPIC) == 0) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    String order = "Colocar_";
    if (!err) {
      String state = doc["STATE"];
      if (state == "start") {
        for (int i = 0; i < bDespaletizado.length(); i++) {
          if (!(bAsignacion[i].get_setBox())) {
            StaticJsonDocument<200> doc;
            order = order + bAsignacion[i].get_boxID();
            doc["ACTION"] = order;
            doc["POSE"] = bAsignacion[i].get_boxpos();
            String action_json;
            serializeJson(doc, action_json);
            enviarMensajePorTopic(ASIGNACION_COMMANDS_TOPIC, action_json);
            bAsignacion[i].set_box();
            i = bDespaletizado.length();
          }
        }
      }

    } else warnln("**>> Solicitud no reconocida!");
  }
  if (strcmp(topic, SENSOR1_STATUS_TOPIC) == 0) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String state = doc["STATE"];
      if(state == "ready"){
        StaticJsonDocument<200> doc;
        doc["ACTION"] = "start";
        String action_json;
        serializeJson(doc, action_json);
        enviarMensajePorTopic(SENSOR1_COMMANDS_TOPIC, action_json);

      }
    }
  }
  if (strcmp(topic, INFOPEDIDO_TOPIC) == 0) {
    getOrder(&bDespaletizado, bAsignacion, incomingMessage);
  }
  /*if (strcmp(topic, STOCK_TOPIC) == 0) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String msg = doc["msg"];
      Serial.println(msg);
    } else warnln("**>> Solicitud no reconocida!");
  }
  if (strcmp(topic, TEMPERATURE_TOPIC) == 0) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      JsonArray array = doc.as<JsonArray>();
      for (JsonVariant v : array) {
        JsonObject obj = v.as<JsonObject>();

        String ID_SENSOR_T = obj["ID_SENSOR"];
        float data = obj["DATA"];

        Serial.println(ID_SENSOR_T);
        Serial.println(data);
      }
    } else warnln("**>> Solicitud no reconocida!");
  }
  if (strcmp(topic, EMERGENCY_TOPIC) == 0) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String EMERGENCY = doc["EMERGENCY_TYPE"];
      Serial.println(EMERGENCY);
    } else warnln("**>> Solicitud no reconocida!");
  }
  if (strcmp(topic, CONTROLBOX_TOPIC) == 0) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    if (!err) {
      String ID_BOX = doc["ID_BOX"];
      Serial.println(ID_BOX);
    } else warnln("**>> Solicitud no reconocida!");
  }*/
}

void enviarMensajePorTopic(const char* topic, String outgoingMessage) {

  mqtt_publish(topic, outgoingMessage.c_str());
}
