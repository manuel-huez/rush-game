#pragma once

#include <SFML/Graphics.hpp>

namespace E
{
    class Color
    {
    public:
        static sf::Color& Orange();
        static sf::Color& Red();
        static sf::Color& Blue();
        static sf::Color& LightBlue();
        static sf::Color& Dark();
        static sf::Color& White();
        static sf::Color& Grey();
    };
}
