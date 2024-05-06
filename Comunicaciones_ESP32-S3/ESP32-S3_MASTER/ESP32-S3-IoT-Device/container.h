class container : public box{

  private:

    int index = 0;
    const char* ID;
    box* boxes;

  public:

    container(int nbox, const char* idcontainer)
    {
      ID = idcontainer;
      boxes = new box[nbox];
    } 

    container()
    {
      ID = "";
    }

    void add_box(box b_add)
    {
      boxes[index] = b_add;
      index++;
    }

    const char* get_containerID()
    {
      return ID;
    }

    box* get_boxes()
    {
      return boxes;
    }

    void print_container()
    {
      Serial.print("CONTAINER --> ");
      Serial.println(ID);
      for(int i = 0; i < index; i++)
      {
        boxes[i].print_box();
      }

    }
};