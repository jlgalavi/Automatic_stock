#include "Algorithms.h"
#include "order.h"
#include "shipment.h"

void suscribirseATopics() {
  
  // TODO: añadir suscripciones a los topics MQTT ...
  mqtt_subscribe(HELLO_TOPIC);
  mqtt_subscribe(INFOPEDIDO_TOPIC);
}

void alRecibirMensajePorTopic(char* topic, String incomingMessage) {

  // TODO: Controlador que gestiona la recepción de datos

  // A partir de aquí debemos gestionar los mensajes
  //  recibidos por los diferentes topics (canales)
  //

  // If a message is received on the topic ...
  if (strcmp(topic, HELLO_TOPIC) == 0 ) {
    if(incomingMessage == "on") {
      infoln("TODO: Encender el led interno");
    }
    else if (incomingMessage == "off") {
      infoln("TODO: Apagar el led interno");
    }
    else warnln("**>> Solicitud no reconocida!");
  }
  if (strcmp(topic, INFOPEDIDO_TOPIC) == 0 ) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, incomingMessage);
    int S = 0, M = 0, L = 0, X = 0;
    if (!err) {
      JsonArray array = doc.as<JsonArray>();
      for(JsonVariant v : array) {
        int id = v["id"];
        if(id == 1){
          S = v["quantity"];
        } else if(id == 2){
          M = v["quantity"];
        } else if(id == 3){
          L = v["quantity"];
        } else if(id == 4){
          X = v["quantity"];
        }
      }
      order webOrder = order(S,M,L,X);
      webOrder.show_order();
      Algorithms A1(webOrder.get_num_boxes(), 100, 100, 50, webOrder.get_V_boxes());
      /*A1.place_boxes();
      shipment S1(A1.V_boxes_in_use, A1.V_containers_in_use, A1.V_targets);
      std::string orderProces;
      S1.save_shipment(orderProces);
      String output = String(orderProces.c_str());
      enviarMensajePorTopic(ORDERPROCES_TOPIC, output);*/
    }
    else warnln("**>> Solicitud no reconocida!");
  }
}

void enviarMensajePorTopic(const char* topic, String outgoingMessage) {

  mqtt_publish(topic, outgoingMessage.c_str());

}





