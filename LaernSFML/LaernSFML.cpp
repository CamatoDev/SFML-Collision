#include <SFML/Graphics.hpp>

int main()
{
	unsigned int width = 640;
	unsigned int height = 480;
	sf::RenderWindow window(sf::VideoMode(width, height), "First SFML");
	
	float rayon = 20;
	float m1 = 3;
	sf::CircleShape shape(rayon);
	shape.setOrigin(rayon, rayon);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(width / 2.0, height / 2.0);

	sf::Vector2f speed;
	float speed_const = 2.0f;
	speed.x = speed_const;
	speed.y = speed_const;


	float rayon2 = 30;
	float m2 = 5;
	sf::CircleShape shape2(rayon2);
	shape2.setOrigin(rayon2, rayon2);
	shape2.setFillColor(sf::Color::Red);
	shape2.setPosition(width / 4.0, height / 2.0);

	sf::Vector2f speed2;
	float speed_const2 = 2.0f;
	speed2.x = speed_const2;
	speed2.y = speed_const2;

	bool pause = false;
	

	sf::RectangleShape rectangle(sf::Vector2f(100, 100));

	rectangle.setOrigin(50, 50);
	rectangle.setPosition(width / 2.0, height / 2.0);

	bool running = true;

	sf::Clock clock;

	while (running)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				running = false;
			}

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space) {
					pause = !pause;
				}
			}
		}

		if (pause) {
			if (shape.getPosition().x + rayon + speed.x >= width || shape.getPosition().x - rayon + speed.x <= 0) {
				speed.x = -speed.x;
			}

			if (shape.getPosition().y + rayon + speed.y >= height || shape.getPosition().y - rayon + speed.y <= 0) {
				speed.y = -speed.y;
			}

			if (shape2.getPosition().x + rayon2 + speed2.x >= width || shape2.getPosition().x - rayon2 + speed2.x <= 0) {
				speed2.x = -speed2.x;
			}

			if (shape2.getPosition().y + rayon2 + speed2.y >= height || shape2.getPosition().y - rayon2 + speed2.y <= 0) {
				speed2.y = -speed2.y;
			}

			float x1 = shape.getPosition().x;
			float y1 = shape.getPosition().y;
			float x2 = shape2.getPosition().x;
			float y2 = shape2.getPosition().y;
			sf::Vector2f speed_f;
			sf::Vector2f speed2_f;

			float cx = (x1 - x2);
			float cy = (y1 - y2);
			float cr = rayon + rayon2;

			if ((cx * cx + cy * cy)  <= cr * cr) {
				speed_f = ((m1 - m2)*speed + (2*m2*speed2))/ (m1 + m2);
				speed2_f = ((m2 - m1) * speed2 + (2 * m1 * speed)) / (m1 + m2);

				speed = speed_f;
				speed2 = speed2_f;
			}

			if (clock.getElapsedTime().asMilliseconds() > 1000. / 60.0) {
				//rectangle.setRotation(10);
				//rectangle.rotate(10);
				shape.move(speed);
				shape2.move(speed2);
				clock.restart();
			}
		}

		window.clear();
		window.draw(shape);
		window.draw(shape2);
		//window.draw(rectangle);
		window.display();
	}
	return 0;
}