#pragma once
#include "Types.h"
#include "PhysicsComponent.h"
#include "PlayerPhysicsComponent.h"
#include "Vector2D.h"
#include <vector>

class TransformComponent;

class PhysicsManager
{
public:
	PhysicsManager();
	~PhysicsManager();

	void Update(float deltaTime);
	void ResolveCollisions(float deltaTime);

    void AddPhysicsComponentPtr(StrongPhysicsComponentPtr comp);

    // TODO: Cache changes
    //void AddPhysicsComponent(PhysicsComponent comp);
    /*int AddPlayerPhysicsComponent(std::shared_ptr<TransformComponent> transformComponent,
                                  float maxSpeed,
                                  float mass,
                                  float restitution,
                                  Vector2D<float> velocity = Vector2D<float>(0, 0),
                                  Vector2D<float> acceleration = Vector2D<float>(0, 0));*/

private:
    struct CollisionEvent
    {
        float penetrationDepth;
        Vector2D<float> normal;

        CollisionEvent(float p_penetrationDepth, Vector2D<float> p_normal)
            : penetrationDepth(p_penetrationDepth),
              normal(p_normal)
        {
        }
    };

    CollisionEvent checkCircleCollision(std::shared_ptr<TransformComponent> actorTransformComponent, std::shared_ptr<TransformComponent> innerActorTransformComponent);
	void resolvePenetration(std::shared_ptr<TransformComponent> actorTransformComponent, std::shared_ptr<TransformComponent> innerActorTransformComponent, const PhysicsManager::CollisionEvent& collisionEvent);
    void resolveCollision(std::shared_ptr<PhysicsComponent> actorPhysicsComp, std::shared_ptr<PhysicsComponent> innerActorPhysicsComp, const PhysicsManager::CollisionEvent& collisionEvent);
    
    // TODO: Cache changes
    //std::vector<PhysicsComponent> m_physicsComponentVec;
    std::vector<StrongPhysicsComponentPtr> m_physicsComponentPtrVec;

    int m_lastComponentId;
    int getNextComponentId() { ++m_lastComponentId; return m_lastComponentId; };
};

