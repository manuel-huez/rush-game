#include "generator.hh"

#include "room.hh"
#include <vector>

namespace RMaze
{
  void Generator::generate_rooms()
  {
    unsigned number = rand() % 3 + 3;
    std::vector<Room> rooms;
    for (unsigned i = 0; i < number; i++)
    {
      int width = rand() % 10 + 3;
      int height = rand() %10 + 3;
      Room room(width, height, 1);
      rooms.push_back(room);
    }
    rooms_ = rooms;
  }

  void Generator::fill_rooms()
  {
    for (auto i : rooms_)
    {
      for (int j = 0; j < i.width_get(); j++)
      {
        for (int k = 0; k < i.height_get(); k++)
          maze_.set(j, k, i.type_get());
      }
    }
  }
}
