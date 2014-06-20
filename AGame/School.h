#ifndef _SCHOOL
#define _SCHOOL

#include "Stage.h"
#include "Yu.h"

class School : public Stage
{
public:
			School();
	void	load();
	void	update(sf::Time);
	void	draw(sf::RenderWindow*);
	void	handlePlayerInput(sf::Keyboard::Key, bool);

private:
	Animation*	anim;
	Fighter*	p1;
};

#endif // School.h