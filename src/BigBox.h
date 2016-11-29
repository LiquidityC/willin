#ifndef BIGBOX_H_
#define	BIGBOX_H_

#include <flat/flat.h>

class BigBox : public flat2d::Entity
{
	public:
		BigBox(int x, int y) : Entity(x, y, 60, 60) {
			entityProperties.setCollidable(true);
			setInputHandler(false);
		}

		void init(const flat2d::GameData *gameData) override;
};

#endif // BIGBOX_H_
