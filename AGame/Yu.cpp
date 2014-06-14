#include "Yu.h"
#include <iostream>

Yu::Yu() : isMovingLeft(false), isMovingRight(false), velocity(100.f), grounded(true), crouched(false), flip(1.f), attacking(false)
{
	position.x = 100.f;
	position.y = 250.f;
}

void Yu::load()
{
	textures.load(Textures::Stand, "Assets/YuStand.png");
	animations.load(Animations::Stand, 7, .1f, true, textures.get(Textures::Stand));

	textures.load(Textures::Crouch, "Assets/YuCrouch.png");
	animations.load(Animations::Crouch, 10, .1f, true, textures.get(Textures::Crouch));

	textures.load(Textures::FWalk, "Assets/YuFWalk.png");
	animations.load(Animations::FWalk, 12, .1f, true, textures.get(Textures::FWalk));

	textures.load(Textures::BWalk, "Assets/YuBWalk.png");
	animations.load(Animations::BWalk, 11, .1f, true, textures.get(Textures::BWalk));

	textures.load(Textures::LAttack, "Assets/YuLAttack.png");
	animations.load(Animations::LAttack, 7, .1f, false, textures.get(Textures::LAttack));

	textures.load(Textures::MAttack, "Assets/YuMAttack.png");
	animations.load(Animations::MAttack, 7, .1f, false, textures.get(Textures::MAttack));

	textures.load(Textures::HAttack, "Assets/YuHAttack.png");
	animations.load(Animations::HAttack, 10, .1f, false, textures.get(Textures::HAttack));

	textures.load(Textures::CLAttack, "Assets/YuCLAttack.png");
	animations.load(Animations::CLAttack, 5, .1f, false, textures.get(Textures::CLAttack));

	textures.load(Textures::CMAttack, "Assets/YuCMAttack.png");
	animations.load(Animations::CMAttack, 13, .1f, false, textures.get(Textures::CMAttack));

	textures.load(Textures::CHAttack, "Assets/YuCHAttack.png");
	animations.load(Animations::CHAttack, 11, .1f, false, textures.get(Textures::CHAttack)); 

	anim = animations.get(Animations::Stand);
}

void Yu::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if(!attacking)
	{
		if (key == sf::Keyboard::D)
			isMovingRight = isPressed;
		else if (key == sf::Keyboard::A)
			isMovingLeft = isPressed;
		else if (key == sf::Keyboard::S)
		{
			crouched = isPressed;
			anim = animations.get(Animations::Crouch);
		}
		else if (key == sf::Keyboard::L)
		{
			attacking = true;
			if(crouched)
			{
				anim = animations.get(Animations::CLAttack);
				anim->resetAnimation();
			}
			else
			{
				anim = animations.get(Animations::LAttack);
				anim->resetAnimation();
			}
		}
		else if (key == sf::Keyboard::SemiColon)
		{
			attacking = true;
			if(crouched)
			{
				anim = animations.get(Animations::CMAttack);
				anim->resetAnimation();
			}
			else
			{
				anim = animations.get(Animations::MAttack);
				anim->resetAnimation();
			}
		}
		else if (key == sf::Keyboard::Quote)
		{
			attacking = true;
			if (crouched)
			{
				anim = animations.get(Animations::CHAttack);
				anim->resetAnimation();
			}
			else
			{
				anim = animations.get(Animations::HAttack);
				anim->resetAnimation();
			}
		}
	}
}

void Yu::update(sf::Time deltaTime)
{
	applyFlip();

	sf::Vector2f movement(0.f, 0.f);

	if(!attacking)
	{
		if(!crouched)
		{
			if(isMovingLeft)
			{
				anim = animations.get(Animations::BWalk);
				movement.x -= velocity;
			}
			if(isMovingRight)
			{
				anim = animations.get(Animations::FWalk);
				movement.x += velocity;
			}
			if((!isMovingLeft  && !isMovingRight) || (isMovingLeft && isMovingRight))
				anim = animations.get(Animations::Stand);
		}
	}
	else
	{
		if(anim->isDone())
		{
			attacking = false;
			crouched = false;
			anim = animations.get(Animations::Stand);
		}
	}

	position.x =  position.x + (movement.x * flip * deltaTime.asSeconds());
	position.y = position.y + (movement.y * flip * deltaTime.asSeconds());

	anim->update(position, deltaTime);
}

void Yu::draw(sf::RenderWindow* window)
{
	anim->draw(window);
}

void Yu::applyFlip()
{
	anim->setScale(flip, 1.f);
}