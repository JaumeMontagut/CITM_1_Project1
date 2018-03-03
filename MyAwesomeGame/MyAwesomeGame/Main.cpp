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
	bool pressingW = false;

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
		while (SDL_PollEvent(&event) != 0)
		{
			if(event.type == SDL_QUIT)
			{
				playing == false;
			}
			else if(event.type == SDL_KEYDOWN)//Només detecta el Keydown aixi
			{
				if(event.key.keysym.sym == SDLK_w)
				{
					rect.y--;
				}
				if(event.key.keysym.sym == SDLK_a)
				{
					rect.x--;
				}
				if(event.key.keysym.sym == SDLK_s)
				{
					rect.y++;
				}
				if(event.key.keysym.sym == SDLK_d)
				{
					rect.x++;
				}
			}
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