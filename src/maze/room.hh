#ifndef ROOM_H
# define ROOM_H



namespace RMaze
{
  class Room
  {
    public:
      Room(int width, int height, int x, int y, int type)
        : width_(width)
        , height_(height)
        , posX_(x)
        , posY_(y)
        , type_(type)
      {
        linked = false;
      }
      int width_get() const;
      int height_get() const;
      int type_get() const;
      int x_get() const;
      int y_get() const;
      bool linked;
    private:
      int width_;
      int height_;
      int posX_;
      int posY_;
      int type_;
  };

  bool operator==(const Room& room, const Room& room2) ;
}

#endif
