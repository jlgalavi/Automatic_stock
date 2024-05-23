#include <iostream>
#include <fstream>
#include <vector>
#include "box.h"
#include "target.h"
#include "container.h"
#include "shipment.h"
#include <ArduinoJson.h>

// Constructor base del envío
// Base constructor of the shipment
shipment::shipment() {
  V_boxes = {};
  V_containers = {};
  V_targets = {};
}
// Constructor del envío con parámetros
// Constructor of the shipment with parameters
shipment::shipment(std::vector<box> V, std::vector<container> C, std::vector<target> T) {
  V_boxes = V;
  V_containers = C;
  V_targets = T;
}
// Mostrar el envío
// Show the shipment
void shipment::show_shipment() {
  std::cout << std::endl
            << "Welcome to the box shipment system" << std::endl;
  std::cout << "This is the resume of your shipment" << std::endl;
  std::cout << std::endl
            << "--------------------------" << std::endl;
  std::cout << "  Number of containers: " << V_containers.size() << std::endl;
  std::cout << "  Number of boxes: " << V_boxes.size() << std::endl;
  for (int i = 0; i < V_containers.size(); i++) {
    std::cout << std::endl
              << "  Container " << i + 1 << std::endl;
    std::cout << "  Volume of boxes: " << V_containers[i].add_volume_boxes() << std::endl;
    V_containers[i].show_container();
  }
  std::cout << "--------------------------" << std::endl;
}

void shipment::save_shipment(std::string output) {
  int index = 0;
  StaticJsonDocument<2000> doc;

  doc["ID_PEDIDO"] = "order_id";
  doc["N_CONT"] = V_containers.size();

  JsonArray json_containers = doc.createNestedArray("CONTAINER");

  for (int i = 0; i < V_containers.size(); i++) {
    JsonObject json_container = json_containers.createNestedObject();
    json_container["ID_CONT"] = "container_id";
    json_container["N_BOX"] = V_containers[i].get_num_boxes();

    JsonArray json_boxes = json_container.createNestedArray("BOXES");

    for (int j = 0; j < V_containers[i].get_num_boxes(); j++) {
      JsonObject json_box = json_boxes.createNestedObject();
      json_box["ID_BOX"] = V_boxes[j + index].get_id();
      json_box["POSE"] = "(" + std::to_string(V_targets[j + index].get_position_x()) +  ", " + std::to_string(V_targets[j + index].get_position_y()) + ", " + std::to_string(V_targets[j + index].get_position_z()) + ")";
    }
  }

  serializeJson(doc, output);

}
// Obtener el número de contenedores
// Get the number of containers
int shipment::get_num_containers() {
  return V_containers.size();
}
// Obtener el número de cajas
// Get the number of boxes
int shipment::get_num_boxes() {
  return V_boxes.size();
}