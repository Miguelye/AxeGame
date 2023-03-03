#include "raylib.h"
#include <string>
#include <iostream>

using namespace std;


int main()
{

	//Window Dimensions
	int windowWidth = 800;
	int windowHeight = 450;
	InitWindow(windowWidth, windowHeight, "Miguel's Window");

	//Circle Data
	int circleX = windowWidth / 2;
	int circleY = windowHeight / 2;
	int radius = 20;

	//Rectangle Data
	int rectX = 300;
	int rectY = 0;
	int rectHeight = 50;
	int rectWidth = 50;

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		
		BeginDrawing();
		ClearBackground(WHITE);

		//Game Logic Begins
		DrawCircle(circleX, circleY, radius, BLUE);
		DrawRectangle(rectX, rectY, rectWidth, rectHeight, RED);

		
		
		rectY += 5;

		if (IsKeyDown(KEY_D))
		{
			if (circleX < windowWidth)
				circleX += 5;
			else
				circleX = 0;
		}		
		if (IsKeyDown(KEY_A))
		{
			if (circleX > 0)
				circleX -= 5;
			else
				circleX = windowWidth;
		}		
		if (IsKeyDown(KEY_W))
		{
			if (circleY > 0)
				circleY -= 5;
			else
				circleY = windowHeight;
		}		
		if (IsKeyDown(KEY_S))
		{
			if (circleY < windowHeight)
				circleY += 5;
			else
				circleY = 0;
		}



		EndDrawing();
	}
	return 0;
}