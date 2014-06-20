#ifndef _STAGE
#define _STAGE

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "AnimationHolder.h"
#include "Animation.h"
#include "Fighter.h"
#include <memory>

class Stage 
{
public:
	virtual void	load() =0;
	virtual void	update(sf::Time) =0;
	virtual void	draw(sf::RenderWindow*) =0;
	virtual void	handlePlayerInput(sf::Keyboard::Key, bool) =0;

protected:
	TextureHolder	textures;
	AnimationHolder animations;
	Animation*		anim;
	Fighter*		p1;
	sf::Vector2f	position;
};

#endif // Stage.h