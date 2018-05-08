#include <SFML\Graphics.hpp>
#include <Toolmanager.h>


//welcome to my shitty OSU ripoff

int main(int argc, char* argv[])
{
	Toolmanager RM;
	bool songPlaying = false;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.0f);
	shape.setOrigin(100, 100);
	shape.setPosition(400, 300);
	shape.setFillColor(sf::Color::Green);
	bool recordingMode = false;

	while (window.isOpen())
	{
		sf::Event event;

		
		RM.debugClock();
		RM.update();
		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LControl)
			{

				if (songPlaying == false)
				{
					RM.playCurrSong();
					songPlaying = true;
					//dont know why system isnt working but instead song will just NEVER play more than once as current
				}
				
			}

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
				RM.dootTest();

			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				shape.setFillColor(sf::Color::Green);
			}

			window.clear();
			window.draw(shape);
			window.display();
			

			
		}

		
	}

	return 0;
}