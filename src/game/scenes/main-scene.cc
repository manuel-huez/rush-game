#include "main-scene.hh"
#include "../objects/background.hh"
#include "../objects/maze.hh"
#include "../objects/player.hh"
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

        maze_ = std::make_shared<Objects::Maze>(*this, window);
        gobject_add("1maze", std::static_pointer_cast<E::GameObject>(maze_));

        player_ = std::make_shared<Objects::Player>(*this, window, 10);
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
