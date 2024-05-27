#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Enemies.h"
#include "GameMemory.h"

#include <iostream>
#include <cmath>
#include <memory>

class Turret
{
private:

	float mTurretSpeed = 100;
	float mTurretRotaion = 0;
	float mTurretRange = 500;
	Texture2D mTurretTexture1, mTurretTexture2, mTurretCurentTexture;
	Enemies mFocusEnemy;

public:
	float mTurretX = 50;
	float mTurretY = 50;
	float mTurretSize = 50;
	bool mTurretUpgrade = false;
	bool mTurretHere = false;

	Turret();
	void Update(Enemies theEnemy);
	void Draw(int x, int y);
	void Start();
	void LockEnemy(Enemies theEnemy);
};

