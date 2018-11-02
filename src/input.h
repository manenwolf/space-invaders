#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

namespace si{
namespace input{

class Input{
public:
	bool space();//returns if the space key is down
	bool escape();//returns if the escape key is down
	bool left();//returns if the left key is down
	bool right();//returns if the right key is down
	bool enter();//returns if the enter key is down
};

}
}


#endif
