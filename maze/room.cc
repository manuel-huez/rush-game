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
}
