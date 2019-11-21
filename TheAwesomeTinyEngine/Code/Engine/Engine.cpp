#include "Engine.h"
#include <chrono>
#include "SDL_image.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
struct InputState {
	bool  bIsPressed;
	int _frameNumber;
};

static SDL_Window* _window;
static SDL_Renderer* _renderer;

static SDL_Color _currentColor = { 255,255,255,255 };

static bool bIsEngineOpen = true;

std::chrono::high_resolution_clock::time_point _lastFrameTime;
static float _frameDelta = 0.f;
static InputState keyStates[(unsigned int)Key::MAX];
int _currentFrameNumber = 1;


void InitializeEngine()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	_window = SDL_CreateWindow("Tiny Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
	_renderer = SDL_CreateRenderer(_window, -1, 0);
	_lastFrameTime = std::chrono::high_resolution_clock::now();
	bIsEngineOpen = true;
}

void UpdateEngine()
{
	_currentFrameNumber++;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			CloseEngine();
		}

		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.repeat == 0){
				InputState& state = keyStates[event.key.keysym.scancode];
				state.bIsPressed = true;
				state._frameNumber = _currentFrameNumber;
			}
		}

		if (event.type == SDL_KEYUP) {
			InputState& state = keyStates[event.key.keysym.scancode];
			state.bIsPressed = false;
			state._frameNumber = _currentFrameNumber;
		}
	}
	/*to calculate time I'm using the std::chrono voodoo,
	it doesn't need to look this bad but for the sake of clarity
	I'm avoiding namespaces and the using macro*/
	std::chrono::high_resolution_clock::time_point CurrentTime = std::chrono::high_resolution_clock::now();

	_frameDelta = std::chrono::duration_cast<std::chrono::microseconds>(CurrentTime - _lastFrameTime).count() * 1e-6f;// 10^6 microseconds in a second

	_lastFrameTime = CurrentTime;
	SDL_RenderPresent(_renderer);
	ClearEngine();

}

void ClearEngine()
{
	SDL_SetRenderDrawColor(_renderer, 132, 123, 132, 0);
	SDL_RenderClear(_renderer);
}

void CloseEngine()
{
	bIsEngineOpen = false;
}

void DestroyEngine()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);

	_renderer = nullptr;
	_window = nullptr;
	SDL_Quit();
}

bool IsEngineOpen()
{
	return bIsEngineOpen;
}

void RenderSquare(float posX, float posY, int width, int height)
{
	SDL_SetRenderDrawColor(_renderer, _currentColor.r, 
		_currentColor.g, _currentColor.b, _currentColor.a);
	SDL_FRect Rect = { posX, posY, width, height };
	SDL_RenderFillRectF(_renderer, &Rect);
}

bool EngineGetKey(Key key)
{
	return keyStates[(int)key].bIsPressed;
}

bool EngineGetKeyDown(Key key)
{
	InputState& state = keyStates[(int)key];
	return state.bIsPressed && state._frameNumber == _currentFrameNumber;
}

float EngineDeltaTime()
{
	return _frameDelta;
}

SDL_Renderer* EngineGetRenderer()
{
	return _renderer;
}

void EngineSetColor(int r, int g, int b, int a)
{
	_currentColor.r = r;
	_currentColor.g = g;
	_currentColor.b = b;
	_currentColor.a = a;
}

void EngineLoadTexture(float posX, float posY, int height, int width, const char* _path)
{
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* tempSurface = IMG_Load(_path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, tempSurface);

	if (_path == nullptr) {
		puts("failed to find path!");
	}

	//SDL_GetRenderDrawColor(_renderer, &_currentColor.r, &_currentColor.g, &_currentColor.b, &_currentColor.a);
	SDL_Rect rect = { posX, posY, width, height };
	SDL_Rect src{ 0,0,tempSurface->w, tempSurface->h };
	SDL_RenderCopy(_renderer, texture, &src, &rect);

	SDL_FreeSurface(tempSurface);
	SDL_DestroyTexture(texture);
}
