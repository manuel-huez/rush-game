#ifndef MAZE_H
# define MAZE_H

# include "generator.hh"
# include <vector>
# include <iostream>

namespace RMaze
{
  class Maze
  {
    public:
      Generator(unsigned size)
        : size_(size)
      {
        map_ = std::vector<int>(size_ * size_);
      }
      void create();
      std::ostream& operator<<(std::ostream& str, const Maze& maze);
    private:
      unsigned size_;
      std::vector<int>& map_;
  };
}

# include "maze.hxx"

#endif
