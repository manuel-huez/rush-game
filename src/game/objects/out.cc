#include "out.hh"

#include "../../engine/color.hh"
#include "../../engine/game-object.hh"

namespace B
{
  Bonus::Bonus(E::Scene& scene, sf::RenderWindow& window, int size,
      float x, float y)
    : E::GameObject(scene, window)
    , size_(size)
    , x_(x)
    , y_(y)
  {
    float si = size;
    E::Object out(sf::RectangleShape(sf::Vector2f({si, si})));
    out.rectangle_shape_get().setFillColor(E::Color::Orange());
    out.rectangle_shape_get().setPosition(sf::Vector2f({x, y}));
    object_add("0Out", out);
  }

  float Bonus::get_x() const
  {
    return x_;
  }

  float Bonus::get_y() const
  {
    return y_;
  }
  
  void Bonus::set_x(float x)
  {
    x_ = x;
  }

  void Bonus::set_y(float y)
  {
    y_ = y;
  }

  void Bonus::update(E::Scene& scene, sf::RenderWindow& window, sf::Time& dt)
  {
    GameObject::update(scene, window, dt);
  }
}
