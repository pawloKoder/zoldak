#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

namespace Zk {
namespace Game {

class Renderable;

class CrateEntity : public Entity
{
public:
	CrateEntity(sf::Vector2f pos, sf::Vector2f size, const char * imgSrc);
	virtual ~CrateEntity();

	virtual void pickUp() = 0;
};

}}
