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
	bool playing;
	bool hasMoved;
	int randNum;


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
		do
		{
			hasMoved = 0;
			randNum = rand() % 4;
			if (randNum == 0 && rect.x < SCREENWITDH - RECTWITDH)
			{
				rect.x++;
				hasMoved = 1;
			}
			else if(randNum == 1 && rect.y < SCREENHEIGHT - RECTHEIGHT)
			{
				rect.y++;
				hasMoved = 1;
			}
			else if (randNum == 2 && rect.x > 0)
			{
				rect.x--;
				hasMoved = 1;
			}
			else if (randNum == 3 && rect.y > 0)
			{
				rect.y--;
				hasMoved = 1;
			}
		} while (hasMoved = 0);

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