#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

namespace si{

class Enemy: public Entity{
public:
	Enemy(std::string filepath);
	void update(){};
};

}
#endif
