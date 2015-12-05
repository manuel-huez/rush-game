#pragma once

#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"

namespace Objects
{
    class Maze : public E::GameObject
    {
    public:
        Maze(E::Scene& scene, sf::RenderWindow& window);
    };
}
