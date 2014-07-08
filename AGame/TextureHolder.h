#ifndef _TEXTUREHOLDER
#define _TEXTUREHOLDER

#include <SFML/Graphics.hpp>
#include <memory>

namespace Textures
{
	enum ID { Stand, Crouch, FWalk, BWalk, LAttack, MAttack, HAttack, CLAttack, CMAttack, CHAttack, Background, Hit, CHit, Guard, CGuard, Intro, Win, Lose};
}

class TextureHolder
{

public:
	void				load(Textures::ID id, const std::string& filename);
	sf::Texture&		get(Textures::ID id);
	const sf::Texture&	get(Textures::ID id) const;

private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};

#endif // TextureHolder.h