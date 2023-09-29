#include "../include/pong.hpp"
#include <SFML/Window/Keyboard.hpp>
Game::Game(){
  window.setPosition(sf::Vector2i(10, 50));
  window.setFramerateLimit(60);
  font.loadFromFile(arial);
}

void Movement::ballCollision() {
  if (BallX > 800) {
      BallX = 100;
      points[0]++;
  } else if (BallX < 0) {
      BallX = 700;
      points[1]++;
  }
  if (BallY <= 0 || BallY >= 600) y_status *= -1;
  if (BallX >= 10 && BallX <= 20 && BallY + 5 >= mouse_position.y && BallY - 5 <= mouse_position.y + 70) x_status *= -1;
  if (BallX >= 780 && BallX <= 790 && BallY + 5 >= enemy_Y && BallY - 5 <= enemy_Y + 70) x_status *= -1;
}

void Movement::ballMove(){
    ballCollision();
    BallX += 12 *(x_status);
    BallY += 8 * (y_status);
}

void Movement::playerMove(){
  mouse_position = sf::Mouse::getPosition(window);
}
void Movement::enemyMove(){
  float speed = 7.2f; 
  float deltaY = BallY - enemy_Y;
  if (deltaY < 0) 
      enemy_Y -= speed;
  else if (deltaY > 0)
      enemy_Y += speed;
  if (rand() % 100 < 2)
      downmode *= -1; 
}

Graphics:: Graphics() : ball(5.f), line(sf::Vector2f(2.f, 600.f)){
  for (int i = 0; i < 2; i++)
    bar[i] = sf::RectangleShape(sf::Vector2f(10.f, 70.f)); 
}

void Graphics::initUI(){
  ball.setFillColor(sf::Color::White);
  bar[0].setFillColor(sf::Color::White);
  line.setFillColor(sf::Color::White);
  line.setPosition(400, 0);
}
void Graphics::updateScores(){
  for (int i = 0; i < 2; i++){
    scoreText[i].setFont(font);
    std::sprintf(scoreString[i], "%d", points[i]);
    scoreText[i].setString(scoreString[i]);
    scoreText[i].setCharacterSize(50);
    scoreText[i].setFillColor(sf::Color::White);
    scoreText[i].setPosition((50 + 690 * !i), 500);
    scoreText[i].setStyle(sf::Text::Regular);
  }
}
void Graphics::gameUI(){
  ballMove();
  playerMove();
  enemyMove();
  updateScores();

  window.clear(sf::Color::Black);
  ball.setPosition(BallX, BallY);
  bar[0].setPosition(10, mouse_position.y);
  bar[1].setPosition(780, enemy_Y);

  window.draw(line);
  window.draw(ball);
  for (int i = 0; i < 2; i++){
    window.draw(bar[i]);
    window.draw(scoreText[i]);
  }
  window.display();
}

void Graphics::windowLoop(){
  initUI();
  while(window.isOpen()){
    gameUI();
    sf::Event event;
    while(window.pollEvent(event)){
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
        window.close();
    }
  }
 }

void StartGame::startGame(){
  windowLoop();
}
