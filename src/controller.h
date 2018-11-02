#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <cmath>

#include "model.h"
#include "view.h"
#include "input.h"
#include "stopwatch.h"
#include "world.h"

namespace si{
namespace controller{

class Controller{
public:
	Controller();
	void startscreen();
	void run();
	void endscreen();
private:
	si::model::Model* mymodel = si::model::Model::getinstance();
	si::view::View myview = si::view::View();
	si::input::Input myinput = si::input::Input();
	si::stopwatch::Stopwatch frametime = si::stopwatch::Stopwatch();
	void controlframerate(int elapse);
	const int maxframerate = 24;
	si::World* myworld = new si::World("../resources/world.xml");
	
};

}
}


#endif
