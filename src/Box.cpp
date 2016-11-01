#include <iostream>
#include <vector>
#include <flat/flat.h>
#include "Box.h"

void Box::init(const flat2d::GameData *gameData)
{
	std::cout << "Initiating Box" << std::endl;

	// Initiate the keys we will use
	activeKeys[SDLK_LEFT] = false;
	activeKeys[SDLK_RIGHT] = false;
	activeKeys[SDLK_UP] = false;
	activeKeys[SDLK_DOWN] = false;

	// Load the texture
	flat2d::Texture *texture = new flat2d::Texture();
	texture->loadFromFile("resources/box.png", gameData->getRenderData()->getRenderer());
	setTexture(texture);

	std::vector<SDL_Rect> frames = {
		{ 0,	0,	20,	20 },
		{ 20,	0,	20,	20 },
		{ 40,	0,	20,	20 },
		{ 60,	0,	20,	20 }
	};
	addAnimation("rotate", new flat2d::Animation(frames, 200));
	startAnimation("rotate");
}

void Box::handle(const SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN) {
		activeKeys[e.key.keysym.sym] = true;
	} else if (e.type == SDL_KEYUP) {
		activeKeys[e.key.keysym.sym] = false;
	}
}

void Box::preMove(const flat2d::GameData *gameData)
{
	// Every frame we reset the velocity
	entityProperties.setXvel(0);
	entityProperties.setYvel(0);

	// And then set it based on active keys
	if (activeKeys[SDLK_LEFT]) {
		entityProperties.setXvel(-300);
	}

	if (activeKeys[SDLK_RIGHT]) {
		entityProperties.setXvel(300);
	}

	if (activeKeys[SDLK_UP]) {
		entityProperties.setYvel(-300);
	}

	if (activeKeys[SDLK_DOWN]) {
		entityProperties.setYvel(300);
	}
}
