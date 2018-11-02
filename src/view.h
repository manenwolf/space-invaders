#ifndef VIEEW_H
#define VIEEW_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include "model.h"
#include "file.h"

namespace si{
namespace view{

class View{
public:
	View();
    ~View();
    void showscreen(std::string filename);
    void start();
    void end();
    void drawtext(std::string message, int x, int y);
	void loadtextures(std::string filepath);
    void drawtexture(int textureid, int x, int y);
	void drawgame();
	int maxframerate;
private:
    sf::RenderWindow* window;
    sf::Font font;
    si::model::Model* mymodel = si::model::Model::getinstance();
    int screenwith;
    int screenheight;
    std::vector<sf::Texture*> textures;
};

}
}


#endif
