#include "box.h"
#include "container.h"
#include "order.h"


void add_order(const char* incomingMessage)
{
  JsonDocument doc;
  DeserializationError err = deserializeJson(doc, incomingMessage);
  if (!err) {
    order inputOrder = order(doc["N_CONT"].as<int>(), doc["ID_PEDIDO"]);
    JsonArray CONTAINER = doc["CONTAINER"];
    for(JsonVariant v : CONTAINER) {
      container inputContainer = container(v["N_BOX"].as<int>(), v["ID_CONT"]);
      JsonArray Positions = v["BOXES"];
      for(JsonVariant w : Positions) {
        box inputBox = box(w["ID_BOX"], w["POSE"]);
        inputContainer.add_box(inputBox);
      }
      inputOrder.add_container(inputContainer);
    }
  }
  else warnln("**>> Solicitud no reconocida!");  
}


