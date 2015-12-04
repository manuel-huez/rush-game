#ifndef ROOM_H
# define ROOM_H



namespace RMaze
{
  class Room
  {
    public:
      Room(int width, int height, int type)
        : width_(width)
        , height_(height)
        , type_(type)
      {}
      int width_get() const;
      int height_get() const;
      int type_get() const;
      int x_get() const;
      int y_get() const;
    private:
      int posX_;
      int posY_;
      int width_;
      int height_;
      int type_;
  };
}

#endif
