#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Export.hpp>
#include <cstdio>
#include <iostream>

#define arial "../fonts/arial.ttf"

class Game {
  protected:
    sf::Font font;
    sf::Text scoreText[2];

    char scoreString[2][5];
    float enemy_Y = 0, BallX = 1, BallY = 1;
    int downmode = 1, x_status = -1, y_status = 1, points[2] {0, -1};
    sf::Vector2i mouse_position;
    sf::RenderWindow window{sf::VideoMode(800,600,32), "Window", sf::Style::Titlebar | sf::Style::Close}; 

  public:
    Game();
};

class Movement : public Game{
  protected:
    void ballCollision();
    void ballMove();
    void playerMove();
    void enemyMove();

};

class Graphics : public Movement{
private:
  sf::CircleShape ball;
  sf::RectangleShape bar[2];
  sf::RectangleShape line;
  void initUI();
  void updateScores();
  void gameUI();
public:
  Graphics();
protected:
  void windowLoop();
};

class StartGame : public Graphics{
  public:
    void startGame();
};
