#include "main-scene.hh"
#include "../objects/background.hh"
#include "../objects/maze.hh"
#include "../objects/enemy.hh"
#include "../../engine/scene.hh"
#include "../../engine/engine.hh"
#include "../../engine/game-object.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <memory>


namespace Scenes
{

  MainScene::MainScene(E::Engine& engine, sf::RenderWindow& window)
    : Scene::Scene(engine, window)
  {
    auto bg = std::make_shared<Objects::Background>(*this, window);
    gobject_add("0background", std::static_pointer_cast<E::GameObject>(bg));

    auto maze = std::make_shared<Objects::MMaze>(*this, window);

    gobject_add("1maze", std::static_pointer_cast<E::GameObject>(maze));

    auto ma = maze->get_maze();
    for (int i = 0; i < 5; i++)
    {
      auto room = ma.get_rooms().at(rand() % ma.get_rooms().size());
      auto anmy = std::make_shared<Char::Enemy>(*this, window,
          room.x_get() + room.width_get() / 2, 
          room.y_get() + room.height_get() / 2, 1,
          "2Ennemy", maze->get_tile_size());
      gobject_add("2Enemy" + i, std::static_pointer_cast<E::GameObject>(anmy));
    }
  }

  void MainScene::update(E::Engine& engine,
      sf::RenderWindow& window, sf::Time& dt)
  {
    Scene::update(engine, window, dt);
  }

}
