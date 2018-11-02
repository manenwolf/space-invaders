#include "entity.h"

si::Entity::Entity(std::string filepath){
	si::file::File input(filepath);
	int newx = input.getint("x");
	int newy = input.getint("y");
	int neww = input.getint("w");
	int newh = input.getint("h");
	square = Square(newx,newy,neww,newh);
	textureid = input.getint("textureid");
	
}
void si::Entity::move(int i){}


