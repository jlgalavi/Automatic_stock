#include "container.h"

class order : public container {

private:

  const char* ID;
  int ncontainers;
  container* containers;

public:

  order(int ncont, const char* idorder) {
    ID = idorder;
    ncontainers = ncont;
    containers = new container[ncont];
  }

  order() {
    ID = "";
  }

  void add_container(container c_add) {
    for (int i = 0; i < ncontainers; i++) {
      if (containers[i].get_containerID() == "") {
        containers[i] = c_add;
        i = ncontainers;
      }
    }
  }

  const char* get_orderID() {
    return ID;
  }

  container get_container(const char* idcontainer) {
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
    for (int i = 0; i < ncontainers; i++) {
      containers[i].print_container();
    }
  }
};