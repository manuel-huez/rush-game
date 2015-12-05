#include "game-object.hh"
#include "scene.hh"
#include "object.hh"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{
    GameObject::GameObject(Scene&, sf::RenderWindow&)
        : GameObject()
    {}
    GameObject::GameObject()
        : objects_{std::map<std::string, Object>()}
        , circles_{std::map<std::string, sf::CircleShape>()}
        , rectangles_{std::map<std::string, sf::RectangleShape>()}
    {}
    GameObject::~GameObject()
    {}

    void GameObject::object_add(std::string key, Object obj)
    {
        objects_[key] = obj;
    }

    Object& GameObject::object_get(std::string key)
    {
        return objects_[key];
    }

    void GameObject::circle_add(std::string key, sf::CircleShape c)
    {
        circles_[key] = c;
    }

    sf::CircleShape& GameObject::circle_get(std::string)
    {
        return circles_[key];
    }

    void GameObject::rectangle_add(std::string key, sf::RectangleShape r)
    {
        rectangles_[key] = r;
    }

    sf::RectangleShape& GameObject::rectangle_get(std::string key)
    {
        return rectangles_[key];
    }

    void GameObject::update(Scene&, sf::RenderWindow&, sf::Time&)
    {}

    void GameObject::draw(sf::RenderWindow& window)
    {
        for (auto x: objects_)
            x.second.draw(window);
    }
}
