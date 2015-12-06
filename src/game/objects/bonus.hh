#ifndef BONUS_H
# define BONUS_H

# include <SFML/Graphics.hpp>
# include "../../engine/game-object.hh"

namespace B
{
  class Bonus : public E::GameObject
  {
    public:
      Bonus(E::Scene& scene, sf::RenderWindow& window);
      int get_bonus() const;
      void set_bonus(int bonus);
      virtual void update(E::Scene& scene, sf::RenderWindow& window,
          sf::Time& dt);
      float get_x() const;
      float get_y() const;
      void set_x(float x);
      void set_y(float y);
    private:
      float x_;
      float y_;
      int bonus_;
      int tile_size_;
  };
}

#endif
