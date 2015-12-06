#ifndef SENTI_H
# define SENTI_H

# include "enemy.hh"
# include <SFML/Graphics.hpp>

namespace EN
{
  class Sentinel: public Char::Enemy
  {
    public:
      Sentinel(E::Scene& scene, sf::RenderWindow& window,
          float posX, float poY, int level, std::string name, int tile_size,
          int size);
      void update(E::Scene&, sf::RenderWindow&, sf::Time& dt);
  };
}

#endif
