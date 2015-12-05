#include "menu-scene.hh"
#include "../../engine/color.hh"
#include "../../engine/font.hh"
#include <SFML/Graphics.hpp>

namespace Scenes
{
    MenuScene::MenuScene(sf::RenderWindow& window)
        : Scene::Scene(window)
    {
        E::Object bg(sf::RectangleShape(sf::Vector2f(window.getSize())));
        bg.rectangle_shape_get().setFillColor(E::Color::Dark());
        object_add("background", bg);

        E::Object title(sf::Text("Menu", E::Font::Default(), 40));
        title.text_get().setPosition({20, 20});
        title.text_get().setColor(E::Color::White());
        object_add("title_text", title);
        E::Object play(sf::Text("play", E::Font::Default(), 25));
        play.text_get().setPosition({20, 80});
        play.text_get().setColor(E::Color::White());
        object_add("play_text", play);
        E::Object quit(sf::Text("quit", E::Font::Default(), 20));
        quit.text_get().setPosition({20, 110});
        quit.text_get().setColor(E::Color::White());
        object_add("quit_text", quit);

        cur_menu_ = CurrentMenuE::Play;
    }

    void MenuScene::handle_events(sf::RenderWindow& window, sf::Time& dt)
    {
        Scene::handle_events(window, dt);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            object_get("play_text").text_get().setCharacterSize(25);
            object_get("quit_text").text_get().setCharacterSize(20);
            cur_menu_ = CurrentMenuE::Play;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            object_get("play_text").text_get().setCharacterSize(20);
            object_get("quit_text").text_get().setCharacterSize(25);
            cur_menu_ = CurrentMenuE::Quit;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            if (cur_menu_ == CurrentMenuE::Quit)
                window.close();
        }
    }

    void MenuScene::update(sf::RenderWindow& window, sf::Time& dt)
    {
        Scene::update(window, dt);
    }
}
