#include "scene.hh"
#include "event-handler.hh"
#include "object.hh"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{

    Scene::Scene()
        : event_handler_{EventHandler()}
        , objects_{std::map<std::string, Object>()}
    {}

    Scene::~Scene()
    {}

    EventHandler& Scene::event_handler_get()
    {
        return event_handler_;
    }

    void Scene::object_add(std::string key, Object obj)
    {
        objects_[key] = obj;
    }

    Object& Scene::object_get(std::string key)
    {
        return objects_.at(key);
    }

    void Scene::update(sf::RenderWindow& window)
    {
        event_handler_.handle(window);
    }

    void Scene::draw(sf::RenderWindow& window) const
    {
        for (auto x: objects_)
            x.second.draw(window);
    }

}
