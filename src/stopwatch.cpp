#include "stopwatch.h"

si::stopwatch::Stopwatch::Stopwatch(){
	clock = sf::Clock();
	clock.restart();
}

int si::stopwatch::Stopwatch::getelapsed(){
	sf::Time time = clock.getElapsedTime();
	clock.restart();
	return time.asMicroseconds();	
}

void si::stopwatch::Stopwatch::start(){
	clock.restart();	
}

int si::stopwatch::Stopwatch::get(){
	sf::Time time = clock.getElapsedTime();
	return time.asMicroseconds();	
}
