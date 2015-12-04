#include "generator.hh"

#include "room.hh"
#include <vector>

namespace RMaze
{
  bool Generator::is_place_available(Room& room) const
  {
    for (int x = room.x_get() - 1; x <= room.x_get() + room.width_get(); x++)
    {
      for (int y = room.y_get() - 1; y <= room.y_get() + room.height_get(); y++)
      {
        unsigned xx = x;
        unsigned yy = y;
        if (x < 0 || xx >= maze_.size_get()
            || y < 0 || yy >= maze_.size_get())
          continue;
        if (maze_.get(x, y) != 0)
          return false;
      }
    }
    return true;
  }
  void Generator::generate_rooms()
  {
    unsigned number = rand() % 3 + 3;
    std::vector<Room> rooms;
    for (unsigned i = 0; i < number; i++)
    {
      int width = rand() % 10 + 3;
      int height = rand() % 10 + 3;
      int x = rand() % (maze_.size_get() - width - 1) + 1;
      int y = rand() % (maze_.size_get() - height - 1) + 1;
      Room room(width, height, x, y, 1);
      if (is_place_available(room))
      {
        rooms.push_back(room);
        fill_room(room);
      }
      else
        i--;
    }
    rooms_ = rooms;
  }

  void Generator::fill_room(Room& room)
  {
    for (int j = room.x_get(); j < room.x_get() + room.width_get(); j++)
    {
      for (int k = room.y_get(); k < room.y_get() + room.height_get(); k++)
        maze_.set(j, k, room.type_get());
    }
  }
}
