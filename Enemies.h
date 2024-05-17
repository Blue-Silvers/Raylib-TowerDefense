#pragma once
#pragma once
#include "raylib.h"
#include "raymath.h"
#include <cmath>
class Enemies
{
	private:

		float mEnemiesSpeed = 100;
		float mEnemiesRotaion = 0;
		Texture2D enemiesTexture;

	public:
		float mEnemiesX = -50;
		float mEnemiesY = 625;
		float mEnemiesSize = 50;
		Enemies();
		void Update();
		void Draw();
		void Start();
};
