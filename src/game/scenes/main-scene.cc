#include "main-scene.hh"
#include "../../engine/scene.hh"
#include "../../engine/engine.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include "../../maze/maze.hh"
#include "../../maze/world.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


namespace Scenes
{

  MainScene::MainScene(E::Engine& engine, sf::RenderWindow& window)
    : Scene::Scene(engine, window)
  {
    E::Object bg(sf::RectangleShape(sf::Vector2f(window.getSize())));
    bg.rectangle_shape_get().setFillColor(E::Color::Dark());
    object_add("0background", bg);

    RMaze::World world(50, 4, 0.4f);
    int mazeSize = 50;
    RMaze::Maze& ma = world.get_maze();
    float tileSize = window.getSize().x / mazeSize;

    for (unsigned x = 0; x < ma.size_get(); x++)
    {
      for (unsigned y = 0; y < ma.size_get(); y++)
      {
        if (ma.get(x, y) != 0)
        {
          E::Object o2(sf::RectangleShape({tileSize, tileSize}));
          switch (ma.get(x, y))
          {
            case 1:
              o2.rectangle_shape_get().setFillColor(E::Color::Grey());
              break;
            case 2:
              o2.rectangle_shape_get().setFillColor(E::Color::White());
              break;
            case 3:
              o2.rectangle_shape_get().setFillColor(E::Color::White());
              break;
            default:
              o2.rectangle_shape_get().setFillColor(E::Color::Grey());
              break;
          }
          o2.rectangle_shape_get().setPosition({x * tileSize, y * tileSize});
          std::string name = "1" + std::to_string(x + ma.size_get() * y);
          object_add(name, o2);
        }
      }
    }
  }

  void MainScene::update(E::Engine& engine,
          sf::RenderWindow& window, sf::Time& dt)
  {
    Scene::update(engine, window, dt);
  }

}
