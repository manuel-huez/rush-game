#include "engine/engine.hh"
#include "engine/scene.hh"
#include "game/scenes/main-scene.hh"
#include "game/scenes/menu-scene.hh"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 800), "My game",
            sf::Style::Default, settings);
    E::Engine engine(800, 800, window);

    auto s = std::make_shared<Scenes::MainScene>(window);
    engine.scene_set(std::static_pointer_cast<E::Scene>(s));

    while (window.isOpen())
        engine.run();

    return 0;
}
