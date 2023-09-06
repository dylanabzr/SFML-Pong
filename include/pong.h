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

#define arial "fonts/arial.ttf"

class Game {
  private:
    sf::Font font;
    sf::Text score_player;
    sf::Text score_enemy;

    char player_score[5], enemy_score[5];
    float enemy_Y = 0, BallX = 1, BallY = 1;
    int downmode = 1, x_status = -1, y_status = 1, player_points = 0, enemy_points = -1;
    sf::Vector2i mouse_position;    

    sf::RenderWindow window{sf::VideoMode(800,600,32), "Window", sf::Style::Titlebar | sf::Style::Close}; 

    void ballCollision();
    void ballMove();
    void playerMove();
    void enemyMove();
    void gameUI();
    void windowLoop();

  public:
    Game();
    void startGame();
};


