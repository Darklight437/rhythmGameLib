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
	bool recordingMode = false;
	bool beatmapLoaded = false;
	int accuracyScore;
	//text
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
	sf::Font font;
	sf::Text text2;
	sf::Text text;
	if (!font.loadFromFile(RM.getExePath() + "\\resources\\arial.ttf"))
	{
		std::cout << "NO LOAD" << "\n" ;
		//error system
	}
	text.setFont(font);
	text2.setFont(font);
	text2.setFillColor(sf::Color::Red);
	text.setFillColor(sf::Color::White);
	text2.setPosition(sf::Vector2f(100, 300));
	text.setPosition(sf::Vector2f(100, 100));

	if (recordingMode)
	{
		text2.setString("recording");
	}
	else
	{
		text2.setString("playing");
	}

	//Loading music	
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
	RM.loadSong("\\audio\\Dieseldotogg.wav", RM.getExePath());
	RM.loadSound("\\audio\\clap.wav", RM.getExePath());



/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



	while (window.isOpen())
	{
		sf::Event event;
		
		RM.debugClock();
		RM.update();
		//reset text
		text.setString(" ");
		if (recordingMode)
		{
			beatmapLoaded = true;
		}
		
		
		

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
				//save a map
				if (recordingMode)
				{
					RM.saveMap("song1.txt");
					text.setFillColor(sf::Color::White);
					text.setString("saved");
				}
				else
				{

					GameClock::getInstance().resetClock();
					if (RM.loadMap("song1.txt", RM.getExePath()))
					{
						text.setString("loaded");
					}
					beatmapLoaded = true;
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
				if (beatmapLoaded != true)
				{
					continue;
				}

				
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
					//gold 
					text.setFillColor(sf::Color::Color(255,215,0));
					text.setString("Perfect");

				default:
					break;
				}


				shape.setFillColor(sf::Color::Blue);
				RM.beatSound(0);

			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				shape.setFillColor(sf::Color::Green);
			}

			

			//drawing section
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
			window.clear();
			window.draw(text2);
			window.draw(text);
			window.draw(shape);
			window.display();		
			
		}	
		
	}
	return 0;
}


