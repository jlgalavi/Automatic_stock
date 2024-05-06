#include "box.h"
#include "container.h"
#include "order.h"
#include "Vector.h"

Vector<order> OrdersQueque;

void add_order(String incomingMessage)
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
    OrdersQueque.push_back(inputOrder);
    Serial.println("ORDER SOCKED");
  }
  else warnln("**>> Solicitud no reconocida!");  
}

void print_orders()
{
  for(int i = 0; i < OrdersQueque.size(); i++)
  {
    OrdersQueque[i].print_order();
  }
}


