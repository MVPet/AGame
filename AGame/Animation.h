#ifndef _ANIMATION
#define _ANIMATION

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

namespace Animations
{
	enum ID { Stand };
}

class Animation {

public:
			Animation(Animations::ID, int, bool, sf::Texture& texture);
	int		getWidth();
	int		getHeight();
	void	update(sf::Vector2f pos);
	void	draw(sf::RenderWindow*);

private:
	sf::Sprite		sprite;
	sf::FloatRect	boundBox;
	int				frameIndex;
	int				width;
	int				height;
	int				numOfFrames;
	int				updateTime;
	bool			loop;
};

#endif