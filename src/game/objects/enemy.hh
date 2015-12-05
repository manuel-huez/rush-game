#ifndef ENNEMY_H
# define ENNEMY_H

# include <memory>
# include <vector>
# include <string>
# include "../../engine/game-object.hh"
# include "../../engine/scene.hh"
# include "../../engine/object.hh"
# include "../../engine/color.hh"
# include <SFML/Graphics.hpp>
namespace Char
{
  class Enemy : public E::GameObject
  {
    public:
      Enemy(E::Scene& scene, sf::RenderWindow& window,
          float posX, float poxY, int level, std::string name, int tile_size);
      virtual void update(E::Scene& scene, sf::RenderWindow& window,
          sf::Time& dt);
      virtual void die();

      void set_posX(float x);
      void set_posY(float y);
      float get_posY() const;
      float get_posX() const;
    private:
      float posX_;
      float posY_;
      int level_;
      float desX_;
      float desY_;
      std::string name_;
      std::shared_ptr<std::vector<int>> path_;
      int tile_size_;
  };
}

#endif
