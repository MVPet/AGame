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
	virtual void	update(sf::Time, Fighter* enemy) =0;
	virtual void	draw(sf::RenderWindow*) =0;
	virtual void	handlePlayerInput() =0;
	void			setVelocity(float vx);
	void			applyFlip();
	float			getVelocity() const;
	virtual bool	getAttacking() =0;
	virtual sf::FloatRect getBoundBox() =0;
	virtual sf::FloatRect getAttackBox() =0;
	virtual bool	getNewAttack() =0;
	virtual void	setNewAttack(bool value) =0;
	virtual int		getHealth() =0;

protected:
	TextureHolder	textures;
	AnimationHolder animations;
	Animation*		anim;
	float			velocity;
	bool			grounded;
	bool			crouched;
	bool			attacking;
	bool			newAttack;
	bool			isHit;
	float			flip;
	sf::Vector2f	position;
};
#endif