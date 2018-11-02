#include "random.h"

si::random::Random::Random(){
	srand (time(NULL));
}

si::random::Random* si::random::Random::getinstance(){
	
	static Random* instance = nullptr;

	if(instance == nullptr){
		instance = new Random();
	}
	return instance;
}


bool si::random::Random::chance(int n){
	if(rand()%n == 0){
		return true;
	}else{
		return false;
	}
}

int si::random::Random::get(){
	return rand();
}


