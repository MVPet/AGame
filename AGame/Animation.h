#ifndef _ANIMATION
#define _ANIMATION

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

namespace Animations
{
	enum ID { Stand, Crouch, FWalk, BWalk, LAttack, MAttack, HAttack, CLAttack, CMAttack, CHAttack, Background };
}

class Animation {

public:
			Animation();
			Animation(Animations::ID id, int frames, float frameInterval, bool isLooping, sf::Texture& texture);
	int		getWidth();
	int		getHeight();
	bool	isDone();
	bool	getLoop();
	void	update(sf::Vector2f pos, sf::Time deltaTime);
	void	draw(sf::RenderWindow* window);
	void	setScale(float x, float y);
	void	resetAnimation();

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
	bool			done;
};

#endif // Animation.h