#include "bullet.h"

si::Bullet::Bullet(std::string filepath):Entity(filepath){
	//std::cout << "making new bullet" << std::endl;
	si::file::File input(filepath);
	speed = input.getint("speed");
}

void si::Bullet::update(){
	if(square.y !=480){
		square.y += speed;
	}
	if(square.y < 0){
		square.y = 480;
	}
	
}
