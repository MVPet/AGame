#ifndef _YU
#define _YU

#include "Fighter.h"

class Yu : public Fighter
{
public:
			Yu(float x, float y);
	void	load();
	void	update(sf::Time);
	void	draw(sf::RenderWindow*);
	void	handlePlayerInput(sf::Keyboard::Key, bool);
	void	applyFlip();

private:
	Animation*		anim;
	bool			isMovingLeft;
	bool			isMovingRight;
	float			velocity;
	bool			grounded;
	bool			crouched;
	bool			attacking;
	float			flip;
	
};
#endif // Yu.h