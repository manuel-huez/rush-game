#include "color.hh"
#include <SFML/Graphics.hpp>

namespace E
{
    sf::Color& Color::Orange()
    {
        static sf::Color c(243, 126, 18);
        return c;
    }

    sf::Color& Color::Red()
    {
        static sf::Color c(192, 57, 43);
        return c;
    }

    sf::Color& Color::Blue()
    {
        static sf::Color c(41, 128, 185);
        return c;
    }

    sf::Color& Color::LightBlue()
    {
        static sf::Color c(52, 152, 219);
        return c;
    }

    sf::Color& Color::Dark()
    {
        static sf::Color c(44, 62, 80);
        return c;
    }

    sf::Color& Color::White()
    {
        static sf::Color c(236, 240, 241);
        return c;
    }

    sf::Color& Color::Grey()
    {
        static sf::Color c(189, 195, 199);
        return c;
    }
}
