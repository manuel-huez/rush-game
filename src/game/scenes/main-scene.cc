#include "main-scene.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include "../../maze/maze.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


namespace Scenes
{

  MainScene::MainScene(sf::RenderWindow& window)
    : Scene::Scene(window)
  {
    E::Object bg(sf::RectangleShape(sf::Vector2f(window.getSize())));
    bg.rectangle_shape_get().setFillColor(E::Color::Dark());
    object_add("0background", bg);

    int mazeSize = 50;
    float tileSize = window.getSize().x / mazeSize;
    RMaze::Maze ma(mazeSize);
    ma.create();
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

  void MainScene::update(sf::RenderWindow& window, sf::Time& dt)
  {
    Scene::update(window, dt);
  }

}
