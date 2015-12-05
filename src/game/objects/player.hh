#pragma once

#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include <SFML/Graphics.hpp>

namespace Objects
{
    class Player : public E::GameObject
    {
    public:
        Player(E::Scene& scene, sf::RenderWindow& window, float size);
        void update(E::Scene& scene, sf::RenderWindow& window, sf::Time& dt);

        sf::Vector2f position_get();
        void position_set(sf::Vector2f pos);
    private:
        float size_;
        sf::Vector2f pos_;
    };
}
