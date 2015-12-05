#include "menu-scene.hh"
#include "../../engine/color.hh"
#include <SFML/Graphics.hpp>

namespace Scenes
{
    MenuScene::MenuScene(sf::RenderWindow& window)
        : Scene::Scene(window)
    {
        E::Object bg(sf::RectangleShape(sf::Vector2f(window.getSize())));
        bg.rectangle_shape_get().setFillColor(E::Color::Dark());
        object_add("background", bg);
    }

    void MenuScene::update(sf::RenderWindow& window, sf::Time& dt)
    {
        Scene::update(window, dt);
    }
}
