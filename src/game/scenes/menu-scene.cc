#include "menu-scene.hh"
#include "../objects/background.hh"
#include "../objects/menu.hh"
#include "../../engine/engine.hh"
#include "../../engine/color.hh"
#include "../../engine/font.hh"
#include "../../engine/scene.hh"
#include "../../engine/game-object.hh"
#include "main-scene.hh"
#include <SFML/Graphics.hpp>
#include <memory>

namespace Scenes
{
    MenuScene::MenuScene(E::Engine& engine, sf::RenderWindow& window)
        : Scene::Scene(engine, window)
    {
        auto bg = std::make_shared<Objects::Background>(*this, window);
        gobject_add("0background", std::static_pointer_cast<E::GameObject>(bg));

        auto menu = std::make_shared<Objects::Menu>(*this, window);
        gobject_add("1menu", std::static_pointer_cast<E::GameObject>(menu));

        cur_menu_ = CurrentMenuE::Play;
    }

    void MenuScene::handle_events(E::Engine& engine,
            sf::RenderWindow& window, sf::Time& dt)
    {
        Scene::handle_events(engine, window, dt);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            gobject_get("1menu")
                .object_get("play_text").text_get().setCharacterSize(25);
            gobject_get("1menu")
                .object_get("quit_text").text_get().setCharacterSize(20);
            cur_menu_ = CurrentMenuE::Play;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            gobject_get("1menu")
                .object_get("play_text").text_get().setCharacterSize(20);
            gobject_get("1menu")
                .object_get("quit_text").text_get().setCharacterSize(25);
            cur_menu_ = CurrentMenuE::Quit;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            if (cur_menu_ == CurrentMenuE::Quit)
                window.close();
            else
            {
                auto s = std::make_shared<Scenes::MainScene>(engine, window);
                engine.scene_set(std::static_pointer_cast<E::Scene>(s));
            }
        }
    }

    void MenuScene::update(E::Engine& engine,
            sf::RenderWindow& window, sf::Time& dt)
    {
        Scene::update(engine, window, dt);
    }
}
