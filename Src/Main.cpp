//      RUN GUN Source
// Started on 15/05/16.
// Daniel Bornscheuer: Main developer

#include "Background.h"
#include "Player.h"

//Functions declarations
bool InitSDL();
void CloseSDL();

//Global variables declaration
SDL_Window* mainWindow = NULL;

SDL_Renderer* mainRenderer = NULL;

SDL_Rect screenRect = { 0, 0, 320, 240 };

//Main function
int main(int argc, char* args[])
{
    if(!InitSDL())
    {
        SDL_Log("SDL was not initialized.\n");
    }

    SDL_Log("SDL Init.");

    //SDL_Point touchPoint = { screenRect.w / 2, screenRect.h / 2 };
    float touchPointX, touchPointY;

    Background testBg;
    Player mainPlayer;
    testBg.SetSpriteTexture("Images/Test/TestBg.png");

    bool exitApp = false;
    bool touchedScreen = false;
    //bool firstRun = true;

    SDL_Event event;

    //Main loop
    while(!exitApp)
    {
        //Prev to loop
        touchedScreen = false;

        //Event poll
        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
                exitApp = true;

            else if(event.type == SDL_FINGERDOWN)
            {
                touchPointX = event.tfinger.x * static_cast<float>(screenRect.w);
                touchPointY = event.tfinger.y * static_cast<float>(screenRect.h);
                touchedScreen = true;
                SDL_Log("Finger touch at: %f, %f", touchPointX, touchPointY);
            }
        }

        //Update stage
        testBg.Update();

        mainPlayer.Update(touchPointX, touchPointY, touchedScreen);

        //Render stage
        SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(mainRenderer);

        testBg.RenderNative();
        mainPlayer.Render();

        SDL_RenderPresent(mainRenderer);
    }

    CloseSDL();

    return 0;
}

//Functions definitions
bool InitSDL()
{
    SDL_Log("Initializing\n");

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("SDL_Init failed with SDL Error %s\n", SDL_GetError());
		return false;
    }

    else
    {
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			SDL_Log("Linear filtering was not enabled");
		}

		SDL_DisplayMode displayMode;

		if(SDL_GetCurrentDisplayMode(0, &displayMode) == 0)
        {
            screenRect.w = displayMode.w;
            screenRect.h = displayMode.h;
        }

        SDL_Log("Screen is %i x %i\n", screenRect.w, screenRect.h);

        mainWindow = SDL_CreateWindow("Run Gun ALPHA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenRect.w, screenRect.h, SDL_WINDOW_SHOWN);

        if(mainWindow == NULL)
        {
            SDL_Log("Could not create Window. SDL_Error: %s\n", SDL_GetError());
            return false;
        }

        else
        {
            mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(mainRenderer == NULL)
            {
                SDL_Log("Could not create Renderer. SDL_Error: %s\n", SDL_GetError());
                return false;
            }

            else
                SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    }

    return true;
}

void CloseSDL()
{
    SDL_DestroyRenderer(mainRenderer);
	SDL_DestroyWindow(mainWindow);
	mainWindow = NULL;
	mainRenderer = NULL;

	SDL_Quit();
}
