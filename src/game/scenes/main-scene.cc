#include "main-scene.hh"
#include "../objects/background.hh"
#include "../objects/maze.hh"
#include "../objects/enemy.hh"
#include "../objects/player.hh"
#include "../../engine/scene.hh"
#include "../../engine/engine.hh"
#include "../../engine/game-object.hh"
#include "../../pathfinding/path.hh"
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

    maze_ = std::make_shared<Objects::MMaze>(*this, window);
    gobject_add("1maze", std::static_pointer_cast<E::GameObject>(maze_));

    auto ma = maze_->get_maze();
    for (int i = 0; i < 20; i++)
    {
      int size = ma.size_get();

      auto room  = ma.get_rooms().at(rand() % ma.get_rooms().size());
      auto room2 = ma.get_rooms().at(rand() % ma.get_rooms().size());
      while (room2.x_get() == room.x_get()
          && room2.y_get() == room.y_get())
        room2 = ma.get_rooms().at(rand() % ma.get_rooms().size());

      int x  = room.x_get()  + room.width_get()   / 2;
      int y  = room.y_get()  + room.height_get()  / 2;
      int x2 = room2.x_get() + room2.width_get()  / 2;
      int y2 = room2.y_get() + room2.height_get() / 2;

      auto pa = PATH::Path(ma.map_get(), x + size *y, size);
      pa.find_path();

      auto anmy = std::make_shared<Char::Enemy>(*this, window, x, y, 1,
          "2Ennemy", maze_->get_tile_size(), pa.get_path(x2, y2), size,
          (rand() % 8 + 12.f) / 10);

      gobject_add("2Enemy" + i, std::static_pointer_cast<E::GameObject>(anmy));
    }

    sf::Vector2f s(10, 10);
    player_ = std::make_shared<Objects::Player>(*this, window, 5, s);

    gobject_add("2player", std::static_pointer_cast<E::GameObject>(player_));
  }

  void MainScene::handle_events(E::Engine& engine,
      sf::RenderWindow& window, sf::Time& dt)
  {
    Scene::handle_events(engine, window, dt);

    (*player_).position_set(sf::Vector2f(sf::Mouse::getPosition(window)));
  }

  void MainScene::update(E::Engine& engine,
      sf::RenderWindow& window, sf::Time& dt)
  {
    Scene::update(engine, window, dt);
  }

}
