#ifndef WORLD_H
#define WORLD_H

#include "player.h"
#include "entity.h"
#include "model.h"
#include "file.h"
#include "stopwatch.h"
#include "random.h"
#include "bullet.h"

namespace si{

class World{
public:
	World(std::string filepath);
	void leftkey();
	void rightkey();
	void fire();
	void update();
	void loadlvl(std::string filepath);
	bool alldead();
	int getscore();
	bool endgame();
	void shoot();

private:
	si::model::Model* mymodel = si::model::Model::getinstance();
	si::stopwatch::Stopwatch time;
	int steptime;
	si::random::Random* random = si::random::Random::getinstance();
	int lvlnr = 0;
	int score = 10;
	int enemyx = 0;
	int enemyy = 40;
	bool end = false;
	bool enemiesdead = false;
	
};

}


#endif
