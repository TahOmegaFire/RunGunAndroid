//      RUN GUN Source
// Started on 15/05/16.
// Sprite Class Created on 15/05/16
// Daniel Bornscheuer: Main developer

#include "Sprite.h"

extern SDL_Renderer* mainRenderer;
extern SDL_Rect screenRect;

Sprite::Sprite()
{
    this->m_Texture = NULL;
//    SDL_Log("Screen get: X: %i | Y: %i", screenRect.w, screenRect.h);
}

Sprite::Sprite(std::string path_file)
{
    this->SetTexture(path_file);
}

Sprite::~Sprite()
{
    ClearMemory();
}

SDL_Texture* Sprite::LoadTexture(std::string path_name)
{
    if(this->m_Texture != NULL)
        ClearMemory();

    SDL_Texture* newTexture = NULL;

    SDL_Surface* Surface = IMG_Load(path_name.c_str());
    {
        if(Surface == NULL)
            SDL_Log("Unable to load surface for sprite. Path: %s", path_name.c_str());

        else
        {
            newTexture = SDL_CreateTextureFromSurface(mainRenderer, Surface);
            if(newTexture == NULL)
                SDL_Log("Unable to load texture for sprite. Path: %s", path_name.c_str());
            else
            {
                this->m_Width = Surface->w;
                this->m_Height = Surface->h;
            }

            SDL_FreeSurface(Surface);
        }
    }

    SDL_Log("Sprite is %i x %i", m_Width, m_Height);

    float newH = (float)m_Height / 1080.0f;
    float newW = (float)m_Width / 1920.0f;

    normalizedW = newW * screenRect.w;
    normalizedH = newH * screenRect.h;

    SDL_Log("Sprite is normalized to %f x %f", normalizedW, normalizedH);

    return newTexture;
}

void Sprite::SetTexture(std::string path_name_to_image)
{
    this->m_Texture = LoadTexture(path_name_to_image);
    if(m_Texture != NULL)
        SDL_Log("Created texture");
}

void Sprite::ClearMemory()
{
    SDL_DestroyTexture(this->m_Texture);
    this->m_Height = 0;
    this->m_Width = 0;
}

void Sprite::Render(int X, int Y, SDL_Rect clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = { X, Y, m_Height, m_Width };
    SDL_Rect renderClip = clip;

    if(clip.x == 0 && clip.y == 0 && clip.h == 0 && clip.w == 0)
    {
        renderClip = renderQuad;
        renderClip.x = 0;
        renderClip.y = 0;
    }

    /*if(clip != NULL)
    {
        renderQuad->w = clip->w;
		renderQuad->h = clip->h;
    }*/

    SDL_RenderCopyEx(mainRenderer, this->m_Texture, &renderClip, &renderQuad, angle, center, flip);
}

void Sprite::SimpleRender(int x, int y)
{
    SDL_Rect renderRect = {x, y, m_Width, m_Height};
    SDL_Rect renderClip = {0, 0, m_Width, m_Height};

    SDL_RenderCopy(mainRenderer, this->m_Texture, &renderClip, &renderRect);
}

void Sprite::ARender(int x, int y, SDL_Rect clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    //Normalizing X and Y
    float newX = (float)x / 1920;
    float newY = (float)y / 1080;

    normalizedX = newX * screenRect.w;
    normalizedY = newY * screenRect.h;

    SDL_Rect renderClip = clip;
    SDL_Rect renderQuad = { normalizedX, normalizedY, normalizedW, normalizedH };

    if(clip.h != 0 && clip.w != 0) //If Clip != NULL
    {
        float newClipRelationX = (float)clip.w / 1920.0f;
        float newClipRelationY = (float)clip.h / 1080.0f;

        renderQuad.w = newClipRelationX * screenRect.w;
        renderQuad.h = newClipRelationY * screenRect.h;
    }

    if(SDL_RenderCopyEx(mainRenderer, this->m_Texture, &renderClip, &renderQuad, angle, center, flip) != 0)
    {
        SDL_Log("Rendering failed you dingus. SDL Error: %s", SDL_GetError());
    }
}

void Sprite::ASRender(int x, int y)
{
    //Normalizing X and Y
    float newX = (float)x / 1920; //Change width with height?
    float newY = (float)y / 1080;

    normalizedX = newX * screenRect.w;
    normalizedY = newY * screenRect.h;

    SDL_Rect renderRect = {normalizedX, normalizedY, normalizedW, normalizedH};
    SDL_Rect renderClip = {0, 0, m_Width, m_Height};

    if(SDL_RenderCopy(mainRenderer, this->m_Texture, &renderClip, &renderRect) != 0)
    {
        SDL_Log("Rendering failed you dingus. SDL Error: %s", SDL_GetError());
    }
}
