#include "controller.h"


//constructor of Controller
si::controller::Controller::Controller(){
    std::cout << "making of a new controller" << std::endl;
	//std::cout <<mymodel->drawables.size() << "------------------->" << std::endl;
}

void si::controller::Controller::startscreen(){
	
    int last = frametime.getelapsed();

    while(not (myinput.enter() or myinput.escape())){
	frametime.start();

        myview.start();
        myview.showscreen("../resources/startscreen.png");

        int framerate = round(1000000.0/(double)last) ;
        myview.drawtext("framerate: " + std::to_string(framerate),0,0);
        
	myview.end();
		
	controlframerate(frametime.get());
	last = frametime.get();
		
    }

}

void si::controller::Controller::endscreen(){

    while(not (myinput.enter() or myinput.escape()) ){
	frametime.start();

        myview.start();

        myview.drawtext("Game Over! score: " + std::to_string(myworld->getscore()),0,200);
        
	myview.end();
		
	controlframerate(frametime.get());
		
    }

}
void si::controller::Controller::run(){

	myview.loadtextures("../resources/textures.xml");
	
	int last = frametime.getelapsed();
	myworld->loadlvl("../resources/lvl1.xml");
    while(not myinput.escape()){

	if(myworld->endgame() == true){
		break;
	}

	frametime.start();
        //updating the game
        if(myinput.left()){
            myworld->leftkey();
        }
        if(myinput.right()){
            myworld->rightkey();
        }
	if(myinput.space()){
	    myworld->fire();
	}
	myworld->update();

	//shooting of enemys
	myworld->shoot();
	
        //drawing the gamestate
        myview.start();
        myview.drawgame();
		
        //calculating and drawing the framerate
        int framerate = round(1000000.0/(double)last) ;

        myview.drawtext("framerate: " + std::to_string(framerate),0,0);
        
	//myview.drawtext("lvl: " + std::to_string(myworld->lvlnr),250,0);
	myview.drawtext("score: " + std::to_string(myworld->getscore()),380,0);

	myview.end();
		
	controlframerate(frametime.get());
	last = frametime.get();
	if(myworld->alldead()){
		myworld->loadlvl("../resources/lvl1.xml");
	}	
    }


}

void si::controller::Controller::controlframerate(int elapse){
    int sparetime = (1000000 / myview.maxframerate) - elapse;
    if(sparetime < 0 ){
        //std::cout << "--lag--" << std::endl;
    }else{
        sf::Time  delaytime = sf::microseconds(sparetime);
		sf::sleep(delaytime);
    }
}
