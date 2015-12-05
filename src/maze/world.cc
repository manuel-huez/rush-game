#include "world.hh"

namespace RMaze
{
  Maze& World::get_maze()
  {
    return *maze_;
  }
}
