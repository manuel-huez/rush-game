#ifndef MAZE_H
# define MAZE_H

# include <vector>
# include <iostream>

namespace RMaze
{
  class Maze
  {
    public:
      Maze(unsigned size)
        : size_(size)
      {
        map_ = std::vector<int>(size_ * size_);
      }
      void create();
      const std::vector<int>& map_get() const;
      std::vector<int>& map_get();
      void set(int x, int y, int type);
      int get(int x, int y) const;
      unsigned size_get() const;
    private:
      unsigned size_;
      std::vector<int> map_;
  };

  std::ostream& operator<<(std::ostream& str, const Maze& ma);
}

#endif
