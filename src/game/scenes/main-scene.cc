#include "main-scene.hh"
#include "menu-scene.hh"
#include "retry-menu-scene.hh"
#include "../objects/background.hh"
#include "../objects/maze.hh"
#include "../objects/enemy.hh"
#include "../objects/sentinel.hh"
#include "../objects/player.hh"
#include "../objects/bonus.hh"
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
    auto roomP  = ma.get_rooms().at(rand() % ma.get_rooms().size());

    add_enemies(window, roomP);
    add_sentinels(window, roomP);
    add_bonuses(window, maze_->get_maze(), maze_->get_tile_size(), 15);

    sf::Vector2f s((roomP.x_get() + roomP.width_get() / 2)
                * maze_->get_tile_size(),
            (roomP.y_get() + roomP.height_get() / 2) * maze_->get_tile_size());
    player_ = std::make_shared<Objects::Player>(*this, window, 5, s);
    gobject_add("2player", std::static_pointer_cast<E::GameObject>(player_));
  }

  void MainScene::handle_events(E::Engine& engine,
      sf::RenderWindow& window, sf::Time& dt)
  {
    Scene::handle_events(engine, window, dt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        auto s = std::make_shared<Scenes::MenuScene>(engine, window);
        engine.scene_set(std::static_pointer_cast<E::Scene>(s));
        return;
    }

    auto pos    = (*player_).position_get();
    float speed = 5 * maze_->get_tile_size();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      pos.y -= speed * dt.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      pos.y += speed * dt.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      pos.x += speed * dt.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      pos.x -= speed * dt.asSeconds();

    (*player_).position_set(pos);
    if ((*maze_).intersects(player_->circle_get("1point")))
    {
        auto s = std::make_shared<Scenes::RetryMenuScene>(engine, window);
        engine.scene_set(std::static_pointer_cast<E::Scene>(s));
        return;
    }
  }

  void MainScene::update(E::Engine& engine,
      sf::RenderWindow& window, sf::Time& dt)
  {
    Scene::update(engine, window, dt);
  }

  void MainScene::add_enemies(sf::RenderWindow& window,
      RMaze::Room& roomP)
  {
    auto ma = maze_->get_maze();
    for (int i = 0; i < 15; i++)
    {
      int size = ma.size_get();

      auto room  = ma.get_rooms().at(rand() % ma.get_rooms().size());
      auto room2 = ma.get_rooms().at(rand() % ma.get_rooms().size());
      while (room2 == room || room == roomP || room2 == roomP)
      {
        room  = ma.get_rooms().at(rand() % ma.get_rooms().size());
        room2 = ma.get_rooms().at(rand() % ma.get_rooms().size());
      }

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
  }
  void MainScene::add_sentinels(sf::RenderWindow& window,
      RMaze::Room& roomP)
  {
    auto ma = maze_->get_maze();
    for (int i = 0; i < 4; i++)
    {
      int size = ma.size_get();

      auto room  = ma.get_rooms().at(rand() % ma.get_rooms().size());
      auto room2 = ma.get_rooms().at(rand() % ma.get_rooms().size());
      while (room2 == room || room == roomP || room2 == roomP)
      {
        room  = ma.get_rooms().at(rand() % ma.get_rooms().size());
        room2 = ma.get_rooms().at(rand() % ma.get_rooms().size());
      }

      int x  = room.x_get()  + room.width_get()   / 2;
      int y  = room.y_get()  + room.height_get()  / 2;

      auto anmy = std::make_shared<EN::Sentinel>(*this, window, x, y, 1,
          "2Sentinel", maze_->get_tile_size(), size);

      gobject_add("2Sentinel" + i,
          std::static_pointer_cast<E::GameObject>(anmy));
    }
  }

  void MainScene::add_bonuses(sf::RenderWindow& window, RMaze::Maze& maze,
      float tile_size, int nb)
  {
    for (int i = 0; i < nb; i++)
    {
      float x = 0;
      float y = 0;
      do {
        x = rand() % maze.size_get();
        y = rand() % maze.size_get();
      }  while (maze.get(x, y) == 100);
      int bonus = rand() % 5 + 12;
      int size = bonus * (window.getSize().y / tile_size) / 50;
      auto b = std::make_shared<B::Bonus>(*this, window, size, size,
          x * tile_size, y * tile_size);
      b->set_bonus(bonus);

      gobject_add("2Bonus" + i, std::static_pointer_cast<E::GameObject>(b));
    }
  }

}
