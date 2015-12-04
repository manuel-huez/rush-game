#pragma once

#include "scene.hh"
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{

    class Engine
    {
    public:
        Engine(const unsigned width, const unsigned height,
            sf::RenderWindow& window);

        sf::RenderWindow& window_get() const;
        void scene_set(Scene& scene);
        Scene& scene_get();
        EventHandler& event_handler_get();

        void draw() const;
        void run();
    private:
        const unsigned width_;
        const unsigned height_;
        sf::RenderWindow& window_;
        Scene scene_;
    };

}
