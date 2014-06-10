#ifndef _GAME
#define _GAME

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Yu.h"

class Game
{
public:
			Game();
	void	run();

private:
	void	processEvents();
	//void	handlePlayerInput(sf::Keyboard::Key , bool);
	void	update(sf::Time);
	void	render();

private:
	sf::RenderWindow	mWindow;
	Fighter*			p1;
	bool				mIsMovingUp;
	bool				mIsMovingDown;
	bool				mIsMovingLeft;
	bool				mIsMovingRight;
	sf::Time			TimePerFrame;
	TextureHolder		textures;

};

#endif