#include "object.hh"
#include <SFML/Graphics.hpp>

namespace E
{

    Object::Object()
    {
        type_ = ObjectE::NONE;
    }

    Object::Object(sf::CircleShape circle)
    {
        circle_ = circle;
        type_ = ObjectE::CIRCLE;
    }

    Object::Object(sf::RectangleShape rectangle)
    {
        rectangle_ = rectangle;
        type_ = ObjectE::RECTANGLE;
    }

    Object::Object(sf::Text text)
    {
        text_ = text;
        type_ = ObjectE::TEXT;
    }

    ObjectE Object::type_get() const
    {
        return type_;
    }

    sf::CircleShape& Object::circle_shape_get()
    {
        return circle_;
    }

    sf::RectangleShape& Object::rectangle_shape_get()
    {
        return rectangle_;
    }

    sf::Text& Object::text_get()
    {
        return text_;
    }

    void Object::position_set(sf::Vector2f pos)
    {
        switch (type_)
        {
            case CIRCLE:
                circle_.setPosition(pos);
                break;
            case RECTANGLE:
                rectangle_.setPosition(pos);
                break;
            case TEXT:
                text_.setPosition(pos);
                break;
            default:
                break;
        }
    }

    void Object::radius_set(float r)
    {
        circle_.setRadius(r);
    }

    void Object::draw(sf::RenderWindow& window)
    {
        switch (type_)
        {
            case CIRCLE:
                window.draw(circle_);
                break;
            case RECTANGLE:
                window.draw(rectangle_);
                break;
            case TEXT:
                window.draw(text_);
                break;
            default:
                break;
        }
    }

}
