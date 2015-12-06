#include "bonus.hh"

#include "../../engine/color.hh"
#include "../../engine/game-object.hh"

namespace B
{
  Bonus::Bonus(E::Scene& scene, sf::RenderWindow& window, int w, int h,
      float x, float y)
    : E::GameObject(scene, window)
    , w_(w)
    , h_(h)
    , x_(x)
    , y_(y)
  {
    float wi = w;
    float he = h;
    E::Object bo(sf::RectangleShape(sf::Vector2f({wi, he})));
    bo.rectangle_shape_get().setFillColor(E::Color::Orange());
    bo.rectangle_shape_get().setPosition(sf::Vector2f({x, y}));
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

  void Bonus::update(E::Scene& scene, sf::RenderWindow& window, sf::Time& dt)
  {
    GameObject::update(scene, window, dt);
  }
}
