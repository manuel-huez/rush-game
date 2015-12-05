#include "engine/engine.hh"
#include "engine/scene.hh"
#include "engine/object.hh"
#include "engine/color.hh"
#include "game/scenes/main-scene.hh"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(200, 200), "My game",
            sf::Style::Default, settings);
    E::Engine engine(200, 200, window);

    auto s = std::make_shared<Scenes::MainScene>();
    engine.scene_set(std::static_pointer_cast<E::Scene>(s));

    E::Object o(sf::CircleShape(100));
    o.circle_shape_get().setFillColor(E::Color::Orange());

    engine.scene_get().object_add("circle", o);

    engine.run();

    return 0;
}
