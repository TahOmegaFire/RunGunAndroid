#include "Player.h"
#include <cmath>

extern SDL_Rect screenRect;

Player::Player()
{
    m_X = 190; //Change to initialization list
    m_Y = 800;

    this->SetSpriteTexture("Images/Test/PlayerTest.png");
    this->clipRect.x = 0;
    this->clipRect.y = 0;
    this->clipRect.w = 150;
    this->clipRect.h = 150;
    this->m_FrameCount = 0;
    this->m_MaxFrame = 6;
}

Player::~Player()
{
    this->m_Sprite.ClearMemory();
}

void Player::Update(float touch_pointX, float touch_pointY, bool was_touched)
{
    this->m_FrameCount++;

    if(m_FrameCount == m_MaxFrame)
    {
        m_FrameCount = 0;
        if(clipRect.x == 0)
            clipRect.x = 150;
        else if(clipRect.x == 150)
            clipRect.x = 300;
        else if(clipRect.x == 300)
            clipRect.x = 450;
        else if(clipRect.x == 450)
            clipRect.x = 0;
    }

    if(was_touched)
    {
        float cX = (touch_pointX * 1920) / screenRect.w;
        float cY = (touch_pointY * 1080) / screenRect.h;

        if(cX > (m_X + 150) && cY < m_Y)
        {
            float sideA = (float)touch_pointX - (float)(m_X + 150);
            float sideB = (float)m_Y - (float)touch_pointY;

            float angleNumber = sideB / sideA;

            float angle = atan(angleNumber) * 180 / 3.14159265;

            Bullet *nBullet = new Bullet(angle, 15, m_X + 150, m_Y);
            bulletList.push_back(nBullet);
        }
    }

    if(!bulletList.empty())
    {
        for(int i = 0; i < bulletList.size(); i++)
        {
            bulletList[i]->Update();
            if(!bulletList[i]->isAlive)
            {
                delete bulletList[i];
                bulletList.erase(bulletList.begin() + i);
            }
        }
    }


}

void Player::Render()
{
    this->m_Sprite.ARender(m_X, m_Y, clipRect, 0, NULL, SDL_FLIP_NONE);

    if(!bulletList.empty())
    {
        for(int i = 0; i < bulletList.size(); i++)
        {
            this->bulletList[i]->Render();
            //SDL_Log("Rendering %i bullet", i);
        }
    }
}

