#pragma once
#include "raylib.h"
#include "Environement.h"
#include "Money.h"
#include "LoadAllTextureAtStart.h"
#include "Turret.h"

class Tile
{
private:

	float mTileSize = 50.0f;
	float mTileX = 50.0f;
	float mTileY = 50.0f;
    int mTileMap[16][24]
    {
        { 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13},
        { 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13},
        { 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13},
        {17, 0, 0, 0, 0, 0, 0, 0,17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 4, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 8,15,15,15,15,15,15,15, 6, 0,17, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 4, 3, 1, 1, 1, 1, 1, 1, 1, 2, 4, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0},
        { 0, 0, 0, 0, 3, 1, 7,16,16,16, 5, 1, 2, 0, 8,15,15,15,15,15,15, 0, 0, 0},
        { 0,17, 0, 4, 3, 1, 2, 4, 0, 4, 3, 1, 2, 4, 3, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        { 0, 0, 0, 0, 3, 1, 2, 0, 0, 0, 3, 1, 2, 0, 3, 1, 7,16,16,16,16, 0, 0,14},
        { 0, 4, 0, 4, 3, 1, 2, 4,17, 4, 3, 1, 2, 4, 3, 1, 2, 4, 0, 4, 0, 0, 0, 0},
        {15,15,15,15, 9, 1, 2, 0, 0, 0, 3, 1,11,15, 9, 1, 2, 0, 0, 0, 0, 0, 0, 0},
        { 1, 1, 1, 1, 1, 1, 2, 4, 0, 4, 3, 1, 1, 1, 1, 1, 2, 4,17, 0, 0, 0, 0, 0},
        {16,16,16,16,16,16,10,17, 0, 0,12,16,16,16,16,16,10, 0, 0, 0, 0, 0, 0, 0},
        { 0, 4, 0, 4, 0, 4, 0, 0, 0,17, 0, 4, 0, 4, 0, 4, 0, 0, 0,17, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,17},
    };

    Texture2D mTileTexture, mTileTexture2;
    bool mOnTurretPlacement = false;
    int mTurretState = 0;
    float mDelay;
    int mCost;
    int mCasltleLife = 1000;

public:


    Turret turret;
	Tile();
	int Update(Money money, int x, int y, int costValue);
	void Draw(Money money, int x, int y, Font ft, int costValue);
	void Start(int x, int y,LoadAllTextureAtStart loadAllTexture);

    bool mCheckpoint = true;
    bool mValidateCheckpoint = false;
};

