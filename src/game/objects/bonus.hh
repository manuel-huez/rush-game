#ifndef BONUS_H
# define BONUS_H

# include "../../engine/game-object.hh"
# include <SFML/Graphics.hpp>
# include "../../engine/scene.hh"

namespace B
{
  class Bonus : public E::GameObject
  {
    public:
      Bonus(E::scene& scene, sf::RenderWindow& window, int w, int h,
          int x, int y);
      float get_x() const;
      float get_y() const;
      void set_x(float x);
      void set_y(float x);
      void set_bonus(int bonus);
      int get_bonus() const;
    private:
      float x_;
      float y_;
      int bonus_;
  };
}

#endif
