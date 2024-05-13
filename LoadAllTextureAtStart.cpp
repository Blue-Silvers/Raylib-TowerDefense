#include "LoadAllTextureAtStart.h"
LoadAllTextureAtStart::LoadAllTextureAtStart()
{

}
void LoadAllTextureAtStart::Start()
{
	//load texture
		loadGrass = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile124.png");

		loadRoad = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile103.png");

		loadRoadR = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile104.png");

		loadRoadL = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile102.png");

		loadTurretPlacement = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile089.png");

		loadRoadOpenAngleRU = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile083.png");

		loadRoadCloseAngleRU = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile081.png");

		loadRoadOpenAngleLU = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile082.png");

		loadRoadCloseAngleLU = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile079.png");

		loadRoadOpenAngleRD = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile106.png");

		loadRoadCloseAngleRD = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile127.png");

		loadRoadOpenAngleLD = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile105.png");

		loadRoadCloseAngleLD = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile125.png");

		loadViewport = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile158.png");

		loadCastle = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile181.png");

		loadRoadU = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile080.png");

		loadRoadD = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile126.png");

		loadRock = LoadTexture("kenney_tower-defense-top-down/PNG/Retina/towerDefense_tile136.png");
}
