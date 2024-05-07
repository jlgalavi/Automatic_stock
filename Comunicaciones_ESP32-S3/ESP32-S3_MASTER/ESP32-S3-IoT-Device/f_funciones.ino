void getOrder(order* inputOrder, String incomingMessage) {
  JsonDocument doc;
  DeserializationError err = deserializeJson(doc, incomingMessage);

  if (!err) {
    order tempOrder = order(doc["N_CONT"].as<int>(), doc["ID_PEDIDO"]);
    JsonArray CONTAINER = doc["CONTAINER"];
    for (JsonVariant v : CONTAINER) {
      container inputContainer = container(v["N_BOX"].as<int>(), v["ID_CONT"]);
      JsonArray Positions = v["BOXES"];
      for (JsonVariant w : Positions) {
        box inputBox = box(w["ID_BOX"], w["POSE"]);
        inputContainer.add_box(inputBox);
      }
      tempOrder.add_container(inputContainer);
    }
    inputOrder[0] = tempOrder;
    Serial.println("ORDER SOCKED");
  }
}

bool compareIDs(String ID1, String ID2)
{
  if(ID1 == ID2)
  {
    return true;
  } else
  {
    return false;
  }
  
}
void perpareOrder(order* outOrder) {

  StaticJsonDocument<200> action_doc;
  String action_json;
  container* tempC = outOrder->get_containers();

  for (int i = 0; i < outOrder->get_Size(); i++) {
    for (int j = 0; j < tempC[i].get_containerSize(); j++) {
      box* tempB = tempC[i].get_boxes();
      String ID = tempB[j].get_boxID();
      if (compareIDs(ID, "X")) {
        //Serial.println(tempB[j].get_boxID());
        action_doc["ACTION"] = "Despaletizado_XL";
        serializeJson(action_doc, action_json);
        Serial.println(action_json);
        enviarMensajePorTopic(DESPALETIZADO_COMMANDS_TOPIC, action_json);
        delay(1000);
      } else if (compareIDs(ID, "L")) {
        //Serial.println(tempB[j].get_boxID());
        action_doc["ACTION"] = "Despaletizado_L";
        serializeJson(action_doc, action_json);
        Serial.println(action_json);
        enviarMensajePorTopic(DESPALETIZADO_COMMANDS_TOPIC, action_json);
        delay(1000);
      } else if (compareIDs(ID, "M")) {
        //Serial.println(tempB[j].get_boxID());
        action_doc["ACTION"] = "Despaletizado_M";
        serializeJson(action_doc, action_json);
        Serial.println(action_json);
        enviarMensajePorTopic(DESPALETIZADO_COMMANDS_TOPIC, action_json);
        delay(1000);
      } else if (compareIDs(ID, "S")) {
        //Serial.println(tempB[j].get_boxID());
        action_doc["ACTION"] = "Despaletizado_S";
        serializeJson(action_doc, action_json);
        Serial.println(action_json);
        enviarMensajePorTopic(DESPALETIZADO_COMMANDS_TOPIC, action_json);
        delay(1000);
      }
    }
  }
}
