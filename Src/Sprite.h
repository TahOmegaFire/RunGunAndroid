//      RUN GUN Source
// Started on 15/05/16.
// Sprite Class Created on 15/05/16
// Daniel Bornscheuer: Main developer

#ifndef C_SPRITE_H
#define C_SPRITE_H

#include "SDL.h"
#include "SDL_image.h"
#include "string"

class Sprite
{
public:

    //Constructors and destructor
    Sprite();
    Sprite(std::string path_file);
    ~Sprite();

    //Variables declaration
    SDL_Texture* m_Texture;
    int m_Width, m_Height;
    float normalizedX, normalizedY, normalizedW, normalizedH;

    //Functions declaration
    SDL_Texture* LoadTexture(std::string path_name);
    void SetTexture(std::string path_name_to_image);
    void ClearMemory();

    void Render(int x, int y, SDL_Rect clip, double angle, SDL_Point* center, SDL_RendererFlip flip);
    void SimpleRender(int x, int y);
    void ARender(int x, int y, SDL_Rect clip, double angle, SDL_Point* center, SDL_RendererFlip flip);
    void ASRender(int x, int y);
};

#endif // C_SPRITE_H
