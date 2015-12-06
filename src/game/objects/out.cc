#include "out.hh"

#include "../../engine/color.hh"
#include "../../engine/game-object.hh"

namespace B
{
  Out::Out(E::Scene& scene, sf::RenderWindow& window, int size,
      float x, float y)
    : E::GameObject(scene, window)
    , size_(size)
    , x_(x)
    , y_(y)
  {
    float si = size;
    E::Object out(sf::RectangleShape(sf::Vector2f({si * 0.7f, si * 0.7f})));
    out.rectangle_shape_get().setFillColor(E::Color::LightGreen());
    out.rectangle_shape_get().setPosition(sf::Vector2f({x + size / 4,
          y + size / 4}));
    object_add("1Out", out);

    E::Object out1(sf::RectangleShape(sf::Vector2f({si, si})));
    out1.rectangle_shape_get().setFillColor(E::Color::Green());
    out1.rectangle_shape_get().setPosition(sf::Vector2f({x, y}));
    object_add("0Out", out1);

  }

  float Out::get_x() const
  {
    return x_;
  }

  float Out::get_y() const
  {
    return y_;
  }
  
  void Out::set_x(float x)
  {
    x_ = x;
  }

  void Out::set_y(float y)
  {
    y_ = y;
  }

  void Out::update(E::Scene& scene, sf::RenderWindow& window, sf::Time& dt)
  {
    GameObject::update(scene, window, dt);
  }
}
