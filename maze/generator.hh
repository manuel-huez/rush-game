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
      void fill_rooms();
    private:
      Maze& maze_;
      std::vector<Room> rooms_;
  };
}

#endif
