#include "Yu.h"
#include <iostream>

// default constructor
Yu::Yu(float x, float y, bool isP2) : isMovingLeft(false), isMovingRight(false), velocity(300.f), grounded(true), crouched(false), attacking(false), movement(0, 0), isHit(false), newAttack(false), intro(true), hasLost(false), health(5)
{
	position.x = x;
	position.y = y;
	prevPosition = position;
	attackKeyDown = false;
	isPlayer2 = isP2;

	if(isPlayer2)
		flip = -1.0f;
	else
		flip = 1.0f;
}

// loads all the animations we'll need for Yu
void Yu::load()
{
	textures.load(Textures::Stand, "Assets/YuStand.png");
	animations.load(Animations::Stand, 10, .1f, true, textures.get(Textures::Stand), 6.f, 162.f, 405.f, 121.f, 0, 0, 0, 0);

	textures.load(Textures::Crouch, "Assets/YuCrouch.png");
	animations.load(Animations::Crouch, 10, .1f, true, textures.get(Textures::Crouch), 2.f, 174.f, 248.f, 158.f, 0, 0, 0, 0);

	textures.load(Textures::FWalk, "Assets/YuFWalk.png");
	animations.load(Animations::FWalk, 11, .1f, true, textures.get(Textures::FWalk), 2.f, 182.f, 401.f, 135.f, 0, 0, 0, 0);

	textures.load(Textures::BWalk, "Assets/YuBWalk.png");
	animations.load(Animations::BWalk, 11, .1f, true, textures.get(Textures::BWalk), 4.f, 45.f, 394.f, 128.f, 0, 0, 0, 0);

	textures.load(Textures::LAttack, "Assets/YuLAttack.png");
	animations.load(Animations::LAttack, 7, .1f, false, textures.get(Textures::LAttack), 32.f, 127.f, 371.f, 122.f, 51.f, 204.f, 160.f, 135.f);

	textures.load(Textures::MAttack, "Assets/YuMAttack.png");
	animations.load(Animations::MAttack, 7, .1f, false, textures.get(Textures::MAttack),0, 144.f, 372.f, 114.f, 96.f, 136.f, 215.f, 236.f);

	textures.load(Textures::HAttack, "Assets/YuHAttack.png");
	animations.load(Animations::HAttack, 10, .1f, false, textures.get(Textures::HAttack), 99.f, 97.f, 335, 208, 13.f, 47.f, 400.f, 423.f);

	textures.load(Textures::CLAttack, "Assets/YuCLAttack.png");
	animations.load(Animations::CLAttack, 5, .1f, false, textures.get(Textures::CLAttack), 2.f, 138.f, 238.f, 158.f, 65.f, 297.f, 106.f, 112.f);

	textures.load(Textures::CMAttack, "Assets/YuCMAttack.png");
	animations.load(Animations::CMAttack, 13, .1f, false, textures.get(Textures::CMAttack), 39.f, 100.f, 199.f, 177.f, 112.f, 264.f, 66.f, 245.f);

	textures.load(Textures::CHAttack, "Assets/YuCHAttack.png");
	animations.load(Animations::CHAttack, 11, .1f, false, textures.get(Textures::CHAttack), 149.f, 47.f, 350.f, 169.f, 11.f, 205.f, 513.f, 211.f); 

	textures.load(Textures::Guard, "Assets/YuGuard.png");
	animations.load(Animations::Guard, 1, .1f, false, textures.get(Textures::Guard), 0, 0, 0, 0, 0, 0, 0, 0);

	textures.load(Textures::CGuard, "Assets/YuCGuard.png");
	animations.load(Animations::CGuard, 1, .1f, false, textures.get(Textures::CGuard), 0, 0, 0, 0, 0, 0, 0, 0);

	textures.load(Textures::Hit, "Assets/YuHit.png");
	animations.load(Animations::Hit, 3, .1f, false, textures.get(Textures::Hit), 0, 0, 380.f, 310.f, 0, 0, 0, 0);

	textures.load(Textures::CHit, "Assets/YuCHit.png");
	animations.load(Animations::CHit, 3, .1f, false, textures.get(Textures::CHit), 0, 0, 265.f, 380.f, 0, 0, 0, 0);

	textures.load(Textures::Intro, "Assets/YuIntro.png");
	animations.load(Animations::Intro, 13, .1f, false, textures.get(Textures::Intro), 0, 0, 0, 0, 0, 0, 0, 0);

	textures.load(Textures::Win, "Assets/YuWin.png");
	animations.load(Animations::Win, 12, .1f, false, textures.get(Textures::Win), 0, 0, 0, 0, 0, 0, 0, 0);

	textures.load(Textures::Lose, "Assets/YuLose.png");
	animations.load(Animations::Lose, 7, .1f, false, textures.get(Textures::Lose), 0, 0, 0, 0, 0, 0, 0, 0);

	anim = animations.get(Animations::Intro);
}

// what we'll do with the inputs, if an attack key, attack, if move, move, etc.
// Could be spiced up by having a Enum for certain controls (IE LightAttack = L), which would allow for customizable controls, but I'll cross that bridge when I get there
void Yu::handlePlayerInput()
{
	if (isPlayer2)
		checkPlayer2Input();
	else
		checkPlayer1Input();
}

