#pragma once

#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include <SFML/Graphics.hpp>

extern int score_g;
extern int best_score_g;

namespace Objects
{
    class RetryMenu : public E::GameObject
    {
    public:
        RetryMenu(E::Scene& scene, sf::RenderWindow& window);
    };
}
