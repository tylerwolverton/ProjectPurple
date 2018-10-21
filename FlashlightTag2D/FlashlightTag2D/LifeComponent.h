#pragma once
#include "ActorComponent.h"
class LifeComponent :
    public ActorComponent
{
public:
    LifeComponent(ComponentId componentId, ActorId parentId, int health);
    virtual ~LifeComponent();

	virtual const EComponentNames GetComponentName() const override;

    virtual void Die();
    virtual void TakeDamage(int damage);

	int GetHealth() { return m_health; }
	int GetMaxHealth() { return m_maxHealth; }

    void SetHealth(int health) 
	{ 
		m_health = health; 
		if (m_health > m_maxHealth)
		{
			m_health = m_maxHealth;
		}
	}

protected:
    ActorId m_parentId;
	int m_maxHealth;
	int m_health;
};

