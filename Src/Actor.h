//      RUN GUN Source
// Started on 15/05/16.
// Actor Class Created on 18/05/16
// Daniel Bornscheuer: Main developer

#ifndef C_ACTOR_H
#define C_ACTOR_H

#include "Sprite.h"

class Actor
{
public:

    //Constructors and destructor
    Actor();
    ~Actor();

    //Variables declaration
    Sprite m_Sprite; //Should add something more for Actor?

    //Functions declaration
    virtual void Update();
    void SetSpriteTexture(std::string path_name_to_image);
    virtual void RenderSimple(int x, int y, SDL_Rect clip);
    virtual void Render(int x, int y, SDL_Rect clip, double angle, SDL_Point* center, SDL_RendererFlip flip);
    virtual void Kill();
};


#endif // C_ACTOR_H
