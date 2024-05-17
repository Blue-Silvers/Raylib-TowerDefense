#include "raylib.h"
#include <iostream>
#include "Tile.h"
#include "Timer.h"
#include "LoadAllTextureAtStart.h"
#include "Menus.h"
#include "Money.h"
#include "Enemies.h"


using namespace std;

    void Start();
    void StartRace();
    void Update();
    void Draw();
    void End();

    Font ft;
    Enemies enemies;
    Tile map[24][16];
    Timer timer;
    LoadAllTextureAtStart loadAllTexture;
    Menus menus;
    Money money;

    int nbCheckPoint;
    bool allCheckpointValidate = false;
    float speedMultiply = 1;

    int main() 
    {

        Start();

        while (!WindowShouldClose())
        {
            Update();
            Draw();
        }

        End();
        return 0;
    }


    void Start()
    {
        InitWindow(1200, 800, "Tower Defense");
        SetTargetFPS(60);
        ft = LoadFont("resources/fonts/jupiter_crash.png");
        loadAllTexture.Start();
        menus.Start(ft);
    }

    void StartRace()
    {
        int speedMultiply = 1;
        enemies.Start();
        for (int x = 0; x < 24; x++)
        {
            for (int y = 0; y < 16; y++)
            {
                map[x][y].Start(x, y, loadAllTexture);
            }
        }
        allCheckpointValidate = false;
        timer.Start();
        money.Start();
    }

    void Update()
    {
        if (menus.Update() == 1) 
        {
            StartRace();
        }
        else if (menus.Update() == 2)
        {
            End();
        }
        int enemyDamage = 0;
        enemyDamage += enemies.Update();
        
        for (int x = 0; x < 24; x++)
        {
            for (int y = 0; y < 16; y++)
            {
                money.mMoney += map[x][y].Update(money, x, y, 0);
                map[x][y].turret.Update();
                if (enemyDamage > 0) 
                {
                    if (map[x][y].HitCastle(enemyDamage) == false) 
                    {
                        //GameOver
                    }
                }
            }
        }
        timer.Update();
    }

    void Draw()
    {
        BeginDrawing();

        ClearBackground(BLACK);


        for (int x = 0; x < 24; x++)
        {
            for (int y = 0; y < 16; y++)
            {
                map[x][y].Draw(money, x,y, ft, 0);
            }
        }

        timer.Draw(ft);
        money.Draw(ft);

        enemies.Draw();

        menus.Draw(timer.mGetMinute, timer.mGetSecond);
        EndDrawing();
    }


    void End()
    {
        CloseWindow();
    }