#ifndef GENERATOR_H
# define GENERATOR_H

# include "maze.hh"
# include "room.hh"
# include <vector>

namespace RMaze
{

  class Generator
  {
    public:
      Generator(Maze& maze)
        : maze_(maze)
      {}
      void generate_rooms(int stretch, float density);
      void fill_room(Room& room);
      float calculate_density(Room& room) const;
      void link();
    private:
      bool is_place_available(Room& room) const;
      int find_closest_notlinked(Room& room) const;
      void link_rooms(Room& a, Room& b);
      Maze& maze_;
      std::vector<Room> rooms_;
  };
}

#endif
