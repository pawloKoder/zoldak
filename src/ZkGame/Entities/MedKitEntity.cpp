#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "../../ZkCommon/Constants.h"
#include "../../ZkCommon/LibraryCast.h"

#include "MedKitEntity.h"
#include "SpawnerMeshEntity.h"
#include "../Renderables/BoxRenderable.h"
#include "../GameSystem.h"

using namespace Zk::Common;
using namespace Zk::Game;

MedKitEntity::MedKitEntity(sf::Vector2f pos, SpawnerMeshEntity * spawner)
	:	CrateEntity(pos, sf::Vector2f(0.25f, 0.25f), "medkit.png"),
		spawner(spawner)
{

}

MedKitEntity::~MedKitEntity()
{

}

void MedKitEntity::update(double step)
{

}

EntityType MedKitEntity::getType() const
{
	return EntityType::MedKitEntity;
}

void MedKitEntity::pickUp()
{
	spawner->entityPickedUp();
	markForDeletion();
}
