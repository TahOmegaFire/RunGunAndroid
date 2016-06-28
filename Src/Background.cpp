//      RUN GUN Source
// Started on 15/05/16.
// Background Class Created on 20/05/16
// Daniel Bornscheuer: Main developer

#include "Background.h"

//extern SDL_Rect screenRect;

Background::Background()
{
    this->m_X = 1920;
    this->m_Y = 0;
    SDL_Log("X: %i | Y: %i", m_X, m_Y);
}

Background::~Background()
{
    this->m_Sprite.ClearMemory();
}

void Background::Update()
{
    this->m_X -= 4;

    if(this->m_X < (-1 * (this->m_Sprite.m_Width)))
        this->Kill();
}

void Background::RenderNative()
{
    if(this->m_Sprite.m_Texture != NULL)
    {
        this->m_Sprite.ASRender(m_X, 0);
    }
    else
        SDL_Log("No texture");
}

void Background::RenderSimple(int x, int y)
{
    this->m_Sprite.ASRender(x, y);
}

void Background::Kill()
{
    this->~Background();
}
