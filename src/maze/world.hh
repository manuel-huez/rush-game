#ifndef WORLD_H
# define WORLD_H

# include <vector>
# include "maze.hh"
# include <memory>
namespace RMaze
{
  class World
  {
    public:
      World(unsigned size, int stretch, float density)
        : size_(size)
      {
        maze_ = std::make_shared<Maze>(50);
        maze_->create(stretch, density);
      }
      Maze& get_maze();
    private:
      unsigned size_;
      std::shared_ptr<Maze> maze_;
  };
}

#endif
