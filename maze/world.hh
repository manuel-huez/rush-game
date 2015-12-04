#ifndef WORLD_H
# define WORLD_H

# include <vector>
# include "Maze.hh"

namespace RMaze
{
  class World
  {
    public:
      World(unsigned size)
        : size_(size)
      {
        map_(size, std::vector<int>(size));
      }
      
    private:
      unsigned size_;
      Maze& maze_;
  };
}

#endif
