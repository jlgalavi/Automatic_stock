class box {

  private:

    String ID;
    String pos;
    bool set = false;

  public:

    box(String idbox, String position)
    {
      ID = idbox;
      pos = position;
    }

    box()
    {
      ID = "";
      pos = "(0,0,0)";
    }

    String get_boxID()
    {
      return ID;
    }

    String get_boxpos()
    {
      return pos;
    }

    bool get_setBox()
    {
      return set;
    }

    void set_box()
    {
      set = true;
    }

    void print_box()
    {
      Serial.print("BOX --> ");
      Serial.print(ID);
      Serial.print("; POSE --> ");
      Serial.println(pos);
    }

};