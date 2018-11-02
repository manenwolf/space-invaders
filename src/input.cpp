#include "input.h"


bool si::input::Input::space(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}
bool si::input::Input::escape(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}

bool si::input::Input::left(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}
bool si::input::Input::right(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}
bool si::input::Input::enter(){
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Return);
}
