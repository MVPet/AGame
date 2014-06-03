#ifndef _GAME
#define _GAME

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

class Game
{
public:
			Game();
	void	run();

private:
	void	processEvents();
	void	handlePlayerInput(sf::Keyboard::Key , bool);
	void	update(sf::Time);
	void	render();

private:
	sf::RenderWindow	mWindow;
	sf::Texture			mTexture;
	sf::Sprite			mPlayer;
	bool				mIsMovingUp;
	bool				mIsMovingDown;
	bool				mIsMovingLeft;
	bool				mIsMovingRight;
	float				playerSpeed;
	sf::Time			TimePerFrame;
	TextureHolder		textures;

};

#endif