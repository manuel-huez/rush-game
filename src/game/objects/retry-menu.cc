#include "retry-menu.hh"
#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include "../../engine/object.hh"
#include "../../engine/color.hh"
#include "../../engine/font.hh"
#include <SFML/Graphics.hpp>
#include <string>

namespace Objects
{
    RetryMenu::RetryMenu(E::Scene& scene, sf::RenderWindow& window)
        : GameObject(scene, window)
    {
        E::Object title(sf::Text("Damn.. You've been spotted!",
                    E::Font::Default(), 40));
        title.text_get().setPosition({20, 20});
        title.text_get().setFillColor(E::Color::Red());
        object_add("title_text", title);

        E::Object play(sf::Text("retry", E::Font::Default(), 25));
        play.text_get().setPosition({20, 80});
        play.text_get().setFillColor(E::Color::White());
        object_add("retry_text", play);

        E::Object quit(sf::Text("quit", E::Font::Default(), 20));
        quit.text_get().setPosition({20, 110});
        quit.text_get().setFillColor(E::Color::White());
        object_add("quit_text", quit);

        E::Object score(sf::Text("Score: " + std::to_string(score_g)
                    + " -- Best score: " + std::to_string(best_score_g),
                E::Font::Default(), 15));
        score.text_get().setPosition({20, 150});
        object_add("score_text", score);

        if (score_g > best_score_g)
        {
            E::Object record(sf::Text("That's a new record!",
                        E::Font::Default(), 15));
            record.text_get().setPosition({20, 170});
            object_add("record_text", record);

            best_score_g = score_g;
        }

        score_g = 0;
    }
}
