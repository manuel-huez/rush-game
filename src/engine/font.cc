#include "font.hh"
#include <SFML/Graphics.hpp>

namespace E
{
    sf::Font& Font::Default()
    {
        static sf::Font f;
        static bool loaded = false;
        if (!loaded)
            f.loadFromFile("src/assets/flat.ttf");

        return f;
    }
}