// our update loop per frame, handles what Yu will do depending on the state he's in
void Yu::update(sf::Time deltaTime, Fighter* enemy)
{
	applyFlip();

	if(!hasLost)
	{
		if(!intro)
		{
	
			movement.x = 0;
			movement.y = 0;
		
			if(!isHit)
			{
				if(!attacking)
				{
					if(!crouched)
					{
						if(isMovingLeft)
						{
							if(enemy->getAttacking())
							anim = animations.get(Animations::Guard);
							else
							{
								anim = animations.get(Animations::BWalk);
								movement.x -= velocity;
							}
						}
						if(isMovingRight)
						{
								anim = animations.get(Animations::FWalk);
								movement.x += velocity;
						}
						if((!isMovingLeft  && !isMovingRight) || (isMovingLeft && isMovingRight))
							anim = animations.get(Animations::Stand);
					}
					else
						if(isMovingLeft && enemy->getAttacking())
								anim = animations.get(Animations::CGuard);

					if(enemy->getHealth() <= 0)
					anim = animations.get(Animations::Win);

					if(health <= 0)
					anim = animations.get(Animations::Lose);
				}
				else
				{
					if(anim->isDone())
					{
						attacking = false;
						position = prevPosition;
						if(crouched)
							anim = animations.get(Animations::Crouch);
						else
							anim = animations.get(Animations::Stand);
					}
				}
			}
			else
			{
				if(anim->isDone())
				{
					isHit = false;
					if(crouched)
						anim = animations.get(Animations::Crouch);
					else
						anim = animations.get(Animations::Stand);
				}
			}


			checkCollisions(enemy);

			position.x =  position.x + (movement.x * flip * deltaTime.asSeconds());
			position.y = position.y + (movement.y * flip * deltaTime.asSeconds());
		}
		else
		{
			if(anim->isDone())
			{
				intro = false;
				anim = animations.get(Animations::Stand);
			}
		}
	}

	anim->update(position, deltaTime);
}

void Yu::draw(sf::RenderWindow* window)
{
	anim->draw(window);
}

// flips the character
void Yu::applyFlip()
{
	anim->setScale(flip, 1.f);
}

void Yu::checkCollisions(Fighter* enemy)
{
	if(anim->getBoundBox().intersects(enemy->getBoundBox()))
		movement = sf::Vector2f(0,0);

	if(enemy->getNewAttack() && anim->getBoundBox().intersects(enemy->getAttackBox()))
	{
		enemy->setNewAttack(false);
		isHit = true;
		if(!crouched)
		{
			anim = animations.get(Animations::Hit);
			health--;
			anim->resetAnimation();
		}
		else
		{
			anim = animations.get(Animations::CHit);
			health--;
			anim->resetAnimation();
		}
	}

	if(enemy->getNewAttack() && anim->getAttackBox().intersects(enemy->getAttackBox()))
	{
		enemy->setNewAttack(false);
		isHit = true;
		if(!crouched)
		{
			anim = animations.get(Animations::Hit);
			health--;
			anim->resetAnimation();
		}
		else
		{
			anim = animations.get(Animations::CHit);
			health--;
			anim->resetAnimation();
		}
	}
}

void Yu::checkPlayer1Input()
{
	if(!attacking)
	{
		isMovingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		isMovingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			crouched = true;
			anim = animations.get(Animations::Crouch);
		}
		else
			crouched = false;

		if(!attackKeyDown)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				LAttack();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				MAttack();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
				HAttack();
		}
	}

	attackKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::L) || sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon) || sf::Keyboard::isKeyPressed(sf::Keyboard::Quote);
}

void Yu::checkPlayer2Input()
{
	if(!attacking)
	{
		isMovingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::K);
		isMovingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
			crouched = true;
			anim = animations.get(Animations::Crouch);
		}
		else
			crouched = false;

		if(!attackKeyDown)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma))
				LAttack();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period))
				MAttack();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
				HAttack();
		}
	}

	attackKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::L) || sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon) || sf::Keyboard::isKeyPressed(sf::Keyboard::Quote);
}

void Yu::LAttack()
{
	newAttack = true;
	attacking = true;

	if(crouched)
	{
		anim = animations.get(Animations::CLAttack);
		anim->resetAnimation();
	}
	else
	{
		prevPosition = position;
		anim = animations.get(Animations::LAttack);
		anim->resetAnimation();
	}
}

void Yu::MAttack()
{
	newAttack = true;
	attacking = true;

	if(crouched)
	{
		anim = animations.get(Animations::CMAttack);
		anim->resetAnimation();
	}
	else
	{
		prevPosition = position;
		position.x += 25.0f;

		anim = animations.get(Animations::MAttack);
		anim->resetAnimation();
	}
}

void Yu::HAttack()
{
	newAttack = true;
	attacking = true;

	if (crouched)
	{
		anim = animations.get(Animations::CHAttack);
		anim->resetAnimation();
	}
	else
	{
		prevPosition = position;
		position.x += 50.0f;

		anim = animations.get(Animations::HAttack);
		anim->resetAnimation();
	}
}

bool Yu::getAttacking()
{ return attacking; }

sf::FloatRect Yu::getBoundBox()
{ return anim->getBoundBox(); }

sf::FloatRect Yu::getAttackBox()
{ return anim->getAttackBox(); }

bool Yu::getNewAttack()
{ return newAttack; }

void Yu::setNewAttack(bool value)
{ newAttack = value; }

int Yu::getHealth()
{ return health; }