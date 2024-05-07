void create_order()
{
  StaticJsonDocument<200> order_doc;
  StaticJsonDocument<200> container_doc;
  StaticJsonDocument<200> box_doc;

  delay(1000);
  // Llena los documentos con los datos
  order_doc["ORDERTYPE"] = "0";
  order_doc["ACTION"] = "start";
  order_doc["IDORDER"] = "pedidoID";
  order_doc["NCONTAINERS"] = "2";

  String order_json;
  serializeJson(order_doc, order_json);
  enviarMensajePorTopic(INFOPEDIDO_TOPIC, order_json);
  delay(1500);

  container_doc["ORDERTYPE"] = "1";
  container_doc["IDCONTAINER"] = "containerID1";
  container_doc["NBOXES"] = "2";

  String container_json;
  serializeJson(container_doc, container_json);
  enviarMensajePorTopic(INFOPEDIDO_TOPIC, container_json);
  delay(1500);

  box_doc["ORDERTYPE"] = "2";
  box_doc["IDCONTAINER"] = "containerID1";
  box_doc["IDBOX"] = "X";
  box_doc["POSE"] = "(1,1,1)";

  String box_json;
  serializeJson(box_doc, box_json);
  enviarMensajePorTopic(INFOPEDIDO_TOPIC, box_json);
  delay(1500);

  box_doc["ORDERTYPE"] = "2";
  box_doc["IDCONTAINER"] = "containerID1";
  box_doc["IDBOX"] = "L";
  box_doc["POSE"] = "(2,2,2)";

  serializeJson(box_doc, box_json);
  enviarMensajePorTopic(INFOPEDIDO_TOPIC, box_json);
  delay(1500);

  container_doc["ORDERTYPE"] = "1";
  container_doc["IDCONTAINER"] = "containerID2";
  container_doc["NBOXES"] = "1";

  serializeJson(container_doc, container_json);
  enviarMensajePorTopic(INFOPEDIDO_TOPIC, container_json);
  delay(1500);

  box_doc["ORDERTYPE"] = "2";
  box_doc["IDCONTAINER"] = "containerID2";
  box_doc["IDBOX"] = "M";
  box_doc["POSE"] = "(3,3,3)";

  serializeJson(box_doc, box_json);
  enviarMensajePorTopic(INFOPEDIDO_TOPIC, box_json);
  delay(1500);

  order_doc["ORDERTYPE"] = "0";
  order_doc["ACTION"] = "stop";
  order_doc["IDORDER"] = "pedidoID";
  order_doc["NCONTAINERS"] = "2";

  serializeJson(order_doc, order_json);
  enviarMensajePorTopic(INFOPEDIDO_TOPIC, order_json);
  delay(1500);
}


/*void add_order(String incomingMessage)
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
    Orders.push_back(inputOrder);
    Serial.println("ORDER SOCKED");
  }
  else warnln("**>> Solicitud no reconocida!");  
}

void print_orders()
{
  for(int i = 0; i < OrdersQueque.size(); i++)
  {
    Orders[i].print_order();
  }
}*/


