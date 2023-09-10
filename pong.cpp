#include "include/pong.hpp"
Game::Game(){
  window.setPosition(sf::Vector2i(10, 50));
  window.setFramerateLimit(60);
  font.loadFromFile(arial);
}

void Movement::ballCollision() {
  if (BallX > 800) {
      BallX = 100;
      player_points++;
  } else if (BallX < 0) {
      BallX = 700;
      enemy_points++;
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
void Graphics::gameUI(){
  ballMove();
  playerMove();
  enemyMove();

  window.clear(sf::Color::Black);
  score_player.setFont(font);
  score_enemy.setFont(font);
  std::sprintf(player_score, "%d", player_points);
  std::sprintf(enemy_score, "%d", enemy_points);
  score_player.setString(player_score);
  score_enemy.setString(enemy_score);
  score_player.setCharacterSize(50);
  score_enemy.setCharacterSize(50);
  score_player.setFillColor(sf::Color::White);
  score_enemy.setFillColor(sf::Color::White);
  score_player.setPosition(50, 500);
  score_enemy.setPosition(740, 500);
  score_player.setStyle(sf::Text::Regular);
  score_enemy.setStyle(sf::Text::Regular);

  sf::CircleShape ball(5.f);
  ball.setFillColor(sf::Color::White);
  ball.setPosition(BallX, BallY);

  sf::RectangleShape player_bar(sf::Vector2f(10.f, 70.f));
  player_bar.setFillColor(sf::Color::White);
  player_bar.setPosition(10, mouse_position.y);

  sf::RectangleShape enemy_bar(sf::Vector2f(10.f, 70.f));
  enemy_bar.setFillColor(sf::Color::White);
  enemy_bar.setPosition(780, enemy_Y);

  sf::RectangleShape line(sf::Vector2f(2.f, 600.f));
  line.setFillColor(sf::Color::White);
  line.setPosition(400, 0);

  window.draw(enemy_bar);
  window.draw(player_bar);
  window.draw(line);
  window.draw(ball);
  window.draw(score_player);
  window.draw(score_enemy);
  window.display();
}

void Graphics::windowLoop(){
  while(window.isOpen()){
    gameUI();
    sf::Event event;
    while(window.pollEvent(event)){
      if (event.type == sf::Event::Closed) window.close();
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
    }
  }
 }

void StartGame::startGame(){
  windowLoop();
}
