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
	bool pressingUp = false;
	bool pressingLeft = false;
	bool pressingDown = false;
	bool pressingRight = false;

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
				if (event.key.keysym.sym == SDLK_UP)
				{
					pressingUp = true;
				}
				if (event.key.keysym.sym == SDLK_LEFT)
				{
					pressingLeft = true;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					pressingDown = true;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					pressingRight = true;
				}
				if(event.key.keysym.sym == SDLK_SPACE)
				{
					projectile.x = rect.x + RECTWITDH / 2;
					projectile.y = rect.y + RECTHEIGHT / 2;
				}
			}
			if (event.type == SDL_KEYUP)
			{
				if(event.key.keysym.sym == SDLK_UP)
				{
					pressingUp = false;
				}
				if (event.key.keysym.sym == SDLK_LEFT)
				{
					pressingLeft = false;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					pressingDown = false;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					pressingRight = false;
				}
			}
		}

		//Movement
		if (pressingUp == true && rect.y > 0)
		{
			rect.y--;
		}
		if (pressingLeft == true && rect.x > 0)
		{
			rect.x--;
		}
		if (pressingDown == true && rect.y < SCREENHEIGHT - RECTHEIGHT)
		{
			rect.y++;
		}
		if (pressingRight == true && rect.x < SCREENWITDH - RECTWITDH)
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

	//Quit
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}