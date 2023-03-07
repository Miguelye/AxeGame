#include "raylib.h"
#include <string>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;
bool IsCollision(Shape, Shape);



int main()
{

	//Window Dimensions
	int windowWidth				= 800;
	int windowHeight			= 450;
	InitWindow(windowWidth, windowHeight, "Miguel's Window");

	//Circle Data
	Circle circle(windowWidth / 2, windowHeight / 2, 20);
	int circleSpeed		= 10;

	//Rectangle Data
	Rectngl axe(300, 0, 50, 50);
	int rectDirectionY  = 10;



	//GameOver Variable
	int gameOverMsgX		= windowWidth/2;
	int gameOverMsgY		= windowHeight/2;
	int gameOverMsgFont		= 20;
	
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{

		BeginDrawing();
		ClearBackground(WHITE);

		if (IsCollision(axe, circle))
		{
			DrawText("Game Over!", gameOverMsgX, gameOverMsgY, gameOverMsgFont, RED);
		}
		else
		{
			//Game Logic Begins
			//DrawRectangle(leftCircleCollider, upperCircleCollider, 40, 40, GREEN);
			DrawCircle(circle.posX, circle.posY, circle.radius, BLUE);
			DrawRectangle(axe.posX, axe.posY, axe.width, axe.height, RED);

			//Updating Colliders
			circle.setColliders();
			axe.setColliders();

			axe.posY += rectDirectionY;



			if (axe.posY > windowHeight - axe.height || axe.posY < 0)
			{
				rectDirectionY = -rectDirectionY;
			}

			if (IsKeyDown(KEY_D))
			{
				if (circle.posX < windowWidth)
					circle.posX += circleSpeed;
				else
					circle.posX = 0;
			}
			if (IsKeyDown(KEY_A))
			{
				if (circle.posX > 0)
					circle.posX -= circleSpeed;
				else
					circle.posX = windowWidth;
			}
			if (IsKeyDown(KEY_W))
			{
				if (circle.posY > 0)
					circle.posY -= circleSpeed;
				else
					circle.posY = windowHeight;
			}
			if (IsKeyDown(KEY_S))
			{
				if (circle.posY < windowHeight)
					circle.posY += circleSpeed;
				else
					circle.posY = 0;
			}
		}	

		//Game Logic Ends
		EndDrawing();
	}
	return 0;
}

bool IsCollision(Shape obj1, Shape obj2)
{
	bool collision = (obj1.rightCollider >= obj2.leftCollider) &&
		(obj1.leftCollider <= obj2.rightCollider) &&
		(obj1.upperCollider <= obj2.bottomCollider) &&
		(obj1.bottomCollider >= obj2.upperCollider);

	return collision;
}