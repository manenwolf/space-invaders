#include "model.h"

si::model::Model* si::model::Model::getinstance(){
	
	static Model* instance = nullptr;

	if(instance == nullptr){
		instance = new Model();
	}
	return instance;
}

si::model::Model::Model(){
	std::cout << "initiating model" << std::endl;
}

si::model::Model::~Model(){
	
}
void si::model::Model::setplayer(std::string filepath){
	si::Player* newplayer = new si::Player(filepath);
	player = newplayer;
	entities.push_back(newplayer);
	playerbullet  = new si::Bullet("../resources/bullet.xml");
	playerbullet->speed *=-1;
	entities.push_back(playerbullet);
	
}

si::Enemy* si::model::Model::enemycollision(){
	si::Square s = playerbullet->square;
	for(int i = 0;i<5;i++){
		for(int j = 0;j<10;j++){
			if(enemies[j][i] != nullptr){
				si::Square o = enemies[j][i]->square;
				if(collision(s,o)){
					return enemies[j][i];
				}
			}
		}
	}
	return nullptr;
}
bool si::model::Model::playercollision(){
	for(unsigned int i = 0;i<bullets.size();i++){
		if(collision(bullets[i]->square,player->square)){
			return true;	
		}
	}
	return false;
}

class undefinedenemy{};
void si::model::Model::deleteenemy(si::Enemy* e){

	bool found1 = false;
	bool found2 = false;

	for(int i = 0;i<5;i++){
		for(int j = 0;j<10;j++){
			if(enemies[j][i] == e){
				enemies[j][i] = nullptr;
				found1 = true;
				break;
			}
		}
	
	}
	for(std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
    		if(*it == e){
			entities.erase(it);
			found2 = true;
			break;
		}
	}
	if(found1 == false or found2 == false){
		throw(undefinedenemy());
	}else{
		//delete e;
	}	
}

bool si::model::Model::collision(si::Square sprite_1, si::Square sprite_2){
//code taken from http://www.cplusplus.com/forum/beginner/41827/

  //Let's examine the x axis first:
  //If the leftmost or rightmost point of the first sprite lies somewhere inside the second, continue.
  if( (sprite_1.x >= sprite_2.x && sprite_1.x <= (sprite_2.x + sprite_2.w)) ||
      ((sprite_1.x + sprite_1.w) >= sprite_2.x && (sprite_1.x + sprite_1.w) <= (sprite_2.x + sprite_2.w)) ){
    //Now we look at the y axis:
    if( (sprite_1.y >= sprite_2.y && sprite_1.y <= (sprite_2.y + sprite_2.h)) ||
        ((sprite_1.y + sprite_1.h) >= sprite_2.y && (sprite_1.y + sprite_1.h) <= (sprite_2.y + sprite_2.h)) ){
      //The sprites appear to overlap.
      return true;
    }
  }
  //The sprites do not overlap:
  return false;
}
