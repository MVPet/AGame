#ifndef _ANIMATION
#define _ANIMATION

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

namespace Animations
{
	enum ID { Stand, Crouch, FWalk, BWalk };
}

class Animation {

public:
			Animation();
			Animation(Animations::ID, int, float, bool, sf::Texture& texture);
	int		getWidth();
	int		getHeight();
	void	update(sf::Vector2f pos, sf::Time deltaTime);
	void	draw(sf::RenderWindow*);
	void	setScale(float x, float y);

private:
	sf::Sprite		sprite;
	sf::FloatRect	boundBox;
	sf::FloatRect	headBox;
	sf::FloatRect	bodyBox;
	sf::FloatRect	legBox;
	int				frameIndex;
	int				width;
	int				height;
	int				numOfFrames;
	float			updateTime;
	float			frameTime;
	bool			loop;
};

#endif