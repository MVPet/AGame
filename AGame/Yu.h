#ifndef _YU
#define _YU

#include "Fighter.h"

class Yu : public Fighter
{
public:
			Yu();
	void	load();
	void	update(sf::Time);
	void	draw(sf::RenderWindow*);
	void	handlePlayerInput(sf::Keyboard::Key, bool);

private:
	Animation*		anim;
	bool			isMovingLeft;
	bool			isMovingRight;
	float			velocity;
	bool			grounded;
	
};
#endif