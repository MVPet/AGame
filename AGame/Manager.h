#ifndef _MANAGER
#define	_MANAGER

#include <SFML/Graphics.hpp>

class Manager {

public:
	Manager::Manager(sf::RenderWindow* app);
	void update();
	void draw();

private:
	void checkEvent();
	void checkKeyboard();

	sf::Keyboard keyboard;
	sf::Event event;
	sf::RenderWindow* window;

};

#endif