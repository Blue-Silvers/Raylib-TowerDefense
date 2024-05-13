#pragma once
#include "raylib.h"
class LoadAllTextureAtStart
{
private:

public :
	Texture2D loadGrass, loadRoad, loadRoadR, loadRoadL, loadTurretPlacement, loadRoadOpenAngleRU, loadRoadCloseAngleRU, loadRoadOpenAngleLU, loadRoadCloseAngleLU, loadRoadOpenAngleRD, loadRoadCloseAngleRD, loadRoadOpenAngleLD, loadRoadCloseAngleLD, loadViewport, loadCastle, loadRoadU, loadRoadD, loadRock;
	LoadAllTextureAtStart();
	void Start();
};

