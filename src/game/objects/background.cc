#include "background.hh"
#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include <SFML/Graphics.hpp>

namespace Objects
{
    Background::Background(E::Scene& scene, sf::RenderWindow& window)
        : GameObject(scene, window)
    {
        E::Object bg(sf::RectangleShape(sf::Vector2f(window.getSize())));
        bg.rectangle_shape_get().setFillColor(E::Color::Dark());
        object_add("0background", bg);
    }
}
