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
	void	handlePlayerInput();

private:
	Animation*	anim;
	Fighter*	p1;
	Fighter*	p2;
};

#endif // City.h