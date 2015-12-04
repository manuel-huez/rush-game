#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace Engine
{

    class Engine
    {
    public:
        Engine(int width, int height, std::string title);

        sf::RenderWindow& window_get() const;
        EventHandler& eventi_handler_get() const;

        void draw() const;
        void run();
    private:
        const int width_;
        const int height_;
        sf::RenderWindow window_;
        EventHandler event_handler_;
    };

}
