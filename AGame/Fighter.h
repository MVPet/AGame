#ifndef _FIGHTER
#define _FIGHTER

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
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
	float			getVelocity() const;

protected:
	TextureHolder	textures;
	Animation*		anim;
	float			velocity;
	sf::FloatRect	boundBox;
	bool			grounded;
	sf::Vector2f	position;
};
#endif