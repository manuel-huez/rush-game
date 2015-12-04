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
      void generate_rooms();
      void fill_room(Room& room);
    private:
      bool is_place_available(Room& room) const; 
      Maze& maze_;
      std::vector<Room> rooms_;
  };
}

#endif