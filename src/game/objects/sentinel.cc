#include "sentinel.hh"

namespace EN
{
  Sentinel::Sentinel(E::Scene& scene, sf::RenderWindow& window,
      float posX, float posY, int level, std::string name, int tile_size,
      int size)
    : Char::Enemy(scene, window, posX, posY, level, name, tile_size,
        nullptr, size, 0.f, 5.f, (float)tile_size * 3.f)
  {}

  void Sentinel::update(E::Scene&, sf::RenderWindow&, sf::Time& dt)
  {
    update_ray(dt);
  }
}
