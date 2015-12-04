#include "maze.hh"
#include <iostream>

int main()
{
  srand(time(NULL));
  RMaze::Maze ma(50);
  ma.create();
  std::cout << ma << std::endl;
  return 0;
}
