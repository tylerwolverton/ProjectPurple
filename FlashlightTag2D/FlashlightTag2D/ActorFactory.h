#pragma once
#include <memory>
#include <map>
#include <tinyxml2.h>

#include "SDLUtils.h"
#include "Types.h"

class World;

class ActorFactory
{
	ActorId m_lastActorId;

protected:
	ActorComponentCreatorMap m_actorComponentCreators;
	GenericObjectFactory<ActorComponent, ComponentId> m_componentFactory;

public:
	ActorFactory();
	
	StrongGameActorPtr CreatePlayer(World*  world);
	StrongGameActorPtr CreateEnemy(World*  world);
	StrongGameActorPtr CreateCamera(World*  world, StrongGameActorPtr target);

private:
	ActorId GetNextActorId() { ++m_lastActorId; return m_lastActorId; };
};
