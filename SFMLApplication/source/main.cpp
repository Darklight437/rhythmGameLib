#include <SFML\Graphics.hpp>
#include <Toolmanager.h>
#include <iostream>

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
	bool recordingMode = true;
	int accuracyScore;
	//text
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
	sf::Font font;
	sf::Text text;
	if (!font.loadFromFile("resources/arial.TFF"))
	{
		std::cout << "NO LOAD" << "/n" ;
		//error system
	}
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(10, 10));
	
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////





	while (window.isOpen())
	{
		sf::Event event;

		
		RM.debugClock();
		RM.update();
		window.draw(text);

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

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RControl)
			{
				RM.saveMap();
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
				
				
				accuracyScore = RM.handleBeat(RM.createEvent(), recordingMode);
				switch (accuracyScore)
				{
				case 0:
					text.setFillColor(sf::Color::Red);
					text.setString("Miss");
					break;
				case 1:
					text.setFillColor(sf::Color::Red);
					text.setString("Bad");
					break;
				case 2:
					text.setFillColor(sf::Color::White);
					text.setString("Good");
					break;
				case 3:
					text.setFillColor(sf::Color::Green);
					text.setString("Great");
					break;
				case 4:
					//its gold 
					text.setFillColor(sf::Color::Color(255,215,0));
					text.setString("Perfect");

				default:
					break;
				}

				shape.setFillColor(sf::Color::Blue);
				RM.beatSound();

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


