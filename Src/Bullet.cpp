#include <math.h>
#include "Bullet.h"

Bullet::Bullet()
{
    this->SetSpriteTexture("Images/Test/TestBullet.png");
    this->m_VelX = 0.0f;
    this->m_VelY = 0.0f;
    this->m_X = 0.0f;
    this->m_Y = 0.0f;
    this->m_Angle = m_X;
}

Bullet::Bullet(float angle, int vel, float x, float y)
{
    this->m_Sprite.SetTexture("Images/Test/TestBullet.png");
    this->m_VelX = cos(angle * 3.14159265 / 180.0f) * vel;
    this->m_VelY = sin(angle * 3.14159265 / 180.0f) * vel;
    this->m_X = x;
    this->m_Y = y;
    this->m_Angle = angle;
    this->isAlive = true;

    //SDL_Log("Velocities: %f and %f", m_VelX, m_VelY);
}

Bullet::~Bullet()
{
    this->m_Sprite.ClearMemory();
}

void Bullet::Update()
{
    this->m_X += m_VelX;
    this->m_Y -= m_VelY;

    SDL_Log("Bullet X: %f | Bullet Y: %f", m_X, m_Y);

    if(this->m_Y < 10)
        this->isAlive = false;
}

void Bullet::Render()
{
    SDL_Rect rekt = {0, 0, m_Sprite.m_Width, m_Sprite.m_Height};

    this->m_Sprite.ARender(m_X, m_Y, rekt, m_Angle, NULL, SDL_FLIP_NONE);
}

void Bullet::Kill()
{
    delete this;
}
