#include "Money.h"

Money::Money()
{

}
void Money::Start()
{
    mMoney = 0;
}
void Money::Update()
{

}
void Money::Draw(Font ft)
{
    DrawTextEx(ft, TextFormat("Money : %04i C", mMoney), Vector2{ 900, 50 }, 50, 5, WHITE);
}