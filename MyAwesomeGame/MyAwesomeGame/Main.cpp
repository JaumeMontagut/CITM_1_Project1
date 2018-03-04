#include "../SDL/include/SDL.h"
#include <iostream>
#include "Header.h"
#pragma comment (lib,"../SDL/libx86/SDL2.lib")
#pragma comment (lib,"../SDL/libx86/SDL2main.lib")

int main (int argc, char* argv[])
{
	//Declaration
	SDL_Window * window;
	SDL_Renderer* renderer;
	SDL_Rect rect;
	SDL_Rect projectile;
	SDL_Event event;
	bool playing;
	bool pressingW = false;
	bool pressingA = false;
	bool pressingS = false;
	bool pressingD = false;

	//Inicialization
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
	projectile.x = SCREENWITDH;
	projectile.y = SCREENHEIGHT;
	projectile.w = 10;
	projectile.h = 5;
	playing = true;

	while(playing == true)
	{
		//Input
		while (SDL_PollEvent(&event) != 0)
		{
			if(event.type == SDL_QUIT)
			{
				playing = false;
			}
			if(event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_w)
				{
					pressingW = true;
				}
				if (event.key.keysym.sym == SDLK_a)
				{
					pressingA = true;
				}
				if (event.key.keysym.sym == SDLK_s)
				{
					pressingS = true;
				}
				if (event.key.keysym.sym == SDLK_d)
				{
					pressingD = true;
				}
				if(event.key.keysym.sym == SDLK_SPACE)
				{
					projectile.x = rect.x + RECTWITDH / 2;
					projectile.y = rect.y + RECTHEIGHT / 2;
				}
			}
			if (event.type == SDL_KEYUP)
			{
				if(event.key.keysym.sym == SDLK_w)
				{
					pressingW = false;
				}
				if (event.key.keysym.sym == SDLK_a)
				{
					pressingA = false;
				}
				if (event.key.keysym.sym == SDLK_s)
				{
					pressingS = false;
				}
				if (event.key.keysym.sym == SDLK_d)
				{
					pressingD = false;
				}
			}
		}

		//Movement
		if (pressingW == true && rect.y > 0)
		{
			rect.y--;
		}
		if (pressingA == true && rect.x > 0)
		{
			rect.x--;
		}
		if (pressingS == true && rect.y < SCREENHEIGHT - RECTHEIGHT)
		{
			rect.y++;
		}
		if (pressingD == true && rect.x < SCREENWITDH - RECTWITDH)
		{
			rect.x++;
		}

		if(projectile.x <= SCREENWITDH)
		{
			projectile.x++;
		}

		//Rendering
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &projectile);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}