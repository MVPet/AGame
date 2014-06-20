#ifndef _ROOFNIGHT
#define _ROOFNIGHT

#include "Stage.h"
#include "Yu.h"

class RoofNight : public Stage
{
public:
			RoofNight();
	void	load();
	void	update(sf::Time);
	void	draw(sf::RenderWindow*);
	void	handlePlayerInput(sf::Keyboard::Key, bool);

private:
	Animation*	anim;
	Fighter*	p1;
};

#endif // RoofNight.h