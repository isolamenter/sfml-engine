//
// Created by akiya on 2024/9/18.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
public:
    const float PlayerSpeed = 10.f;
    const sf::Time TimePerFrame = sf::seconds(1.f/60.f);

    Game();
    void run();

private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;

    void processEvents();
    void update(sf::Time);
    void render();
    void handlePlayerInput(sf::Keyboard::Key, bool);
};

#endif //GAME_H
