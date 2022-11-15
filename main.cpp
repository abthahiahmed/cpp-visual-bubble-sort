// Visualization of Bubble Sort Algorithm | Abthahi Ahmed Rifat
#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>

using namespace std;
SDL_Window *win = SDL_CreateWindow("Visualization of Bubble Sort | Abthahi Ahmed Rifat", SDL_WINDOWPOS_CENTERED, 100, 1000, 400, SDL_WINDOW_SHOWN);
SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
SDL_Event event;

int _mX, _mY;

int random(int a, int b){	
	return a + (rand() / (RAND_MAX / (b - a)));
}

void drawRect(SDL_Rect rect){
	SDL_RenderFillRect(ren, &rect);	
}

int main(int argc, char *argv[]){
	SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
	bool isRunning = true;
	
	int max = 200;
	
	int arr[max];
	for (int i = 0; i < max; i++)
		arr[i] = random(1, 380);
	
	
	int a = 0;
	int b = 0;
	
	while(isRunning){
		SDL_GetMouseState(&_mX, &_mY);
		SDL_PollEvent(&event);
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);
		
		if (b < (max - 1)){
			if (a < (max - 1)){
				a = a + 1;
			}else{
				b = b + 1;
				a = 0;
			}
		}
		
		if (arr[a + 1] < arr[a]){
			
			int tmp = arr[a + 1];
			arr[a + 1] = arr[a];
			arr[a] = tmp;
			
		}
		
		for (int i = 0; i < max; i++){
			SDL_SetRenderDrawColor(ren, 140, 140, 255, 255);
			drawRect({i * 5, 400 - arr[i], 2, arr[i]});
			SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
			drawRect({i * 5 - 2, 400 - arr[i] - 6, 4, 4});
		


		}
		
		drawRect({a * 5 - 6, 380 - arr[a], 12, 12});
		SDL_RenderPresent(ren);
		
		if (event.type == SDL_QUIT){
			isRunning = false;
		}

	}
	
	
	return 0;
}
