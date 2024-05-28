#include "Config.h"
void suscribirseATopics() {
  
  // TODO: añadir suscripciones a los topics MQTT ...
  mqtt_subscribe(HELLO_TOPIC);

}

void alRecibirMensajePorTopic(char* topic, String incomingMessage) {
/* if (strcmp(topic, CONTROL) == 0 ) {
    if (!err) {
      int luz = doc ["luz"];
      float distancia = doc["distancia"]; 
      int boton = doc["boton"];
    realizar_accion(luz, distancia, boton);
    }
  }*/
}
void enviarMensajePorTopic(const char* topic, String outgoingMessage) {
  mqtt_publish(topic, outgoingMessage.c_str());
}





