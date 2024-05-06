class order : public container{

  private:

    int index = 0;
    const char* ID;
    container* containers;

  public:

    order(int ncont, const char* idorder)
    {
      ID = idorder;
      containers = new container[ncont];
    }

    void add_container(container c_add)
    {
      containers[index] = c_add;
      index++;
    }

    const char* get_orderID()
    {
      return ID;
    }

    container* get_containers()
    {
      return containers;
    }

    void print_order()
    {
      Serial.print("ORDER --> ");
      Serial.println(ID);
      for(int i = 0; i < index; i++)
      {
        containers[i].print_container();
      }
    }
};