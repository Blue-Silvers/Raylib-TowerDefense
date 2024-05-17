#include "Timer.h"

Timer::Timer()
{

}
void Timer::Start()
{
    mSecond = 0;
    mMinute = 0;
    mStopTimer = false;
}
void Timer::Update()
{
    if (mStopTimer == false) 
    {
        mSecond += GetFrameTime();
        if (mSecond >= 59)
        {
            mSecond = 0;
            mMinute += 1;
        }
    }

}
void Timer::Draw(Font ft)
{
    DrawTextEx(ft, TextFormat("Survive time :\n\n\n  %02.02f min", /*GetTime() / 100)*/mMinute + mSecond / 100), Vector2{ 500,25 }, 50, 5, WHITE);
}

void Timer::Pause() 
{
    mStopTimer = true;
    mGetMinute = mMinute;
    mGetSecond = mSecond;
}
