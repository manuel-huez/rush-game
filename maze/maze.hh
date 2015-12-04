#ifndef MAZE_H
# define MAZE_H

namespace RMaze
{
  class Maze
  {
    public:
      Generator()
      {}
    private:
      unsigned size_;
      std::vector<std::vector<int>> map_;
  };
}
#endif
