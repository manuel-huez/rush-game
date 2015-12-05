#pragma once

#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../maze/maze.hh"

namespace Objects
{
  class MMaze : public E::GameObject
  {
    public:
      MMaze(E::Scene& scene, sf::RenderWindow& window);
      RMaze::Maze& get_maze();
      int get_tile_size() const;
    private:
      RMaze::Maze maze_;
      int tileSize_;
  };
}
