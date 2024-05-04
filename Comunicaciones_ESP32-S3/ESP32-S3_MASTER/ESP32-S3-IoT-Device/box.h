class box : public target{

  private:

    char ID;
    target pos;

  public:

    box(char idbox, target position)
    {
      ID = idbox;
      pos = position;
    }

}