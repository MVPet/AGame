#ifndef _YU
#define _YU

#include "Fighter.h"

class Yu : public Fighter
{
public:
			Yu(float x, float y, bool isP2);
	void	load();
	void	update(sf::Time, Fighter* enemy);
	void	draw(sf::RenderWindow*);
	void	handlePlayerInput();
	bool	getAttacking();
	sf::FloatRect getBoundBox();
	sf::FloatRect getAttackBox();
	bool	getNewAttack();
	void	setNewAttack(bool value);
	int		getHealth();

private:
	Animation*		anim;
	bool			isMovingLeft;
	bool			isMovingRight;
	float			velocity;
	bool			grounded;
	bool			crouched;
	bool			attacking;
	bool			isHit;
	bool			newAttack;
	bool			attackKeyDown;
	bool			isPlayer2;
	float			flip;
	bool			intro;
	bool			hasLost;
	int				health;
	sf::Vector2f	prevPosition;
	sf::Vector2f	movement;

	void	applyFlip();
	void	MAttack();
	void	HAttack();
	void	LAttack();
	void	checkPlayer1Input();
	void	checkPlayer2Input();
	void	checkCollisions(Fighter* enemy);
	
};
#endif // Yu.h