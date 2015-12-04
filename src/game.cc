#include "engine/engine.hh"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(200, 200), "My game",
            sf::Style::Default, settings);
    E::Engine engine(200, 200, window);

    engine.run();

    return 0;
}
