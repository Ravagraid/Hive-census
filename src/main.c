/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

For a C++ project simply rename the file to .cpp and re-run the build script 

-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty. In no event 
--will the authors be held liable for any damages arising from the use of this software.

--Permission is granted to anyone to use this software for any purpose, including commercial 
--applications, and to alter it and redistribute it freely, subject to the following restrictions:

--  1. The origin of this software must not be misrepresented; you must not claim that you 
--  wrote the original software. If you use this software in a product, an acknowledgment 
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

*/

#include <stdio.h>
#include "raylib.h"
#include "cJSON.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

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
	fclose;
		// free the JSON string and cJSON object 
		cJSON_free(json_str);
	cJSON_Delete(json);

	// Tell the window to use vysnc and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(1280, 800, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the backbuffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("Hello Raylib", 200,200,20,WHITE);

		// draw our texture to the screen
		DrawTexture(wabbit, 400, 200, WHITE);
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	UnloadTexture(wabbit);

	CloseWindow();
	return 0;
}