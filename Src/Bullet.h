//      RUN GUN Source
// Started on 15/05/16.
// Bullet Class Created on 18/05/16
// Daniel Bornscheuer: Main developer

#include "Actor.h"

class Bullet : public Actor
{
public:
    Bullet();
    Bullet(float angle, int vel, float x, float y);
    ~Bullet();

    void Update();
    void Render();
    void Kill();
    
    bool isAlive;

private:
    float m_VelX, m_VelY, m_X, m_Y, m_Angle;
};
