#include "menu.hh"
#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include "../../engine/font.hh"
#include <SFML/Graphics.hpp>

namespace Objects
{
    Menu::Menu(E::Scene& scene, sf::RenderWindow& window)
        : GameObject(scene, window)
    {
        E::Object title(sf::Text("Sprinter Cell", E::Font::Default(), 40));
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
    }
}
