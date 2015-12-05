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

    void GameObject::update(Scene&, sf::RenderWindow&, sf::Time&)
    {}

    void GameObject::draw(sf::RenderWindow& window)
    {
        for (auto x: objects_)
            x.second.draw(window);
    }
}
