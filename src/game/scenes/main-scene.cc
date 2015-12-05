#include "main-scene.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Scenes
{

    MainScene::MainScene(sf::RenderWindow& window)
        : Scene::Scene(window)
    {
        E::Object bg(sf::RectangleShape(sf::Vector2f(window.getSize())));
        bg.rectangle_shape_get().setFillColor(E::Color::Dark());
        object_add("background", bg);

        E::Object o(sf::CircleShape(100));
        o.circle_shape_get().setFillColor(E::Color::Orange());
        object_add("circle", o);

        E::Object o2(sf::RectangleShape({120, 50}));
        o2.rectangle_shape_get().setFillColor(E::Color::Orange());
        object_add("rectangle", o2);
    }

    void MainScene::update(sf::RenderWindow& window, sf::Time& dt)
    {
        Scene::update(window, dt);

        object_get("circle").circle_shape_get().setPosition({10, 10});

        std::cout << "Update" << std::endl;
    }

}
