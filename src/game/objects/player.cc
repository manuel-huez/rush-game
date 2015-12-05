#include "player.hh"
#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Objects
{
    Player::Player(E::Scene& scene, sf::RenderWindow& window, float size)
        : GameObject(scene, window)
    {
        size_ = size;
        pos_ = {0, 0};

        E::Object r(sf::RectangleShape({size, size}));
        r.rectangle_shape_get().setFillColor(E::Color::Blue());
        object_add("0cursor", r, true);
    }

    void Player::update(E::Scene& scene,
            sf::RenderWindow& window, sf::Time& dt)
    {
        GameObject::update(scene, window, dt);

        auto c = circle_get("0cursor");
        c.setPosition(position_get());
        circle_set("0cursor", c);
        auto c2 = object_get("0cursor");
        c2.position_set(position_get());
        object_set("0cursor", c2);
    }

    sf::Vector2f Player::position_get()
    {
        return pos_;
    }

    void Player::position_set(sf::Vector2f pos)
    {
        pos_ = pos;
    }
}
