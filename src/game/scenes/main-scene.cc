#include "main-scene.hh"
#include "../objects/background.hh"
#include "../objects/maze.hh"
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

    auto maze = std::make_shared<Objects::Maze>(*this, window);
    gobject_add("1maze", std::static_pointer_cast<E::GameObject>(maze));
  }

  void MainScene::update(E::Engine& engine,
          sf::RenderWindow& window, sf::Time& dt)
  {
    Scene::update(engine, window, dt);
  }

}
