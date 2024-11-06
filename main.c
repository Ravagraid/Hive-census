/* Copyright(c) 2024 James Gardner. All Rights Reserved. */

#include "include/cJSON.h"
#include "include/raylib.h"
#include "include/resource_dir.h"
#include <stdio.h>
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)
#define WINDOW_TITLE "Death to the Spyrers!"

int main(void) {
  // create a cJSON object
  cJSON *json = cJSON_CreateObject();
  cJSON_AddStringToObject(json, "name", "John Doe");
  cJSON_AddNumberToObject(json, "age", 30);
  cJSON_AddStringToObject(json, "email", "john.doe@example.com");
  // convert the cJSON object to a JSON string
  char *json_str = cJSON_Print(json);

  // write the JSON string to a file
  FILE *fp = fopen("data.json", "w");
  if (fp == NULL) {
    printf("Error: Unable to open the file.\n");
    return 1;
  }
  printf("%s\n", json_str);
  fputs(json_str, fp);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  SearchAndSetResourceDir("resources");
  Font font = LoadFont("ShureTechMonoNerdFontMono-Regular.ttf");
  // game loop
  while (!WindowShouldClose()) {
    // drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);

    const char *text = WINDOW_TITLE;
    const Vector2 text_size = MeasureTextEx(font, text, 20, 1);
    DrawTextEx(
        font, text,
        (Vector2){SCREEN_WIDTH / 2 - text_size.x / 1.25, text_size.y + 10},
        (float)font.baseSize, 1, BLACK);
    EndDrawing();
  }

  fclose;
  cJSON_free(json_str);
  cJSON_Delete(json);
  CloseWindow();
  return 0;
}
