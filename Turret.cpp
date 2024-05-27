#include "Turret.h"

#include <vector>

Turret::Turret() 
{

}
void Turret::Start()
{
	mTurretTexture1 = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile249.png");
	mTurretTexture2 = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile250.png");
	mTurretX = 50;
	mTurretY = 50;
	mTurretSize = 50;
	mTurretSpeed = 100;
	mTurretRotaion = 0;
}
void Turret::Update(Enemies theEnemy)
{
	mTurretRotaion += mTurretSpeed * DEG2RAD * GetFrameTime();
	if (theEnemy.mEnemiesX - (mTurretX + mTurretSize/2) + theEnemy.mEnemiesY - (mTurretY + mTurretSize / 2) < mTurretRange)
	{
		LockEnemy(theEnemy);
		mTurretRotaion = 0.5;
	}

}
void Turret::Draw(int x, int y)
{
	if (mTurretHere == true) 
	{
		if (mTurretUpgrade == false)
		{
			mTurretCurentTexture = mTurretTexture1;
		}
		else
		{
			mTurretCurentTexture = mTurretTexture2;
		}
		Rectangle rec{ mTurretX * x + mTurretSize / 2, mTurretY * y + mTurretSize / 2, mTurretSize, mTurretSize };
		Vector2 origin{ mTurretSize / 2, mTurretSize / 2 };
		DrawTexturePro(mTurretCurentTexture, Rectangle{ 0, 0, 128, 128 }, rec, origin, mTurretRotaion * RAD2DEG, WHITE);
	}
}

void Turret::LockEnemy(Enemies theEnemy)
{
	mFocusEnemy = theEnemy;
}