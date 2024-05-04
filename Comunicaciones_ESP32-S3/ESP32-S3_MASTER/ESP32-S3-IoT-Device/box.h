class box {

  private:

    const char* ID;
    const char* pos;

  public:

    box(const char* idbox, const char* position)
    {
      ID = idbox;
      pos = position;
    }

    box()
    {
      ID = "";
      pos = "(0,0,0)";
    }

    const char* get_boxID()
    {
      return ID;
    }

    const char* get_boxpos()
    {
      return pos;
    }

};