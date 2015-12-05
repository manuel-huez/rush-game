#include "game-object.hh"
#include "scene.hh"
#include "object.hh"
#include <map>
#include <string>
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace E
{
    GameObject::GameObject(Scene&, sf::RenderWindow&)
        : GameObject()
    {}
    GameObject::GameObject()
        : objects_{std::map<std::string, Object>()}
        , circles_{std::map<std::string, sf::CircleShape>()}
    {}
    GameObject::~GameObject()
    {}

    void GameObject::object_add(std::string key, Object obj, bool collision)
    {
        objects_[key] = obj;

        if (!collision)
            return;

        switch (obj.type_get())
        {
            case ObjectE::CIRCLE:
                circle_add(key, obj.circle_shape_get());
                break;
            case ObjectE::RECTANGLE:
                {
                    auto rect = obj.rectangle_shape_get();
                    float r = (rect.getSize().x + rect.getSize().y) / 2;
                    sf::CircleShape s(r);
                    s.setPosition(rect.getPosition());
                    circle_add(key, s);
                    break;
                }
            default:
                break;
        }
    }

    Object& GameObject::object_get(std::string key)
    {
        return objects_[key];
    }

    void GameObject::object_set(std::string key, Object obj)
    {
        objects_[key] = obj;
    }

    void GameObject::circle_add(std::string key, sf::CircleShape c)
    {
        circles_[key] = c;
    }

    sf::CircleShape& GameObject::circle_get(std::string key)
    {
        return circles_[key];
    }

    void GameObject::circle_set(std::string key, sf::CircleShape c)
    {
        circles_[key] = c;
    }

    bool GameObject::intersects(sf::CircleShape& c)
    {
        float xa = c.getPosition().x + c.getRadius() / 2;
        float ya = c.getPosition().y + c.getRadius() / 2;
        for (auto x: circles_)
        {
            auto c2 = x.second;
            float xb = c2.getPosition().x + c2.getRadius() / 2;
            float yb = c2.getPosition().y + c2.getRadius() / 2;

            float d = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
            if (d < c.getRadius() + c2.getRadius())
                return true;
        }

        return false;
    }

    void GameObject::update(Scene&, sf::RenderWindow&, sf::Time&)
    {
        std::cout << "Base update" << std::endl;
    }

    void GameObject::draw(sf::RenderWindow& window)
    {
        for (auto x: objects_)
            x.second.draw(window);
    }
}
