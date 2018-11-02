#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <vector>
#include <array>

#include "entity.h"
#include "player.h"
#include "enemy.h"



namespace si{
namespace model{

class Model{
public:
	static Model* getinstance();
	~Model();
	void setplayer(std::string filepath);
	si::Bullet* playerbullet = new si::Bullet("../resources/bullet.xml");
	Player* player = nullptr;
	std::vector<Entity*> entities;
	std::array<std::array<Enemy*,5>,10> enemies;
	si::Enemy* enemycollision();
	void deleteenemy(si::Enemy* e);
	std::vector<si::Bullet*> bullets;
	bool playercollision();
private:
	Model();
	bool collision(si::Square sprite_1, si::Square sprite_2);

	
};

}
}



#endif
