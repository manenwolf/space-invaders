#ifndef BULLET_H
#define BULLET_H

#include "entity.h"

namespace si{
class Bullet: public Entity{
public:
	Bullet(std::string filepath);
	void update();
	int speed;

};

}

#endif
