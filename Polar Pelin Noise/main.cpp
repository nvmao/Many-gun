#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Flatform.h"
#include "Game.h"
#include <fstream>
#include "Steering_Behaviors.h"
using namespace sf;
using namespace std;
 


int main()
{
	srand(time(nullptr));

	//Steering_Behaviors s;




	window = new RenderWindow(VideoMode(1500, 800),
		"Polar perlin noise", Style::Default);
	window->setVerticalSyncEnabled(true);
	window->setFramerateLimit(120);

	Game game;

	Event e;
	while (window->isOpen())
	{
		while (window->pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				{
				window->close();
				break;
				}
			case Event::MouseButtonPressed:
				{
				//s.get();
				}
			}
		}
		
		window->clear();

		game.update();
		//s.update();
		
		//s.draw();
		game.draw();

		window->display();

	}


}