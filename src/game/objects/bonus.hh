#ifndef BONUS_H
# define BONUS_H

# include <SFML/Graphics.hpp>
# include "../../engine/game-object.hh"
# include "../../engine/scene.hh"

namespace B
{
  class Bonus: public E::GameObject
  {
    public:
      Bonus(E::Scene& scene, sf::RenderWindow& window, int w, int h,
          float x, float y);
      virtual void update(E::Scene& scene, sf::RenderWindow& window,
          sf::Time& dt);

      float get_x() const;
      float get_y() const;
      void set_x(float x);
      void set_y(float y);
      int get_bonus() const;
      void set_bonus(int bonus);
    private:
      int w_;
      int h_;
      float x_;
      float y_;
      int bonus_;
  };
}

#endif
