#include <iostream>
#include "BigBox.h"

void BigBox::init(const flat2d::GameData *gameData)
{
	std::cout << "Initiating BigBox" << std::endl;
	flat2d::Texture *texture = new flat2d::Texture();
	texture->loadFromFile("resources/bigbox.png", gameData->getRenderData()->getRenderer());
	setTexture(texture);
}
