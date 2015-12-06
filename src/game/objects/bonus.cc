#include "bonus.hh"

namespace B
{
  Bonus::Bonus(E::Scene& scene, sf::RenderWindow& window, int w, int h,
      float x, float y)
    : E::GameObject(scene, window)
    , x_(x)
    , y_(y)
  {
    E::Object bo(sf::RectangleShape(sf::Vector2f({2, h})));
    bo.rectangle_shape_get().setFillColor(E::Color::Orange());
    bg.rectangle_shape_get().setPosition(sf::Vector2f({x, y}));
    object_add("0Bonus", bo);
  }

  float Bonus::get_x() const
  {
    return x_;
  }

  int Bonus::get_bonus() const
  {
    return bonus_;
  }

  void Bonus::set_bonus(int bonus)
  {
    bonus_ = bonus;
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

  void update(E::Scene& scene, sf::RenderWindow& window, sf::Time& dt)
  {
    GameObject.update(scene, window, dt);
  }
}
