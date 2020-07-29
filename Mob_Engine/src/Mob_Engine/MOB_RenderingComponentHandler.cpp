#include "MOB_RenderingComponentHandler.h"


MOB_RenderingComponentHandler::MOB_RenderingComponentHandler(SDL_Window* window) {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

MOB_RenderingComponentHandler::~MOB_RenderingComponentHandler() {
	SDL_DestroyRenderer(_renderer);
}


void MOB_RenderingComponentHandler::start() {

}

SDL_Texture* MOB_RenderingComponentHandler::loadTexture(std::string filePath) {
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	if (loadedTextures.count(filePath) == 0) {
		surface = IMG_Load(filePath.c_str());
		texture = SDL_CreateTextureFromSurface(_renderer, surface);
		if (surface == NULL) {
			printf("Could not load file at path: %s. \n", filePath.c_str());
			return NULL;
		}
		if (texture == NULL) {
			printf("Could not assign texture from surface \n");
			return NULL;
		}
		loadedTextures.emplace(filePath, texture);
	}
	else {
		texture = loadedTextures.at(filePath);
		if (texture == NULL) {
			printf("Could not load file at path: %s. \n", filePath.c_str());
			return NULL;
		}
	}
	SDL_FreeSurface(surface);
	return texture;
}


void MOB_RenderingComponentHandler::clear() {
	SDL_RenderClear(_renderer);
}

void MOB_RenderingComponentHandler::flip() {
	SDL_RenderPresent(_renderer);
}


void MOB_RenderingComponentHandler::frameUpdate() {
	clear();
	MOB_TransformComponent transform = NULL;
	for (int i = 0; i < renderingComponentList.size(); i++) {
		transform = MOB_TransformComponentHandler::fetchTransform(renderingComponentList[i].gameObject->getName());
		renderingComponentList[i].renderGameObject(_renderer, &transform);
	}
	flip();
}

void MOB_RenderingComponentHandler::changeRenderBackgroundColor(int r, int g, int b) {
	SDL_SetRenderDrawColor(_renderer, r, g, b, 0xff);
}