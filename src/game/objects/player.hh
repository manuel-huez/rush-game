#pragma once

#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../engine/color.hh"
#include <SFML/Graphics.hpp>

namespace Objects
{
    class Player : public E::GameObject
    {
    public:
        Player(E::Scene& scene, sf::RenderWindow& window, float size,
                sf::Vector2f pos);
        void update(E::Scene& scene, sf::RenderWindow& window, sf::Time& dt);

        sf::Vector2f position_get();
        void position_set(sf::Vector2f pos);
    private:
        float size_;
        sf::Vector2f pos_;
        sf::Vector2f last_pos_;
        float animation_cur_;
        float animation_duration_;
        float animation_distance_;
    };
}
