#include "player.h"

si::Player::Player(std::string filepath): Entity(filepath){
	std::cout << "new player" << std::endl;
	si::file::File input(filepath);
	speed = input.getint("speed");
	hitpoints = input.getint("hitpoints");
};

void si::Player::move(int i){
	square.x += i*speed;
	if(square.x<0){
		square.x = 0;
	}
	if(square.x+square.w > 640){
		square.x = 640 - square.w;
	}
}
