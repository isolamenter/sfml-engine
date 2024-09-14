#include <SFML/Graphics.hpp>

class Game
{
  public:
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
    void update();
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
};

int main()
{
    Game game;
    game.run();
}

Game::Game() : mWindow(sf::VideoMode(640, 482), "SFML TEST")
{
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
    while (mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event{};
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    switch (key)
    {
    case sf::Keyboard::Key::W:
        mIsMovingUp = isPressed;
        break;
    case sf::Keyboard::Key::S:
        mIsMovingDown = isPressed;
        break;
    case sf::Keyboard::Key::A:
        mIsMovingLeft = isPressed;
        break;
    case sf::Keyboard::Key::D:
        mIsMovingRight = isPressed;
        break;
    default:
        break;
    }
}
