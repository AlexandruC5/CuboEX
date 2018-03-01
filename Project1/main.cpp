#include "stdio.h"
#include "/Users/alexa/Desktop/CuboEX/SDL/include/SDL.h"
#pragma comment(lib, "/Users/alexa/Desktop/CuboEX/SDL/libx86/SDL2.lib")
#pragma comment(lib, "/Users/alexa/Desktop/CuboEX/SDL/libx86/SDL2main.lib")

using namespace std;

Uint32 WIDTH = 720;
Uint32 HEIGHT = 480;



void mR(SDL_Rect *r, Uint32 &rs) {

	if (rs == 0)
	{
		if (r->y > HEIGHT - r->w) {
			rs = 1;
		}
		else r->y += 5;

	}
	else {
		if (r->y <= 0) {
			rs = 0;
		}
		else r->y -= 5;
	}

}





int main(int argc, char* argv[]) {

	SDL_Window *win;
	SDL_Renderer *rend = NULL;
	Uint32 rs = 0;

	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow(
		"Cube",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		720,
		480,
		SDL_WINDOW_RESIZABLE
	);

	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);

	SDL_Rect *r = new SDL_Rect();
	r->h = 100;
	r->w = 100;
	r->x = (WIDTH / 2) - r->w / 2;
	r->y = HEIGHT / 2 - (r->h / 2);

	while (1) {

		SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
		SDL_RenderClear(rend);
		mR(r, rs);
		SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
		SDL_RenderFillRect(rend, r);
		SDL_RenderPresent(rend);

	} SDL_DestroyWindow(win);

	SDL_Quit();

	return 0;
}