#include "sentinel.hh"

namespace EN
{
  Sentinel::Sentinel(E::Scene& scene, sf::RenderWindow& window,
      float posX, float posY, int level, std::string name, int tile_size,
      int size)
    : Char::Enemy(scene, window, posX, posY, level, name, tile_size,
        nullptr, size, 0.f)
  {}

  void Sentinel::update(E::Scene& scene, sf::RenderWindow& window, sf::Time& dt)
  {
    scene = scene;
    if (window.getSize().x > 1)
      return;
    dt = dt;
  }
}
