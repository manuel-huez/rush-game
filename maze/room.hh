#ifndef ROOM_H
# define ROOM_H



template RMaze
{
  class Room
  {
    public:
      Room(int width, int height, int type)
        : width_(width)
        , height_(height)
        , type_(type)
      {}
      int width_get();
      int height_get();
      int type_get();
    private:
      int width_;
      int height_;
      int type_;
  };
}

#endif
