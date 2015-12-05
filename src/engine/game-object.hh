#pragma once

#include "scene.hh"
#include "object.hh"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{

    class Scene;
    class GameObject
    {
    public:
        GameObject(Scene& scene, sf::RenderWindow& window);
        GameObject();
        ~GameObject();

        void object_add(std::string key, Object obj);
        Object& object_get(std::string key);

        void circle_add(std::string key, sf::CircleShape c);
        sf::CircleShape& circle_get(std::string key);
        void rectangle_add(std::string key, sf::RectangleShape r);
        sf::RectangleShape& rectangle_get(std::string key);

        virtual void update(Scene& scene, sf::RenderWindow& window,
                sf::Time& dt);
        virtual void draw(sf::RenderWindow& window);
    private:
        std::map<std::string, Object> objects_;
        std::map<std::string, sf::CircleShape> circles_;
        std::map<std::string, sf::RectangleShape> rectangles_;
    };

}
