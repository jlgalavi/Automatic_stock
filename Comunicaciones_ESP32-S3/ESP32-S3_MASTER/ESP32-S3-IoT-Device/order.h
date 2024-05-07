#include "container.h"

class order : public container {

private:

  String ID;
  int ncontainers;
  container* containers;

public:

  order(int ncont, String idorder) {
    ID = idorder;
    ncontainers = ncont;
    containers = new container[ncont];
  }

  order() {
    ID = "";
  }

  void add_container(container c_add) {
    for (int i = 0; i < ncontainers; i++) {
      if (!(containers[i].get_setContainer())) {
        containers[i] = c_add;
        containers[i].set_container();
        i = ncontainers;   
      }
    }
  }

  String get_orderID() {
    return ID;
  }

  container get_container(String idcontainer) {
    for (int i = 0; i < ncontainers; i++) {
      if (containers[i].get_containerID() == idcontainer) {
        return containers[i];
      }
    }
    Serial.println("CONTAINER NOT FOUNDED");
  }

  container* get_containers() {
    return containers;
  }

  int get_Size() {
    return ncontainers;
  }

  void set_containers(container* newContainers) {
    containers = newContainers;
  }

  void print_order() {
    Serial.print("ORDER --> ");
    Serial.println(ID);
    Serial.print("Nº Containers --> ");
    Serial.println(ncontainers);
    for (int i = 0; i < ncontainers; i++) {
      containers[i].print_container();
    }
  }
};