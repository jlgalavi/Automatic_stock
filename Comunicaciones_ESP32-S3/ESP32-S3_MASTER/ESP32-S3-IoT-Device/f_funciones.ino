bool STATE_DESPALETIZADO = false;
bool STATE_STATION = false;

void getOrder(String* bDespaletizado, box* bAsignacion, String incomingMessage) {
  JsonDocument doc;
  DeserializationError err = deserializeJson(doc, incomingMessage);
  int index = 0;
  if (!err) {
    order tempOrder = order(doc["N_CONT"].as<int>(), doc["ID_PEDIDO"]);
    JsonArray CONTAINER = doc["CONTAINER"];
    for (JsonVariant v : CONTAINER) {
      container inputContainer = container(v["N_BOX"].as<int>(), v["ID_CONT"]);
      JsonArray Positions = v["BOXES"];
      for (JsonVariant w : Positions) {
        box inputBox = box(w["ID_BOX"], w["POSE"]);
        String id = w["ID_BOX"];
        bDespaletizado[0] = bDespaletizado[0] + id;
        inputContainer.add_box(inputBox);
        bAsignacion[index] = inputBox;
        index++;
      }
      tempOrder.add_container(inputContainer);
    }
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

void setStateDespaletizado(bool state)
{
  STATE_DESPALETIZADO = state;
}

bool get_StateDespaletizado()
{
  return STATE_DESPALETIZADO;
}

void setStateStation(bool state)
{
  STATE_STATION = state;
}

bool get_StateStation()
{
  return STATE_STATION;
}

