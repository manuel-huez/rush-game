#ifndef MAZE_H
# define MAZE_H

# include <vector>
# include <iostream>
# include <memory>
# include "room.hh"

namespace RMaze
{
  class Maze
  {
    public:
      Maze()
        : size_(0)
      {}
      Maze(const unsigned size)
        : size_(size)
      {
        map_ = std::vector<int>(size_ * size_, 100);
      }
      void create(int stretch, float density);
      const std::vector<int>& map_get() const;
      std::vector<int>& map_get();
      void set(int x, int y, int type);
      int get(int x, int y) const;
      unsigned size_get() const;
      float density;
      std::vector<Room>& get_rooms();
    private:
      const unsigned size_;
      std::vector<int> map_;
      std::vector<Room> rooms_;
  };

  std::ostream& operator<<(std::ostream& str, const Maze& ma);
}

#endif
