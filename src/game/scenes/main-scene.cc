#include "main-scene.hh"
#include "../objects/background.hh"
#include "../objects/maze.hh"
#include "../../engine/scene.hh"
#include "../../engine/engine.hh"
#include "../../engine/game-object.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


namespace Scenes
{

  MainScene::MainScene(E::Engine& engine, sf::RenderWindow& window)
    : Scene::Scene(engine, window)
  {
    E::GameObject bg = Objects::Background(*this, window);
    gobject_add("0background", bg);

    E::GameObject maze = Objects::Maze(*this, window);
    gobject_add("1maze", maze);
  }

  void MainScene::update(E::Engine& engine,
          sf::RenderWindow& window, sf::Time& dt)
  {
    Scene::update(engine, window, dt);
  }

}
