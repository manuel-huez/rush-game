#ifndef WORLD_H
# define WORLD_H

#include <vector>

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
      std::vector<std::vector<int>> map_;
  };
}

#endif
