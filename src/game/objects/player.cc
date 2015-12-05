#include "player.hh"
#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Objects
{
    Player::Player(E::Scene& scene, sf::RenderWindow& window, float size,
            sf::Vector2f pos)
        : GameObject(scene, window)
    {
        size_ = size;
        pos_  = pos;

        auto s = E::Object(sf::CircleShape(size));
        s.circle_shape_get().setFillColor(E::Color::Blue());
        s.circle_shape_get().setPosition(pos);
        object_add("0cursor", s, true);
    }

    void Player::update(E::Scene& scene,
            sf::RenderWindow& window, sf::Time& dt)
    {
        GameObject::update(scene, window, dt);

        auto pos = position_get();
        pos.x   -= size_;
        pos.y   -= size_;
        auto c   = circle_get("0cursor");
        c.setPosition(pos);
        circle_set("0cursor", c);
        auto c2 = object_get("0cursor");
        c2.position_set(pos);
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
