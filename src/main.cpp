#include <SFML/Graphics.hpp>
#include <iostream>
#include "controller.h"

int main()
{
	std::cout << std::endl << std::endl 
			       << "<---start of main function" 
			       << std::endl << std::endl; 


	si::controller::Controller mycontroller;
	mycontroller.startscreen();
	mycontroller.run();
	mycontroller.endscreen();

	
	std::cout << std::endl << std::endl 
		               << "<---end of main function" 
		               << std::endl << std::endl; 

	return 0;
}
