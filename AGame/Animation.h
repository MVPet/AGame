#ifndef _ANIMATION
#define _ANIMATION

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

namespace Animations
{
	enum ID { Stand, Crouch, FWalk, BWalk, LAttack, MAttack, HAttack, CLAttack, CMAttack, CHAttack, Background, Hit, CHit, Guard, CGuard, Intro, Win, Lose };
}

class Animation {

public:
			Animation();
			Animation(Animations::ID id, int frames, float frameInterval, bool isLooping, sf::Texture& texture, float bTop, float bLeft, float bHeight, float bWidth, float atTop, float atLeft, float atHeight, float atWidth);
	int		getWidth();
	int		getHeight();
	bool	isDone();
	bool	getLoop();
	void	update(sf::Vector2f pos, sf::Time deltaTime);
	void	draw(sf::RenderWindow* window);
	void	setScale(float x, float y);
	void	resetAnimation();
	void	updateBoxes();

	sf::FloatRect	getBoundBox();
	sf::FloatRect	getAttackBox();

private:
	sf::Sprite		sprite;
	sf::FloatRect	boundBox;
	sf::FloatRect	attackBox;
	int				frameIndex;
	float			width;
	float			height;
	int				numOfFrames;
	float			updateTime;
	float			frameTime;
	bool			loop;
	bool			done;
	float			sTop;
	float			sLeft;
	float			aTop;
	float			aLeft;
};

#endif // Animation.h