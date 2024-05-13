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
	return 10;
}
void Tile::Draw(int x, int y)
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
}
