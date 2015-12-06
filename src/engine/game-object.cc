#include "game-object.hh"
#include "scene.hh"
#include "object.hh"
#include <map>
#include <string>
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdexcept>

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
                    sf::CircleShape s(r / 2);
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
        if (objects_.find(key) == objects_.end())
            throw std::logic_error("Key not found for object (get): " + key);

        return objects_[key];
    }

    void GameObject::object_set(std::string key, Object obj)
    {
        if (objects_.find(key) == objects_.end())
            throw std::logic_error("Key not found for object (set): " + key);

        objects_[key] = obj;
    }

    void GameObject::circle_add(std::string key, sf::CircleShape c)
    {
        circles_[key] = c;
    }

    sf::CircleShape& GameObject::circle_get(std::string key)
    {
        if (circles_.find(key) == circles_.end())
            throw std::logic_error("Key not found for circle (get): " + key);

        return circles_[key];
    }

    void GameObject::circle_set(std::string key, sf::CircleShape c)
    {
        if (circles_.find(key) == circles_.end())
            throw std::logic_error("Key not found for circle (set): " + key);

        circles_[key] = c;
    }

    bool GameObject::intersects(sf::CircleShape& c)
    {
        float xa = c.getPosition().x + (c.getRadius()
            + c.getOutlineThickness()) / 2;
        float ya = c.getPosition().y + (c.getRadius()
            + c.getOutlineThickness()) / 2;
        for (auto x: circles_)
        {
            auto c2 = x.second;
            float xb = c2.getPosition().x + (c2.getRadius()
                + c2.getOutlineThickness()) / 2;
            float yb = c2.getPosition().y + (c2.getRadius()
                + c2.getOutlineThickness()) / 2;

            float d = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
            if (d < c.getRadius() + c2.getRadius())
                return true;
        }

        return false;
    }

    bool GameObject::intersects(GameObject& obj)
    {
        for (auto x: obj.circles_)
        {
            if (intersects(x.second))
                return true;
        }

        return false;
    }

    void GameObject::update(Scene&, sf::RenderWindow&, sf::Time&)
    {
        //
    }

    void GameObject::draw(sf::RenderWindow& window)
    {
        for (auto x: objects_)
            x.second.draw(window);
    }
}
