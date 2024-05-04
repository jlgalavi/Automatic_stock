class box : public target{

  private:

    const char* ID;
    target pos;

  public:

    box(const char* idbox, target position)
    {
      ID = idbox;
      pos = position;
    }

    box()
    {
      ID = "";
      pos = target(0,0,0);
    }

    const char* get_boxID()
    {
      return ID;
    }

    target get_boxpos()
    {
      return pos;
    }

};