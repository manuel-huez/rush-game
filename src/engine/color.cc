#include "color.hh"
#include <SFML/Graphics.hpp>

namespace E
{
    sf::Color& Color::Orange()
    {
        static sf::Color c(243, 126, 18);
        return c;
    }
}
