#include <iostream>
#include <vector>
#include "BigBox.h"

void BigBox::init(const flat2d::GameData *gameData)
{
	std::cout << "Initiating BigBox" << std::endl;
	flat2d::Texture *texture = new flat2d::Texture();
	texture->loadFromFile("resources/bigbox.png", gameData->getRenderData()->getRenderer());
	setTexture(texture);

	std::vector<SDL_Rect> frames = {
		{ 0, 0, 60, 60 },
		{ 60, 0, 60, 60 }
	};

	addAnimation("blink", new flat2d::Animation(frames, 200));
	startAnimation("blink");
}
