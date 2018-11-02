#include "view.h"


si::view::View::View(){
	std::cout << "making the renderwindow" << std::endl;
	
	//reading in information for creating the screen from a file
	si::file::File screenspecs;
	try{
		screenspecs.load("../resources/screenspecs.xml");
	}catch(si::file::incorectfile){
		std::cout << "could not open file screenspecs.xml" << std::endl;
	}
	//reading in of screenwith
	try{
		maxframerate = screenspecs.getint("framerate");
	}catch(si::file::inputerror){
		std::cout << "could not read in framerate using 24 as default" << std::endl;
		maxframerate = 24;
	}
	try{
		screenwith = screenspecs.getint("screenwith");
	}catch(si::file::inputerror){
		std::cout << "could not read in screenwith using 640 as default" << std::endl;
		screenwith = 640;
	}
	
	//reading in of screenheight
	try{
		screenheight = screenspecs.getint("screenheight");
	}catch(si::file::inputerror){
		std::cout << "could not read in screenheigt using 480 as default" << std::endl;
		screenheight = 480;
	}
	
	//actual creating of the window
	std::cout << "creating a new window of size: " << screenwith << "," << screenheight << std::endl;
	try{
		window = new sf::RenderWindow(sf::VideoMode(screenwith, screenheight), "dieter's space invaders game");
	}catch(...){
		std::cout << "someting whent wrong when creating window" << std::endl;
		throw;
	}
	
	//loading in of the font
	std::string fontlocation;
	try{
		fontlocation = screenspecs.getstring("font");
	}catch(si::file::inputerror){
		std::cout << "could not read in the font using ../resources/spaceage.ttf as default" << std::endl;
		fontlocation = "../resources/spaceage.ttf";
	}
	if(!font.loadFromFile(fontlocation)){
		std::cout << "could not load font: " << fontlocation << std::endl;
	}
	
}

void si::view::View::start(){
window->clear();
}

void si::view::View::end(){
window->display();
}

void si::view::View::showscreen(std::string filename){
 	sf::Texture texture;
	
	if(! texture.loadFromFile(filename)){
		std::cout << "could not load file: " << filename << std::endl;
	}

 	sf::Sprite sprite;
 	sprite.setTexture(texture);
	
	window->draw(sprite);
	
}

void si::view::View::drawtext(std::string message , int x, int y){
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(18);	
	text.setString(message);
	text.setPosition(x,y);
	text.setColor(sf::Color::Red);
	window->draw(text);
}


si::view::View::~View(){
	std::cout << "deleting the renderwindow" << std::endl;
	delete window;
}

class loaderror{};
void si::view::View::loadtextures(std::string filepath){
	std::cout << "start loading textures" << std::endl;
	si::file::File input(filepath);
	

	int numtextures;
	try{
		numtextures = input.getint("numtextures");
	}catch(si::file::inputerror){
		std::cout << "could not load in the number of textures -> loading of textures canceled" << std::endl;
		throw(loaderror());
	}
	for(int i = 0;i < numtextures;i++){
		sf::Texture* t = new sf::Texture();
		std::string filename = input.getstring("t"+std::to_string(i));
		if(! t->loadFromFile(filename)){
			std::cout << "could not load file: " << filename << std::endl;
			throw(loaderror());
		}
		std::cout << "loading texture" << filename << std::endl;

		textures.push_back(t);
		
	}
	std::cout << "end loading textures" << std::endl;
}

void si::view::View::drawtexture(int textureid, int x, int y){
	if(textureid >= textures.size()){
		std::cout << "undefined texture id: " << textureid << std::endl;
	}
	sf::Sprite s;
	s.setTexture(*textures[textureid]);

	s.setPosition(x,y);
	window->draw(s);

}

void si::view::View::drawgame(){
	//draw all drawables
	if(mymodel->player == nullptr){
		std::cout << "no player" << std::endl;
	}
	for(unsigned int i;i< mymodel->entities.size();i++){
		int textureid = mymodel->entities[i]->textureid;
		si::Square s =  mymodel->entities[i]->square ;
		int x = s.x;
		int y = s.y;
		drawtexture(textureid,x,y);
	}
}


