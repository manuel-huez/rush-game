#pragma once

#include <SFML/Graphics.hpp>

namespace E
{

    enum ObjectE {
        CIRCLE,
        RECTANGLE,
        TEXT,
        NONE
    };

    class Object
    {
    public:
        Object();
        Object(sf::CircleShape circle);
        Object(sf::RectangleShape rectangle);
        Object(sf::Text text);

        ObjectE type_get() const;

        sf::CircleShape& circle_shape_get();
        sf::RectangleShape& rectangle_shape_get();
        sf::Text& text_get();

        void position_set(sf::Vector2f pos);
        void radius_set(float r);

        void draw(sf::RenderWindow& window);

    private:
        sf::CircleShape circle_;
        sf::RectangleShape rectangle_;
        sf::Text text_;
        ObjectE type_;
    };

}
