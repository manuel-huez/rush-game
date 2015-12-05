#include "enemy.hh"
#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include <SFML/Graphics.hpp>
#include <string>
namespace Char
{

  Enemy::Enemy(E::Scene& scene, sf::RenderWindow& window,
        float posX, float posY, int level, std::string name, int tileSize)
    : E::GameObject(scene, window)
    , posX_(posX)
    , posY_(posY)
    , level_(level)
    , name_(name)
  {
    auto en = E::Object(sf::CircleShape(7));
    en.circle_shape_get().setFillColor(E::Color::Red());
    en.circle_shape_get().setPosition({posX * tileSize, posY * tileSize});
    object_add(name_, en);
  }
  void Enemy::update(E::Scene& scene, sf::RenderWindow& window,
      sf::Time& dt)
  {
    GameObject::update(scene, window, dt);
    set_posX(get_posX() + 1);
    sf::Vector2f poss(get_posX(), get_posY());
    auto c = circle_get(name_);
    c.setPosition(poss);
    circle_set(name_, c);
    auto c2 = object_get(name_);
    c2.position_set(poss);
    object_set(name_, c2);
  }

  void Enemy::die()
  {

  }

  std::string& Enemy::get_name() const
  {
    return name_;
  }

  void Enemy::set_posX(float x)
  {
    posX_ = x;
  }

  void Enemy::set_posY(float y)
  {
    posY_ = y;
  }

  float Enemy::get_posX() const
  {
    return posX_;
  }

  float Enemy::get_posY() const
  {
    return posY_;
  }
}
