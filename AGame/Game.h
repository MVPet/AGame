#ifndef _GAME
#define _GAME

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "StageList.h"
#include "Yu.h"


class Game
{
public:
			Game();
	void	run();

private:
	void	processEvents();
	void	update(sf::Time);
	void	render();

private:
	sf::RenderWindow	mWindow;
	Stage*				stage;
	bool				mIsMovingUp;
	bool				mIsMovingDown;
	bool				mIsMovingLeft;
	bool				mIsMovingRight;
	sf::Time			TimePerFrame;
	TextureHolder		textures;

};

#endif // Game.h