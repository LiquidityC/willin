#include <iostream>
#include <flat/flat.h>

#include "Box.h"
#include "BigBox.h"

int main(int argc, char* argv[])
{
	std::cout << "Loading Flat" << std::endl;
	flat2d::FlatBuilder *flat = new flat2d::FlatBuilder();
	flat->loadSDL("WilLin", 60, 800, 600);
	flat2d::GameEngine *engine = flat->getGameEngine();

	flat2d::EntityContainer *container = flat->getGameData()->getEntityContainer();
	container->registerObject(new Box(20, 20));
	container->registerObject(new BigBox(100, 100));

	// Create the callback methods
	auto stateCallback = [](flat2d::GameData *gameData) -> flat2d::GameStateAction {
		return flat2d::GameStateAction::NOOP;
	};
	auto handleCallback = [](const SDL_Event& event) -> void {
		// Nothing to do here
	};

	std::cout << "Starting the engine" << std::endl;
	engine->run(stateCallback, handleCallback);
	std::cout << "Exiting" << std::endl;

	delete flat;
}
