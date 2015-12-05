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

        animation_cur_      = 0.f;
        animation_duration_ = 1.f;
        animation_distance_ = size * 4;

        auto s = E::Object(sf::CircleShape(size));
        s.circle_shape_get().setFillColor(E::Color::Blue());
        s.circle_shape_get().setPosition(pos);
        object_add("1point", s, true);

        auto noise = E::Object(sf::CircleShape(0));
        noise.circle_shape_get().setFillColor(sf::Color::Transparent);
        noise.circle_shape_get().setOutlineColor(E::Color::LightBlue());
        noise.circle_shape_get().setOutlineThickness(size / 2.5f);
        object_add("0noise", noise, true);
    }

    void Player::update(E::Scene& scene,
            sf::RenderWindow& window, sf::Time& dt)
    {
        GameObject::update(scene, window, dt);

        auto pos = position_get();
        auto c   = circle_get("1point");
        c.setPosition(pos);
        circle_set("1point", c);
        auto c2 = object_get("1point");
        c2.position_set(c.getPosition());
        object_set("1point", c2);

        auto c3 = circle_get("0noise");
        float diff = c3.getRadius() - c.getRadius();
        c3.setPosition({pos.x - diff, pos.y - diff});

        if (animation_cur_ > 0)
        {
            c3.setRadius(animation_distance_ *
                    ((animation_duration_ - animation_cur_) / animation_duration_));
            animation_cur_ -= dt.asSeconds();
        }
        else
            c3.setRadius(0);
        circle_set("0noise", c3);
        auto c4 = object_get("0noise");
        c4.position_set(c3.getPosition());
        c4.radius_set(c3.getRadius());
        object_set("0noise", c4);

        if (pos_ != last_pos_ && animation_cur_ <= 0)
            animation_cur_ = animation_duration_;

        last_pos_ = pos_;
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
