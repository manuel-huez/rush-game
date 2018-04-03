#ifndef OUT_H
# define OUT_H

# include <SFML/Graphics.hpp>
# include "../../engine/game-object.hh"
# include "../../engine/scene.hh"

namespace B
{
  class Out: public E::GameObject
  {
    public:
      Out(E::Scene& scene, sf::RenderWindow& window, int size,
          float x, float y);
      virtual void update(E::Scene& scene, sf::RenderWindow& window,
          sf::Time& dt);

      float get_x() const;
      float get_y() const;
      void set_x(float x);
      void set_y(float y);
    private:
      float x_;
      float y_;
  };
}

#endif
