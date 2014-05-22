#include "Manager.h"

// Constructor
Manager::Manager(sf::RenderWindow* app) { 
	window = app;
}

// Called once per frame
void Manager::update() {

	elapsed += clock.restart();

	if(elapsed >= sf::seconds(1.0f / 60.0f))
	{
		checkEvent();
		checkKeyboard();
		elapsed = sf::seconds(0.0f);
	}
}

void Manager::draw() {
}

// Used to check for events like closing the window or a key being pressed
void Manager::checkEvent() {

	while (window->pollEvent(event))
	{
		switch(event.type)
		{
			// window closed
			case sf::Event::Closed:
				window->close();
				break;

			//key pressed
			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::Escape)
				{
					window->close();
				}
				break;

			default:
				break;
		}
	}
}

// Used to check for keys being held down
void Manager::checkKeyboard() {
	/* WILL BE USED FOR SOMETHIG LATER,
	*	THIS IS A NOTE TO REMIND ME HOW TO DO THESE EVENTS
	* if(keyboard.isKeyPressed(sf::Keyboard::Escape))
	*	window->close();
	*/
}