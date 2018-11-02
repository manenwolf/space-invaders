#include "world.h"

si::World::World(std::string filepath){
	//opening the file and setting up new world object
	si::file::File inputfile;
	std::cout << "starting loading in of world" << std::endl;
	try{
		inputfile.load("../resources/world.xml");
	}catch(si::file::incorectfile){
		std::cout << "could not open file world.xml" << std::endl;
	}
	std::string playerpath;
	try{
		playerpath = inputfile.getstring("playerpath");
	}catch(si::file::inputerror){
		std::cout << "could not reading playerpath" << std::endl;
	}
	mymodel->setplayer(playerpath);

}

void si::World::leftkey(){
	//leftkey is pressed so move in left direction
	mymodel->player->move(-1);
}
void si::World::rightkey(){
	//rightkey is pressed so move in right direction
	mymodel->player->move(1);
}
void si::World::fire(){
	//if bullet is ready for firing then start the bullet 
	if(mymodel->playerbullet->square.y == 480){
		mymodel->playerbullet->square.y = 400;
		mymodel->playerbullet->square.x = mymodel->player->square.x + (mymodel->player->square.w - mymodel->playerbullet->square.w)/2;	
	}
}

void si::World::update(){

	//calling update function of all entities
	for(unsigned int i = 0;i < mymodel->entities.size();i++){
		mymodel->entities[i]->update();
	}

	//delete al enemys that are hit
	si::Enemy* e = mymodel->enemycollision();
	if(e!=nullptr){
		//std::cout << "---------enemy hit ------------" << std::endl;
		mymodel->deleteenemy(e);
		mymodel->playerbullet->square.y = 480;
		score+=10;
	}
	
	//check if playerbullet hits enemy if so end game
	if(mymodel->playercollision()){
		end = true;
	}		

	//calculating position of enemys
	static int laststep = 0;
	int steps = time.get()/steptime;
	
	if(laststep != steps){
		laststep = steps;
		if(steps%12 == 0){
			enemyy+=20;
			//lvl is over
			if(steps/12 == 8){
				end = true;
				
			}
		}else{
		
			if((steps%24)/12 == 0){
				enemyx +=10;
			}else{
				enemyx-=10;
			}
		}
	}
	
	//updating the position of all enemies and seeing or their is an enemie alive
	enemiesdead = true;
	for(int i = 0;i<5;i++){
		for(int j = 0;j<10;j++){
			if(mymodel->enemies[j][i] != nullptr){
				enemiesdead = false;
				mymodel->enemies[j][i]->square.x = enemyx+j*55;
				mymodel->enemies[j][i]->square.y = enemyy+i*40;
			}
		}
	}
	

}

void si::World::loadlvl(std::string filepath){
	//loads in the lvl
	lvlnr+=1;
	enemyx = 0;
	enemyy = 40;
	time.start();
	std::cout << "starting a new lvl" << std::endl;
	si::file::File inputfile;
	try{
		inputfile.load(filepath);
	}catch(si::file::incorectfile){
		std::cout << "could not open file" << filepath << std::endl;
	}
	//very lvl is a bit faster
	steptime = inputfile.getint("steptime");
	for(int i = 0;i < lvlnr;i++){
		steptime *=0.8;
	}
	for(int i = 0;i<5;i++){
		std::string enemyfile;
		try{
		enemyfile = inputfile.getstring("enemy"+std::to_string(i));
		}catch(si::file::inputerror){
			std::cout << "could not get " <<"enemy"+std::to_string(i) << std::endl;
		}
		for(int j = 0 ; j<10;j++){
			
			si::Enemy* newenemy = new Enemy(enemyfile);
			mymodel->entities.push_back(newenemy);
			mymodel->enemies[j][i] = newenemy;
		}
	}
}

//calculates if theire is an enemy that shoots
void si::World::shoot(){
	if(random->chance(100)){
		int n = random->get()%10;
		si::Bullet* newbul = new si::Bullet("../resources/bullet.xml");
		newbul->square.y = enemyy;
		newbul->square.x = enemyx + n*55 + 25;
		mymodel->entities.push_back(newbul);
		mymodel->bullets.push_back(newbul);
	}
}
//checks if all the enemies have been killed
bool si::World::alldead(){
	return enemiesdead;
}
int si::World::getscore(){
	return score;
}
bool si::World::endgame(){
	return end;
}
