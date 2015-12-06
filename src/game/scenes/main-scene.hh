#pragma once

#include "../../engine/scene.hh"
#include "../../engine/engine.hh"
#include "../objects/player.hh"
#include "../objects/maze.hh"
#include <SFML/Graphics.hpp>
#include <memory>

namespace Scenes
{
    class MainScene : public E::Scene
    {
    public:
        MainScene(E::Engine& engine, sf::RenderWindow& window);
        void handle_events(E::Engine& engine,
                sf::RenderWindow& window, sf::Time& dt);
        void update(E::Engine& engine,
                sf::RenderWindow& window, sf::Time& dt);
    private:
        void add_enemies(sf::RenderWindow& window, RMaze::Room& roomP);
        void add_sentinels(sf::RenderWindow& window, RMaze::Room& roomP);
        void add_bonuses(sf::RenderWindow& window, RMaze::Maze& maze, int nb);
        std::shared_ptr<Objects::Player> player_;
        std::shared_ptr<Objects::MMaze>   maze_;
    };
}
