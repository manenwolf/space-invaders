#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>     
#include <time.h>   

namespace si{
namespace random{


class Random{
public:
	static Random* getinstance();
	~Random();
	int get();
	bool chance(int n);
private:
	Random();
};


}
}



#endif
