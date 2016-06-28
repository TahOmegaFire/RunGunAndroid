//      RUN GUN Source
// Started on 15/05/16.
// Actor Class Created on 18/05/16
// Daniel Bornscheuer: Main developer

#include "Actor.h"

Actor::Actor()
{

}

Actor::~Actor()
{
    this->m_Sprite.ClearMemory();
}

void Actor::Update()
{

}

void Actor::SetSpriteTexture(std::string path_name_to_image)
{
    this->m_Sprite.SetTexture(path_name_to_image);
}

void Actor::RenderSimple(int x, int y, SDL_Rect clip)
{
    SDL_Point* point;
    point->x = 0;
    point->y = 0;
    this->m_Sprite.Render(x, y, clip, 0, point, SDL_FLIP_NONE);
}

void Actor::Render(int x, int y, SDL_Rect clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    this->m_Sprite.Render(x, y, clip, angle, center, flip);
}

void Actor::Kill()
{
    this->~Actor();
}
