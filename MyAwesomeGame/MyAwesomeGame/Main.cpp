#include "../SDL/include/SDL.h"
#include <iostream>
#include <time.h>

#pragma comment (lib,"../SDL/libx86/SDL2.lib")
#pragma comment (lib,"../SDL/libx86/SDL2main.lib")

#define SCREENWITDH 640
#define SCREENHEIGHT 480
#define RECTWITDH 40
#define RECTHEIGHT 20

int main (int argc, char* argv[])
{
	SDL_Window * window;
	SDL_Renderer* renderer;
	SDL_Rect rect;
	SDL_Event event;
	bool playing;
	bool hasMoved;
	int randNum;
	bool keyPressed[323] = { false };

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("MyAwesomeGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWITDH, SCREENHEIGHT, SDL_WINDOW_OPENGL);
	if(window == NULL)
	{
		std::cout<<"Window not created"<<SDL_GetError<<std::endl;
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	
	rect.x = 0;
	rect.y = 0;
	rect.w = RECTWITDH;
	rect.h = RECTHEIGHT;
	
	playing = true;

	srand(time(NULL));

	while(playing == true)
	{
		//Commands
		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				playing = false;
			}
			if(event.type == SDL_KEYDOWN)
			{
				keyPressed[event.key.keysym.sym] = true;
			}
			if(event.type == SDL_KEYUP)
			{
				keyPressed[event.key.keysym.sym] = false;
			}
		}

		if(keyPressed[SDLK_UP] == true)
		{
			rect.y--;
		}
		if (keyPressed[SDLK_LEFT] == true)
		{
			rect.x--;
		}
		if (keyPressed[SDLK_DOWN] == true)
		{
			rect.y++;
		}
		if (keyPressed[SDLK_RIGHT] == true)
		{
			rect.x++;
		}

		//Mirar que no surti de la pantalla

		//Rendering
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);

		SDL_RenderPresent(renderer);
	}


	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}