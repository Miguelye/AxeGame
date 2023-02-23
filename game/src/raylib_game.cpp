#include "raylib.h"
#include <string>

using namespace std;

int width = 350;
int length = 200;

int main()
{
	InitWindow(width, length, "Miguel's Window");

	

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		DrawCircle(width/2, length/2, 20, BLUE);
		EndDrawing();
	}
	return 0;
}