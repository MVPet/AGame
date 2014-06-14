#ifndef _FIGHTER
#define _FIGHTER

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "AnimationHolder.h"
#include "Animation.h"
#include <memory>

class Fighter
{
public:
	virtual void	load() =0;
	virtual void	update(sf::Time) =0;
	virtual void	draw(sf::RenderWindow*) =0;
	virtual void	handlePlayerInput(sf::Keyboard::Key, bool) =0;
	void			setVelocity(float vx);
	void			applyFlip();
	float			getVelocity() const;

protected:
	TextureHolder	textures;
	AnimationHolder animations;
	Animation*		anim;
	float			velocity;
	bool			grounded;
	bool			crouched;
	bool			attacking;
	float			flip;
	sf::Vector2f	position;
};
#endif