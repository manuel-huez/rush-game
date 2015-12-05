#include "scene.hh"
#include "object.hh"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{

    Scene::Scene()
        : objects_{std::map<std::string, Object>()}
    {}

    Scene::~Scene()
    {}

    void Scene::object_add(std::string key, Object obj)
    {
        objects_[key] = obj;
    }

    Object& Scene::object_get(std::string key)
    {
        return objects_.at(key);
    }

    void Scene::handle_events(sf::RenderWindow& window, sf::Time&)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    void Scene::update(sf::RenderWindow&, sf::Time&)
    {}

    void Scene::draw(sf::RenderWindow& window) const
    {
        for (auto x: objects_)
            x.second.draw(window);
    }

}
