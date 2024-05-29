#include "Config.h"
void suscribirseATopics() {
  
  // TODO: añadir suscripciones a los topics MQTT ...
  mqtt_subscribe(HELLO_TOPIC);

}

//void alRecibirMensajePorTopic(char* topic, String incomingMessage) {}

void enviarMensajePorTopic(const char* topic, String outgoingMessage) {
  mqtt_publish(topic, outgoingMessage.c_str());
}




void alRecibirMensajePorTopic(char* topic, String msg) {
  JsonDocument doc, vuelta, t;
  DeserializationError err = deserializeJson(doc, msg); 
  String msg1;
  int id = doc["id"];
  int nuevo_id;
  
  if(strcmp(topic, HELLO_TOPIC) == 0){
    switch(id){
      case 1:
        nuevo_id = 4;
        put_item(nuevo_id, &Buffer);
        nuevo_id = 5;
        put_item(nuevo_id, &Buffer);
      break;
      
      case 2:
        nuevo_id = 2;
        put_item(nuevo_id, &Buffer);
        nuevo_id = 3;
        put_item(nuevo_id, &Buffer);
      break;
      
      case 3:
        nuevo_id = 2;
        put_item(nuevo_id, &Buffer);
        nuevo_id = 3;
        put_item(nuevo_id, &Buffer);
        nuevo_id = 4;
        put_item(nuevo_id, &Buffer);
      break;
      
      case 4:
        nuevo_id = 2;
        put_item(nuevo_id, &Buffer);
        nuevo_id = 4;
        put_item(nuevo_id, &Buffer);
        nuevo_id = 5;
        put_item(nuevo_id, &Buffer);
      break;
      
      case 5:
        nuevo_id = 5;
        put_item(nuevo_id, &Buffer);
      break;
    
      case 6: 
        nuevo_id = 4;
        put_item(nuevo_id, &Buffer);
      break;
  
      case 7:
        nuevo_id = 2;
        put_item(nuevo_id, &Buffer);
      break;
      
      case 8:
        nuevo_id = 3;
        put_item(nuevo_id, &Buffer);
      break;
      
      case 9:
        nuevo_id = 1;
        put_item(nuevo_id, &Buffer);
      break;
      }
    }

  /*if(strcmp(topic, TOPIC2) == 0){
    if(id == 0){
      get_item(&id, &Buffer);
      switch(id){
      case 1:
        vuelta["id"] = id;
        serializeJson(vuelta, msg1);
        enviarMensajePorTopic(TOPIC2, msg1);
      break;
      
      case 2:
        vuelta["id"] = id;
        serializeJson(vuelta, msg1);
        enviarMensajePorTopic(TOPIC2, msg1);
      break;
      
      case 3:
        vuelta["id"] = id;
        serializeJson(vuelta, msg1);
        enviarMensajePorTopic(TOPIC2, msg1);
      break;
      
      case 4:
        vuelta["id"] = id;
        serializeJson(vuelta, msg1);
        enviarMensajePorTopic(TOPIC2, msg1);
      break;
      
      case 5:
        vuelta["id"] = id;
        serializeJson(vuelta, msg1);
        enviarMensajePorTopic(TOPIC2, msg1);
      break;
      }
    }
  }*/
}
