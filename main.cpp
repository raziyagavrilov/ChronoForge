#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    // Initialize random seed
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "ChronoForge");
    window.setFramerateLimit(60);

    // Player setup
    sf::CircleShape player(20.f);
    player.setFillColor(sf::Color::Green);
    player.setPosition(400.f, 300.f);
    float playerSpeed = 200.f; // Pixels per second

    // Chrono Shard setup
    std::vector<sf::CircleShape> shards;
    for (int i = 0; i < 5; ++i) {
        sf::CircleShape shard(10.f);
        shard.setFillColor(sf::Color::Yellow);
        shard.setPosition(static_cast<float>(rand() % 700 + 50), static_cast<float>(rand() % 500 + 50));
        shards.push_back(shard);
    }

    // Enemy setup
    sf::CircleShape enemy(15.f);
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(100.f, 100.f);
    float enemySpeed = 100.f;

    // Time manipulation variables
    bool isTimeSlowed = false;
    float timeScale = 1.f;
    int score = 0;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.f, 10.f);

    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds() * timeScale;

        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                isTimeSlowed = !isTimeSlowed;
        }

        // Update time scale
        timeScale = isTimeSlowed ? 0.5f : 1.f;

        // Player movement
        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= playerSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += playerSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= playerSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += playerSpeed;
        player.move(movement * deltaTime);

        // Keep player in bounds
        sf::Vector2f pos = player.getPosition();
        pos.x = std::max(0.f, std::min(pos.x, 760.f));
        pos.y = std::max(0.f, std::min(pos.y, 560.f));
        player.setPosition(pos);

        // Enemy movement (random teleport when time is slowed)
        if (isTimeSlowed && rand() % 100 < 5) {
            enemy.setPosition(static_cast<float>(rand() % 700 + 50), static_cast<float>(rand() % 500 + 50));
        } else {
            sf::Vector2f enemyMove = player.getPosition() - enemy.getPosition();
            float length = std::sqrt(enemyMove.x * enemyMove.x + enemyMove.y * enemyMove.y);
            if (length > 1.f) enemyMove /= length;
            enemy.move(enemyMove * enemySpeed * deltaTime);
        }

        // Check for shard collection
        for (auto it = shards.begin(); it != shards.end();) {
            if (player.getGlobalBounds().intersects(it->getGlobalBounds())) {
                it = shards.erase(it);
                score += 10;
            } else {
                ++it;
            }
        }

        // Update score text
        scoreText.setString("Score: " + std::to_string(score));

        // Draw everything
        window.clear();
        window.draw(player);
        for (const auto& shard : shards) window.draw(shard);
        window.draw(enemy);
        window.draw(scoreText);
        window.display();
    }

    return 0;
}
