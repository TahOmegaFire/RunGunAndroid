#include "Bullet.h"
#include <deque>

class Player : public Actor
{
public:
    //Constructor & Destructor
    Player();
    ~Player();

    int m_X, m_Y, m_FrameCount, m_MaxFrame;

    SDL_Rect clipRect;

    //Functions declaration
    void Update(float touch_pointX, float touch_pointY, bool was_touched);
    void Render();

private:
    std::deque<Bullet*> bulletList; //Temporary bullet list for testing
};
