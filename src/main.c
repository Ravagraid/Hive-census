#include <stdio.h>
#include "raylib.h"
#include "cJSON.h"
#include "resource_dir.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)
#define WINDOW_TITLE "Hello Hive Scum!"

int main (void)
{
	// create a cJSON object 
	cJSON* json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "name", "John Doe");
	cJSON_AddNumberToObject(json, "age", 30);
	cJSON_AddStringToObject(json, "email", "john.doe@example.com");
	// convert the cJSON object to a JSON string 
	char* json_str = cJSON_Print(json);

	// write the JSON string to a file 
	FILE* fp = fopen("data.json", "w");
	if ( fp == NULL ) {
		printf("Error: Unable to open the file.\n");
		return 1;
	}
	printf("%s\n", json_str);
	fputs(json_str, fp);

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	SetTargetFPS(60);

	SearchAndSetResourceDir("resources");
	Texture2D texture = LoadTexture("wabbit_alpha.png");

	// game loop
	while (!WindowShouldClose())
	{
		// drawing
		BeginDrawing();

		// Setup the backbuffer for drawing (clear color and depth buffers)
		ClearBackground(RAYWHITE);

		const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
		const int texture_y = SCREEN_HEIGHT / 2 - texture.width / 2;
		DrawTexture(texture, texture_x, texture_y, WHITE);

		const char* text = WINDOW_TITLE;
		const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
		DrawText(json_str, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y + 10, 20, BLACK);
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	fclose;
	cJSON_free(json_str);
	cJSON_Delete(json);
	CloseWindow();
	return 0;
}