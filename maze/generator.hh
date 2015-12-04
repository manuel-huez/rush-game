#ifndef GENERATOR_H
# define GENERATOR_H

# include "maze.hh"

namespace RMaze
{
  class Generator
  {
    public:
      Generator(Maze& maze)
        : maze_(maze)
      {}

    private:
        Maze& maze_;
  };
}

#endif
