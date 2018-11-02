#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <SFML/Graphics.hpp>

namespace si{
namespace stopwatch{

class Stopwatch{
public:
	Stopwatch();//creates an new instance of the class
	int getelapsed();//gets the time sinds last reset  in microseconds and calls a reset
	void start();//resets the time
	int get();//gets the time sinds last reset in microseconds
private:
	sf::Clock clock;
};

}
}



#endif
