#include <SFML\Graphics.hpp>
#include <Gamemanager.h>


//welcome to my shitty OSU ripoff

int main(int argc, char* argv[])
{
	Gamemanager GM;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.0f);
	shape.setOrigin(100, 100);
	shape.setPosition(400, 300);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;

		if (!GM.songPlaying)
		{
			GM.playCurrSong();
			GM.songPlaying = true;
		}

		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				shape.setFillColor(sf::Color::Blue);
				GM.dootTest();

			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				shape.setFillColor(sf::Color::Green);
			}

			window.clear();
			window.draw(shape);
			window.display();
			GM.update();
		}

		
	}

	return 0;
}