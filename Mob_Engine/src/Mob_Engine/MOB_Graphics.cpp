#include "MOB_Graphics.h"
#include "MOB_Sprite.h"


MOB_Graphics::MOB_Graphics() {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	this->_window = SDL_CreateWindow("Blacksmith game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 600, SDL_WINDOW_SHOWN);

	this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
}

MOB_Graphics::~MOB_Graphics() {
	SDL_DestroyWindow(_window);
	
	SDL_DestroyRenderer(_renderer);
	
	loadedTextures.clear();

	drawables.clear();


	SDL_Quit();
}

void MOB_Graphics::renderObject(MOB_GameObject* gameObject) {
	SDL_Texture* tex = loadTexture(_renderer, gameObject->getGraphicFilePath());
	MOB_Sprite* newSprite = new MOB_Sprite(tex, gameObject->getGraphicW(), gameObject->getGraphicH());
	drawables.emplace(gameObject->getName(), newSprite);
}


SDL_Texture* MOB_Graphics::loadTexture(SDL_Renderer* renderer, std::string filePath){
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	if (loadedTextures.count(filePath) == 0) {
		surface = IMG_Load(filePath.c_str());
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (surface == NULL) {
			printf("Could not load file at path: %s. \n", filePath.c_str());
			return NULL;
		}
		if (texture == NULL) {
			printf("Could not assign texture from surface \n");
			return NULL;
		}
		loadedTextures.emplace(filePath, texture);
	} else {
		texture = loadedTextures.at(filePath);
		if (texture == NULL) {
			printf("Could not load file at path: %s. \n", filePath.c_str());
			return NULL;
		}
	}
	SDL_FreeSurface(surface);
	return texture;
}

void MOB_Graphics::updateRenderLocation(std::string gameObjectName, int x, int y, int w, int h) {
	drawables.at(gameObjectName)->setDestinationRect(x, y, w, h);
}


void MOB_Graphics::blitSurfaces() {
	for (std::map<std::string, IDrawable*>::iterator it = drawables.begin(); it != drawables.end(); it++) {
		SDL_RenderCopy(_renderer, drawables[it->first]->getTexture(),
			&drawables[it->first]->getSrcRect(), &drawables[it->first]->getDestRect());
	}
}

void MOB_Graphics::clear() {
	SDL_RenderClear(_renderer);
}

void MOB_Graphics::flip() {
	SDL_RenderPresent(_renderer);
}

void MOB_Graphics::setDefaultRenderColor(int r, int g, int b) {
	SDL_SetRenderDrawColor(_renderer, r, g, b, 0xff);
}

void MOB_Graphics::graphicsUpdate() {
	clear();
	blitSurfaces();
	flip();
}