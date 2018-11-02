#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

#include "file.h"

namespace si{

class Square{
public:
	Square(int xpos, int ypos, int with, int height):x(xpos),y(ypos),w(with),h(height){};
	Square():x(0),y(0),w(0),h(0){};
	int x;
	int y;
	int w;
	int h;
};

class Entity{
public:
	Entity(std::string filepath);
	Square square;
	int textureid;
	void move(int i);
	virtual void update() = 0;
	//virtual ~Entity() ;
	
};

}



#endif
