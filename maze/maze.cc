#include "maze.hh"
#include "generator.hh"

namespace RMaze
{
  void Maze::create()
  {
    Generator gen(*this);
    gen.generate_rooms();
    gen.fill_rooms();
  }

  std::ostream& operator<<(std::ostream& str, const Maze& maze)
  {
    for (int x = 0; x < size_; x++)
    {
      for (int y = 0; y < size_; y++)
      {
        str << " " << map_.at(x + size_ * y);
      }
    }
    return str;
  }
}
