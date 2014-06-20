#ifndef _CITY
#define _CITY

#include "Stage.h"
#include "Yu.h"

class City : public Stage
{
public:
			City();
	void	load();
	void	update(sf::Time);
	void	draw(sf::RenderWindow*);
	void	handlePlayerInput(sf::Keyboard::Key, bool);

private:
	Animation*	anim;
	Fighter*	p1;
};

#endif // City.h