#ifndef GENERATOR_H
# define GENERATOR_H

namespace RMaze
{
  class Maze
  {
    public:
      Generator(World& w)
        : world_(w)
      {}
    private:
      World& world_;
  };
}
#endif
