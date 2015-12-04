#include "maze.hh"
#include "generator.hh"

namespace RMaze
{
  void Maze::create()
  {
    Generator gen(*this);
    gen.generate_rooms();
  }

  const std::vector<int>& Maze::map_get() const
  {
    return map_;
  }
  std::vector<int>& Maze::map_get() 
  {
    return map_;
  }
  
  unsigned Maze::size_get() const
  {
    return size_;
  }
  
  void Maze::set(int x, int y, int type)
  {
    map_.at(x + size_ * y) = type;
  }

  int Maze::get(int x, int y) const
  {
    return map_.at(x + size_ * y);
  }
  std::ostream& operator<<(std::ostream& str, const Maze& ma)
  {
    unsigned size = ma.size_get();
    for (unsigned y = 0; y < size; y++)
    {
      for (unsigned x = 0; x < size; x++)
      {
        str << " " << (ma.map_get().at(x + size * y) ? "O" : ".");
      }
      std::cout << std::endl;
    }
    return str;
  }
}
