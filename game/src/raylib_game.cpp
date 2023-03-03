#include "raylib.h"
#include <string>
#include <iostream>

using namespace std;


int main()
{

	//Window Dimensions
	int windowWidth				= 800;
	int windowHeight			= 450;
	InitWindow(windowWidth, windowHeight, "Miguel's Window");

	//Circle Data
	int circleX					= windowWidth / 2;
	int circleY					= windowHeight / 2;
	int radius					= 20;
	int circleSpeed				= 10;
	//Circle Collider Edges
	int upperCircleCollider		= circleY - radius;
	int bottomCircleCollider	= circleY + radius;
	int leftCircleCollider		= circleX - radius;
	int rightCircleCollider		= circleX + radius;

	//Rectangle Data
	int rectX				= 300;
	int rectY				= 0;
	int rectHeight			= 50;
	int rectWidth			= 50;
	int rectDirectionY		= 10;
	//Rectangle Collider Edges
	int upperRectCollider	= rectY;
	int bottomRectCollider	= rectY + rectHeight;
	int leftRectCollider	= rectX;
	int rightRectCollider	= rectX + rectWidth;

	bool collisionWithAxe = true;

	//GameOver Variable
	int gameOverMsgX		= windowWidth/2;
	int gameOverMsgY		= windowHeight/2;
	int gameOverMsgFont		= 20;

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{

		BeginDrawing();
		ClearBackground(WHITE);

		if (collisionWithAxe)
		{
			DrawText("Game Over!", gameOverMsgX, gameOverMsgY, gameOverMsgFont, RED);
		}
		else
		{
			//Game Logic Begins
			//DrawRectangle(leftCircleCollider, upperCircleCollider, 40, 40, GREEN);
			DrawCircle(circleX, circleY, radius, BLUE);
			DrawRectangle(rectX, rectY, rectWidth, rectHeight, RED);



			rectY += rectDirectionY;


			if (rectY > windowHeight - rectHeight || rectY < 0)
			{
				rectDirectionY = -rectDirectionY;
			}

			if (IsKeyDown(KEY_D))
			{
				if (circleX < windowWidth)
					circleX += circleSpeed;
				else
					circleX = 0;
			}
			if (IsKeyDown(KEY_A))
			{
				if (circleX > 0)
					circleX -= circleSpeed;
				else
					circleX = windowWidth;
			}
			if (IsKeyDown(KEY_W))
			{
				if (circleY > 0)
					circleY -= circleSpeed;
				else
					circleY = windowHeight;
			}
			if (IsKeyDown(KEY_S))
			{
				if (circleY < windowHeight)
					circleY += circleSpeed;
				else
					circleY = 0;
			}
		}

		//Game Logic Ends
		EndDrawing();
	}
	return 0;
}