#include "Enemies.h"

Enemies::Enemies()
{

}
void Enemies::Start()
{
	enemiesTexture = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile245.png");
	 mEnemiesX = 0;
	 mEnemiesY = 625;
}
int Enemies::Update()
{
	if (mEnemiesY == 625 && mEnemiesX < 275)
	{
		mEnemiesX += 1;
		mEnemiesRotaion = 0;
	}
	else if (mEnemiesY > 325 && mEnemiesX < 575)
	{
		mEnemiesY -= 1;
		mEnemiesRotaion = -1.5;
	}
	else if (mEnemiesX < 575 && mEnemiesY < 625)
	{
		mEnemiesX += 1;
		mEnemiesRotaion = 0;
	}
	else if (mEnemiesY < 625 && mEnemiesX < 775)
	{
		mEnemiesY += 1;
		mEnemiesRotaion = 1.5;
	}
	else if (mEnemiesX < 775 && mEnemiesY > 425)
	{
		mEnemiesX += 1;
		mEnemiesRotaion = 0;
	}
	else if (mEnemiesY > 425 && mEnemiesX < 1025)
	{
		mEnemiesY -= 1;
		mEnemiesRotaion = -1.5;
	}
	else if (mEnemiesX < 1025)
	{
		mEnemiesX += 1;
		mEnemiesRotaion = 0;
	}
	else 
	{
		return damage;
	}
	return 0;
}
void Enemies::Draw()
{
	Rectangle rec{ mEnemiesX, mEnemiesY, mEnemiesSize, mEnemiesSize };
	Vector2 origin{ mEnemiesSize / 2, mEnemiesSize / 2 };
	DrawTexturePro(enemiesTexture, Rectangle{ 0, 0, 128, 128 }, rec, origin, mEnemiesRotaion * RAD2DEG, PINK);
}
