#include "room.hh"
namespace RMaze
{
  int Room::width_get() const
  {
    return width_;
  }

  int Room::height_get() const
  {
    return height_;
  }

  int Room::type_get() const
  {
    return type_;
  }

  int Room::x_get() const
  {
    return posX_;
  }

  int Room::y_get() const
  {
    return posY_;
  }
}
