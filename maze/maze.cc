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
  std::ostream& operator<<(std::ostream& str, const Maze& ma)
  {
    unsigned size = ma.size_get();
    for (unsigned x = 0; x < size; x++)
    {
      for (unsigned y = 0; y < size; y++)
      {
        str << " " << ma.map_get().at(x + size * y);
      }
      std::cout << std::endl;
    }
    return str;
  }
}
