#include "engine/engine.hh"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "My game");
    E::Engine engine(200, 200, window);

    engine.run();

    return 0;
}
