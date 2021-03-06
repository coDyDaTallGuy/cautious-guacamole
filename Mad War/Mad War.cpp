// Mad War.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

int main(int argc, char* argv[])
{
	// Declarations and pointers
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Event event;
	SDL_Rect rect_1, rect_2, rect_3, rect_g, rect_pic1, rect_test1;
	SDL_Surface *screen_surface = NULL;
	

	//Screen dimensions
	const int SCREEN_WIDTH = 1920;
	const int SCREEN_HEIGHT = 1080;

	SDL_Init(SDL_INIT_EVERYTHING);	// Initialize SDL2
	IMG_Init(IMG_INIT_PNG);		// Initialize SDL_image png 

	//Creates an application window 
	window = SDL_CreateWindow(
		"Mad War",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_OPENGL
	);

	//First rectangle
	rect_1.w = 120;
	rect_1.h = 100;
	rect_1.x = 760;
	rect_1.y = SCREEN_HEIGHT / 2;

	//Second rectangle
	rect_2.w = 120;
	rect_2.h = 100;
	rect_2.x = SCREEN_WIDTH / 2;
	rect_2.y = SCREEN_HEIGHT / 2;

	//Third rectange
	rect_3.w = 120;
	rect_3.h = 100;
	rect_3.x = 206;
	rect_3.y = SCREEN_HEIGHT / 2;

	//Ground rectangle //Change this to a 2D texture
	rect_g.w = SCREEN_WIDTH;
	rect_g.h = 160;
	rect_g.x = 0;
	rect_g.y = 920;

	//Character test rectangle
	rect_test1.w = 10;
	rect_test1.h = 30;
	rect_test1.x = 750;
	rect_test1.y = SCREEN_HEIGHT / 2;



	


	//Rectangle array
/*	SDL_Rect[rect_1, rect_2, ];			//	SDL_RenderDrawRects(renderer, &)	*/
		
	//Creates renderer for use in the window
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	//Texture 
	texture = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET,
		1920,
		1080
	); 

	
	

	// Checks if window was created successfully
	if (window == NULL)
	{
		std::cout << "Error could not create window" << SDL_GetError();
		return 1;
	}

	//Keeps the window open until you Quit
	while (1)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			break;

//NOTE: Put rectangels into an array and make use of SDL_RenderDrawRects
		//Setting background color
		SDL_SetRenderTarget(renderer, texture);
		SDL_SetRenderDrawColor(renderer, 134, 177, 206, 255);
		SDL_RenderClear(renderer);

		//Rendering the rectangles		//Purple
		SDL_RenderDrawRect(renderer, &rect_1);
		SDL_SetRenderDrawColor(renderer, 118, 96, 139, 255);
		SDL_RenderFillRect(renderer, &rect_1);

		SDL_RenderDrawRect(renderer, &rect_2);
		SDL_SetRenderDrawColor(renderer, 49, 91, 139, 255);
		SDL_RenderFillRect(renderer, &rect_2);

		SDL_RenderDrawRect(renderer, &rect_3);
		SDL_SetRenderDrawColor(renderer, 118, 96, 139, 255);
		SDL_RenderFillRect(renderer, &rect_3);

		//Ground Rectangle
		SDL_RenderDrawRect(renderer, &rect_g);
		SDL_SetRenderDrawColor(renderer, 103, 113, 91, 255);
		SDL_RenderFillRect(renderer, &rect_g);

		//Test Rectangle
		SDL_RenderDrawRect(renderer, &rect_test1);
		
		
		


		//Key event testing		//scrolling up or down currently increases or decreases rect sizes

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEWHEEL)
			{
				if (event.wheel.y > 0)
				{
					rect_2.h++ * 2;
				}

				if (event.wheel.y < 0)
				{
					rect_2.h-- * 2;
				}
			}
			
			//moving objects with keyboard and menu creations
			SDL_PumpEvents();	
			const Uint8* keys = SDL_GetKeyboardState(NULL);

			if (keys[SDL_SCANCODE_LEFT]) rect_test1.x -= 20;
			if (keys[SDL_SCANCODE_RIGHT]) rect_test1.x += 20;
			if (keys[SDL_SCANCODE_DOWN]) rect_test1.y += 20;
			if (keys[SDL_SCANCODE_UP]) rect_test1.y -= 20;
			



		}




		SDL_SetRenderTarget(renderer, NULL);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		
	}
	

	// Clean up
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}

