#include "Tile.h"
Tile::Tile()
{

}
void Tile::Start(int x, int y, LoadAllTextureAtStart loadAllTexture)
{
	//load texture
	if (mTileMap[y][x] == (int)TileType::GRASS)
	{
		mTileTexture = loadAllTexture.loadGrass;
	}
	else if (mTileMap[y][x] == (int)TileType::ROAD)
	{
		mTileTexture = loadAllTexture.loadRoad;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADR)
	{
		mTileTexture = loadAllTexture.loadRoadR;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADL)
	{
		mTileTexture = loadAllTexture.loadRoadL;
	}
	else if (mTileMap[y][x] == (int)TileType::TURRETPLACEMENT)
	{
		mTileTexture = loadAllTexture.loadTurretPlacement;
		turret.Start();
	}
	else if (mTileMap[y][x] == (int)TileType::ROADOPENANGLERU)
	{
		mTileTexture = loadAllTexture.loadRoadOpenAngleRU;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADCLOSEANGLERU)
	{
		mTileTexture = loadAllTexture.loadRoadCloseAngleRU;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADOPENANGLELU)
	{
		mTileTexture = loadAllTexture.loadRoadOpenAngleLU;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADCLOSEANGLELU)
	{
		mTileTexture = loadAllTexture.loadRoadCloseAngleLU;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADOPENANGLERD)
	{
		mTileTexture = loadAllTexture.loadRoadOpenAngleRD;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADCLOSEANGLERD)
	{
		mTileTexture = loadAllTexture.loadRoadCloseAngleRD;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADOPENANGLELD)
	{
		mTileTexture = loadAllTexture.loadRoadOpenAngleLD;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADCLOSEANGLELD)
	{
		mTileTexture = loadAllTexture.loadRoadCloseAngleLD;
	}
	else if (mTileMap[y][x] == (int)TileType::VIEWPORT)
	{
		mTileTexture = loadAllTexture.loadViewport;
	}
	else if (mTileMap[y][x] == (int)TileType::CASTLE)
	{
		mTileTexture = loadAllTexture.loadGrass;
		mTileTexture2 = loadAllTexture.loadCastle;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADU)
	{
		mTileTexture = loadAllTexture.loadRoadU;
	}
	else if (mTileMap[y][x] == (int)TileType::ROADD)
	{
		mTileTexture = loadAllTexture.loadRoadD;
	}
	else if (mTileMap[y][x] == (int)TileType::ROCK)
	{
		mTileTexture = loadAllTexture.loadGrass;
		mTileTexture2 = loadAllTexture.loadRock;
	}
}
int Tile::Update(Car car, int x, int y, bool activeEnd)
{
	if (mTileMap[y][x] == (int)TileType::TURRETPLACEMENT)
	{
		mDelay += GetFrameTime();
		if (CheckCollisionPointRec(GetMousePosition(), { mTileX * x, mTileY * y, mTileSize, mTileSize }))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			mOnTurretPlacement = true;
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
			{
				SetMouseCursor(MOUSE_CURSOR_DEFAULT);
				
				if (mDelay >= 0.5) 
				{
					if (turret.mTurretUpgrade == false && turret.mTurretHere == true)
					{
						turret.mTurretUpgrade = true;
					}
				}

				if (turret.mTurretHere == false)
				{
					mDelay = 0;
					turret.mTurretHere = true;
				}
				
			}
			if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
			{
				SetMouseCursor(MOUSE_CURSOR_DEFAULT);
				turret.mTurretHere = false;
				turret.mTurretUpgrade = false;
				//destroy turret and loot half money cost
			}
		}
		else if(mOnTurretPlacement == true)
		{
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
			mOnTurretPlacement = false;
			//caché prix
		}
	}
	turret.Update();
				return 10;
}
void Tile::Draw(int x, int y,Font ft)
{
	
	Rectangle rec{ mTileX * x, mTileY * y, mTileSize, mTileSize };
	Vector2 origin{ 0, 0};
	DrawTexturePro(mTileTexture, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
	if (mTileMap[y][x] == (int)TileType::ROCK)
	{
		DrawTexturePro(mTileTexture2, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
	}
	else if (mTileMap[y][x] == (int)TileType::CASTLE)
	{
		DrawTexturePro(mTileTexture2, Rectangle{ 0, 0, 128, 128 }, Rectangle { mTileX * (float)( x - 2.5), mTileY * (y - 2), mTileSize *3, mTileSize *3 }, origin, 0.0f, WHITE);
	}

	turret.Draw(x, y);

	if (mOnTurretPlacement == true)
	{
		if (turret.mTurretHere == false)
		{
			DrawTextEx(ft, TextFormat("Buy: %03ic", 100), Vector2{ mTileX * x, mTileY * (float)(y - 0.5) }, 18, 1, WHITE);
		}
		else if (turret.mTurretUpgrade == false)
		{
			DrawTextEx(ft, TextFormat("Up: %03ic", 200), Vector2{ mTileX * x, mTileY * (float)(y - 0.5) }, 18, 1, WHITE);
		}
	}
}
