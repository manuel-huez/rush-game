#include "bonus.hh"

namespace B
{
  Bonus::Bonus(E::Scene& scene, sf::RenderWindow& window)
    : E::GameObject(scene, window)
  {}

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

  void update(E::Scene& scene, sf::RenderWindow& window, sf::Time& dt)
  {
    //
  }
}
