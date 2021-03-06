#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "Entity.h"
#include "../InputSystem.h"

namespace Zk {
namespace Game {

class PlayerTrackEntity : public Entity
{
public:
	PlayerTrackEntity(int trackedPlayer);
	virtual ~PlayerTrackEntity();

	virtual void update(double step) override;
	virtual EntityType getType() const override;

	virtual sf::Vector2f getCenterPosition() const override;

private:
	int trackedPlayer;
	sf::Vector2f currPos;
};

}}
