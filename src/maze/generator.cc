#include "generator.hh"

#include "room.hh"
#include <vector>
#include <cmath>

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
        if (maze_.get(x, y) != 100)
          return false;
      }
    }
    return true;
  }

  float Generator::calculate_density(Room& room) const
  {
    for (int x = room.x_get(); x < room.x_get() + room.width_get(); x++)
    {
      for (int y = room.y_get(); y < room.y_get() + room.height_get(); y++)
      {
        if (maze_.get(x, y) == 2)
          maze_.density++;
      }
    }
    return maze_.density / (maze_.size_get() * maze_.size_get());
  }

  void Generator::generate_rooms(int stretch, float density)
  {
    std::vector<Room>& rooms = maze_.get_rooms();
    while (true)
    {
      stretch = stretch;
      int width = rand() % (stretch + stretch / 2) + (stretch - stretch / 2);
      int height = rand() % (stretch + stretch / 2) + (stretch - stretch / 2);
      int x = rand() % (maze_.size_get() - width - 2) + 2;
      int y = rand() % (maze_.size_get() - height - 2) + 2;
      Room room(width, height, x, y, 2);
      if (is_place_available(room))
      {
        rooms.push_back(room);
        fill_room(room);
        if (maze_.get_rooms().size() > 1 && calculate_density(room) > density)
          break;
      }
    }
  }

  void Generator::fill_room(Room& room)
  {
    for (int j = room.x_get(); j < room.x_get() + room.width_get(); j++)
    {
      for (int k = room.y_get(); k < room.y_get() + room.height_get(); k++)
        maze_.set(j, k, room.type_get());
    }
  }

  int Generator::find_closest_notlinked(Room& room) const
  {
    int closest = 0;
    int distance = 10000;
    int x = room.x_get();
    int y = room.y_get();
    for (unsigned i = 0; i < maze_.get_rooms().size(); i++)
    {
      if (maze_.get_rooms().at(i).x_get() != x
          && maze_.get_rooms().at(i).y_get() != y)
      {
        int d = std::sqrt(std::pow(maze_.get_rooms().at(i).x_get() - x, 2)
            + pow(maze_.get_rooms().at(i).y_get() - y, 2));

        if (d < distance && maze_.get_rooms().at(i).linked == false)
        {
          distance = d;
          closest = i;
        }
      }
    }
    return closest;
  }

  void Generator::link_rooms(Room& a, Room& b)
  {
    int ax = a.x_get();
    int ay = a.y_get();
    int bx = b.x_get();
    int by = b.y_get();
    int ax1 = a.x_get();
    int ay1 = a.y_get();
    int bx1 = b.x_get();
    int by1 = b.y_get();

    if (ax < bx)
    {
      if (ay < by)
      {
        while (ay1 < by1)
        {
          ay1++;
          maze_.set(ax1, ay1, 1);
          maze_.set(ax1 + 1, ay1, 1);
          maze_.set(ax1 - 1, ay1, 1);
        }
        while (ax1 < bx1)
        {
          ax1++;
          maze_.set(ax1, ay1, 1);
          maze_.set(ax1, ay1 + 1, 1);
          maze_.set(ax1, ay1 - 1, 1);
        }
      }
      else
      {
        while (ay1 > by1)
        {
          ay1--;
          maze_.set(ax1, ay1, 1);
          maze_.set(ax1 + 1, ay1, 1);
          maze_.set(ax1 - 1, ay1, 1);
        }
        while (ax1 < bx1)
        {
          ax1++;
          maze_.set(ax1, ay1, 1);
          maze_.set(ax1, ay1 + 1, 1);
          maze_.set(ax1, ay1 - 1, 1);
        }

      }
    }
    else
    {
      if (ay < by)
      {
        while (ay1 < by1)
        {
          ay1++;
          maze_.set(ax1, ay1, 1);
          maze_.set(ax1 + 1, ay1, 1);
          maze_.set(ax1 - 1, ay1, 1);
        }
        while (ax1 > bx1)
        {
          ax1--;
          maze_.set(ax1, ay1, 1);
          maze_.set(ax1, ay1 + 1, 1);
          maze_.set(ax1, ay1 + 1, 1);
        }
      }
      else
      {
        while (ay1 > by1)
        {
          ay1--;
          maze_.set(ax1, ay1, 1);
          maze_.set(ax1 + 1, ay1, 1);
          maze_.set(ax1 - 1, ay1, 1);
        }
        while (ax1 > bx1)
        {
          ax1--;
          maze_.set(ax1, ay1, 1);
          maze_.set(ax1, ay1 + 1, 1);
          maze_.set(ax1, ay1 - 1, 1);
        }

      }

    }
  }

  void Generator::link()
  {
    Room room = maze_.get_rooms().at(rand() % maze_.get_rooms().size());
    for (unsigned i = 0; i < maze_.get_rooms().size(); i++)
    {
      Room& closest = maze_.get_rooms().at(find_closest_notlinked(room));
      closest.linked = true;
      link_rooms(room, closest);
      room = closest;
    }
  }

}
