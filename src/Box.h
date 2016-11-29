#ifndef BOX_H_
#define	BOX_H_

#include <flat/flat.h>
#include <map>

class Box : public flat2d::Entity
{
	private:
		std::map<SDL_Keycode, bool> activeKeys;

	public:
		Box(int x, int y) : Entity(x, y, 20, 20) {
			entityProperties.setCollidable(true);
			setInputHandler(true);
		}

		void init(const flat2d::GameData *gameData) override;
		void handle(const SDL_Event& event) override;
		void preMove(const flat2d::GameData *gameData) override;
};

#endif // BOX_H_
