#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "bullet.h"

namespace si{

class Player: public Entity{
public:
	Player(std::string filepath);
	void move(int i);
	void update(){};
	int hitpoints;
private:
	int speed;
};

}


#endif
