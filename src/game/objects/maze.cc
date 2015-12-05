#include "maze.hh"
#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include "../../maze/maze.hh"
#include "../../maze/world.hh"
#include <SFML/Graphics.hpp>

namespace Objects
{
  Maze::Maze(E::Scene& scene, sf::RenderWindow& window)
    : GameObject(scene, window)
  {
    RMaze::World world(50, 7, 0.35f);
    int mazeSize = 50;
    RMaze::Maze& ma = world.get_maze();
    float tileSize  = window.getSize().x / mazeSize;
    for (unsigned x = 0; x < ma.size_get(); x++)
    {
      for (unsigned y = 0; y < ma.size_get(); y++)
      {
        if (ma.get(x, y) != 0)
        {
          E::Object o(sf::RectangleShape({tileSize, tileSize}));
          switch (ma.get(x, y))
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
              break;
          }

          o.rectangle_shape_get().setPosition({x * tileSize,
              y * tileSize});
          std::string name = "0" + std::to_string(x
              + ma.size_get() * y);
          object_add(name, o);
        }
      }
    }
  }
}
