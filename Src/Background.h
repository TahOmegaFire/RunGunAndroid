//      RUN GUN Source
// Started on 15/05/16.
// Background Class Created on 20/05/16
// Daniel Bornscheuer: Main developer

#ifndef C_BACKGROUND_H
#define C_BACKGROUND_H

#include "Actor.h"

class Background : public Actor
{
public:
    //Constructor and destructor
    Background();
    ~Background();

    //Variables declaration
    int m_X, m_Y;

    //Functions declaration
    void Update();
    void RenderNative();
    void RenderSimple(int x, int y);
    void Kill();
};

#endif // C_BACKGROUND_H
