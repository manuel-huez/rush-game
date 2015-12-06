#include "scene.hh"
#include "game-object.hh"
#include "engine.hh"
#include <map>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

namespace E
{

    Scene::Scene(Engine&, sf::RenderWindow&)
        : gobjects_{std::map<std::string, std::shared_ptr<GameObject>>()}
    {}

    Scene::~Scene()
    {}

    void Scene::gobject_add(std::string key, std::shared_ptr<GameObject> obj)
    {
        gobjects_[key] = obj;
    }

    GameObject& Scene::gobject_get(std::string key)
    {
        return *gobjects_.at(key);
    }

    void Scene::gobject_delete(std::string key)
    {
        gobjects_.erase(key);
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

    void Scene::update(Engine&, sf::RenderWindow& window, sf::Time& dt)
    {
        for (auto x: gobjects_)
            (*(x.second)).update(*this, window, dt);
    }

    void Scene::draw(sf::RenderWindow& window) const
    {
        for (auto x: gobjects_)
            (*(x.second)).draw(window);
    }

}
