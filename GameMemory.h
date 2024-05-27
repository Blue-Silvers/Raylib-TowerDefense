#pragma once
#include "raylib.h"

#include "Turret.h"
#include "Enemies.h"
//#include "Bullet.h"

#include <memory>
#include <vector>
class GameMemory
{
	public:
		void Init();

		//void DestroyBulletAndEnemies();

		//void SpawnBullet(float x, float y, float angle);

		//std::vector<std::shared_ptr<Enemies>>& GetAllEnemiesHere();

		int mEnemyCount = 0;

	private:

		/*std::vector<std::shared_ptr<Bullet>> mAllBullets{};*/
		/*std::vector<std::shared_ptr<Enemies>> mAllEnemies{};*/
		/*std::vector<Turret> mAllTurrets{};*/

};

