#pragma once
#include "raylib.h"
#include "raymath.h"
#include <cmath>
class Turret
{
private:

	float mTurretSpeed = 100;
	float mTurretRotaion = 0;
	Texture2D mTurretTexture1, mTurretTexture2, mTurretCurentTexture;

public:
	float mTurretX = 50;
	float mTurretY = 50;
	float mTurretSize = 50;
	bool mTurretUpgrade = false;
	bool mTurretHere = false;
	Turret();
	void Update();
	void Draw(int x, int y);
	void Start();
};

