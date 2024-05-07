#include "box.h"

class container : public box {

private:

  const char* ID;
  box* boxes;
  int nboxes;
  int index = 0;

public:

  container(int nbox, const char* idcontainer) {
    ID = idcontainer;
    nboxes = nbox;
    boxes = new box[nbox];
  }

  container() {
    ID = "";
  }

  void add_box(box b_add) {
    if (index < nboxes) {
      boxes[index] = b_add;
      index++;
    } else {
      Serial.println("ERROR | MAX BOXES");
    }
  }

  const char* get_containerID() {
    return ID;
  }

  box* get_boxes() {
    return boxes;
  }

  int get_containerSize() {
    return nboxes;
  }

  void set_boxes(box* newBoxes) {
    boxes = newBoxes;
  }

  void print_container() {
    Serial.print("CONTAINER --> ");
    Serial.println(ID);
    if (ID != "") {
      for (int i = 0; i < nboxes; i++) {
        boxes[i].print_box();
      }
    }
  }
};