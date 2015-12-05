#include "scene.hh"
#include "object.hh"
#include "engine.hh"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{

    Scene::Scene(Engine&, sf::RenderWindow&)
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

    void Scene::handle_events(Engine&,
            sf::RenderWindow& window, sf::Time&)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    void Scene::update(Engine&, sf::RenderWindow&, sf::Time&)
    {}

    void Scene::draw(sf::RenderWindow& window) const
    {
        for (auto x: objects_)
            x.second.draw(window);
    }

}
