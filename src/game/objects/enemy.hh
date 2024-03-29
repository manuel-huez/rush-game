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
          float posX, float posY, int level, std::string name, int tile_size,
          std::shared_ptr<std::vector<int>> path, int size, float speed,
          float animation_duration, float animation_distance);
      Enemy(E::Scene& scene, sf::RenderWindow& window,
          float posX, float posY, int level, std::string name, int tile_size,
          std::shared_ptr<std::vector<int>> path, int size, float speed)
        : Enemy(scene, window, posX, posY, level, name, tile_size, path,
                size, speed, 0, 0)
      {}
      virtual void update(E::Scene& scene, sf::RenderWindow& window,
          sf::Time& dt);
      virtual void update_ray(sf::Time& dt);
      virtual void die();

      void set_posX(float x);
      void set_posY(float y);
      float get_posY() const;
      float get_posX() const;
    protected:
      float posX_;
      float posY_;
      int level_;
      std::string name_;
      int tile_size_;
      std::shared_ptr<std::vector<int>> path_;
      int size_;
      int sens_;
      std::vector<int>::size_type it_;
      float speed_;
      float animation_cur_;
      float animation_duration_;
      float animation_distance_;
  };
}

#endif
