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
};