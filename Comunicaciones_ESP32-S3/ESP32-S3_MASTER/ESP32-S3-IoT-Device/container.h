class container : public box{

  private:

    int nboxes;
    String ID;
    box* boxes;

  public:

    container(int nbox, String idcontainer)
    {
      nboxes = nbox;
      ID = idcontainer;
      boxes = new box[nbox];
    } 
};