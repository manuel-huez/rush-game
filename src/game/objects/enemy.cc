#include "enemy.hh"
#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>
namespace Char
{

  Enemy::Enemy(E::Scene& scene, sf::RenderWindow& window,
      float posX, float posY, int level, std::string name, int tile_size,
      std::shared_ptr<std::vector<int>> path, int size, float speed,
      float animation_duration, float animation_distance)
    : E::GameObject(scene, window)
      , posX_(posX)
      , posY_(posY)
      , level_(level)
      , name_(name)
      , tile_size_(tile_size)
      , path_(path)
      , size_(size)
      , speed_(speed)
      , animation_cur_(0)
      , animation_duration_(animation_duration)
      , animation_distance_(animation_distance)
  {
    auto en = E::Object(sf::CircleShape(0.5f * tile_size));
    en.circle_shape_get().setFillColor(E::Color::Red());
    en.circle_shape_get().setPosition({posX * tile_size, posY * tile_size});
    object_add(name_, en, true);
    it_ = 0;;
    sens_ = 1;

    auto ray = E::Object(sf::CircleShape(0));
    ray.circle_shape_get().setFillColor(E::Color::RedOpacity());
    ray.circle_shape_get().setOutlineColor(E::Color::Red());
    ray.circle_shape_get().setOutlineThickness(tile_size / 7.f);
    object_add("0ray", ray, true);

  }

  float dist(float ax, float ay, float bx, float by)
  {
    return sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
  }

  void Enemy::update(E::Scene& scene, sf::RenderWindow& window,
      sf::Time& dt)
  {
    int to_x = (*path_)[it_] % size_;
    int to_y = (*path_)[it_] / size_;

    if (dist(posX_, posY_, to_x, to_y) < 0.1f)
    {
      do {
        if ((it_ == 0 && sens_ == -1)
            || (it_ == path_->size() - 1 && sens_ == 1))
          sens_ *= -1;
        it_ += sens_;
      } while( (*path_)[it_] == 0);
    }
    else
    {
      if (to_x > posX_)
        posX_ += dt.asSeconds() * speed_;
      else if (to_x < posX_)
        posX_ -= dt.asSeconds() * speed_;
      if (to_y > posY_)
        posY_ += dt.asSeconds() * speed_;
      else if (to_y < posY_)
        posY_ -= dt.asSeconds() * speed_;
    }
    GameObject::update(scene, window, dt);
    sf::Vector2f poss(get_posX() * tile_size_, get_posY() * tile_size_);
    auto c = circle_get(name_);
    c.setPosition(poss);
    circle_set(name_, c);
    auto c2 = object_get(name_);
    c2.position_set(poss);
    object_set(name_, c2);

    update_ray(dt);
  }

  void Enemy::update_ray(sf::Time& dt)
  {
    auto c = circle_get(name_);
    sf::Vector2f poss(get_posX() * tile_size_, get_posY() * tile_size_);
    auto c3 = circle_get("0ray");
    float diff = c3.getRadius() - c.getRadius();
    c3.setPosition({poss.x - diff, poss.y - diff});
    if (animation_cur_ > 0)
    {
        c3.setRadius(animation_distance_ *
                ((animation_duration_ - animation_cur_)
                 / animation_duration_));
        animation_cur_ -= dt.asSeconds();
    }
    else
    {
        c3.setRadius(0);
        if (animation_duration_ > 0)
            animation_cur_ = animation_duration_;
    }

    circle_set("0ray", c3);
    auto c4 = object_get("0ray");
    c4.position_set(c3.getPosition());
    c4.radius_set(c3.getRadius());
    object_set("0ray", c4);
  }

  void Enemy::die()
  {

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
