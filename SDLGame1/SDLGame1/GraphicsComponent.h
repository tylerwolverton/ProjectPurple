#pragma once
#include "ActorComponent.h"
#include "SDLUtils.h"

class GameActor;
struct SDL_Texture;

class GraphicsComponent :
	public ActorComponent
{
public:
	SDL_Rect animationFrameRect;
	SDL_Texture* m_sprite;

	GraphicsComponent(SDL_Texture* sprite, int animationTimer);
	virtual ~GraphicsComponent();

	virtual bool Init(tinyxml2::XMLElement* pData) override;
	virtual void PostInit() override;
	virtual void Update(GameActor& actor, int deltaMs) override;

	virtual ComponentId GetComponentId() const override;
	virtual EComponentNames GetComponentName() const override;

private:
	int curAnimationTime, m_animationTimer;
	int xFrame, yFrame;
};

