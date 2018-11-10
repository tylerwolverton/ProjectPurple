#include "Behavior.h"

class GameActor;

class Boss1Behavior :
    public Behavior
{
public:
    Boss1Behavior(std::shared_ptr<GameActor> targetActor, Vector2D<int> levelSize);
    virtual ~Boss1Behavior();

    std::vector<std::shared_ptr<Command>> Update(const GameActor& actor) override;

    void SetTarget(std::shared_ptr<GameActor> targetActor) { m_targetActor = targetActor; }

private:
    std::shared_ptr<GameActor> m_targetActor;
    uint32_t m_lastTickVal;

    void initializeMovePositions();
    void spawnBullets(std::shared_ptr<TransformComponent> actorTransformComp);

    enum EBehaviorStates
    {
        Wait,
        Move,
        Explode
    };

    EBehaviorStates m_curState;
    Vector2D<float> m_moveDir;
    Vector2D<float> m_lastPos;
    Vector2D<int> m_levelSize;
    std::vector<Vector2D<float>> m_movePositionVec;
    int m_curPosIdx;
    int m_bulletCount;
};