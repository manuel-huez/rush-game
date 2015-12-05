#include "maze.hh"
#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "enemy.hh"
#include "maze.hh"
#include "../../engine/color.hh"
#include "../../maze/maze.hh"
#include "../../maze/world.hh"
#include <SFML/Graphics.hpp>

namespace Objects
{
  MMaze::MMaze(E::Scene& scene, sf::RenderWindow& window)
    : GameObject(scene, window)
    , maze_(RMaze::World(50, 7, 0.35f).get_maze())
  {
    int mazeSize = 50;
    float tileSize  = window.getSize().x / mazeSize;
    tileSize_ = tileSize;
    for (unsigned x = 0; x < maze_.size_get(); x++)
    {
      for (unsigned y = 0; y < maze_.size_get(); y++)
      {
        if (maze_.get(x, y) != 0)
        {
          E::Object o(sf::RectangleShape({tileSize, tileSize}));
          bool collision = false;
          switch (maze_.get(x, y))
          {
            case 1:
              o.rectangle_shape_get().setFillColor(
                  E::Color::Grey());
              break;
            case 2:
              o.rectangle_shape_get().setFillColor(
                  E::Color::White());
              break;
            default:
              o.rectangle_shape_get().setFillColor(
                  E::Color::Dark());
              collision = true;
              break;
          }

          o.rectangle_shape_get().setPosition({x * tileSize,
              y * tileSize});
          std::string name = "0" + std::to_string(x
              + maze_.size_get() * y);
          object_add(name, o, collision);
        }
      }
    }

  }

  int MMaze::get_tile_size() const
  {
    return tileSize_;
  }

  RMaze::Maze& MMaze::get_maze()
  {
    return maze_;
  }

}
