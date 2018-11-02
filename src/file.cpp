#include "file.h"

si::file::File::File(std::string filename){
	f_name = filename;
	try{
		read_xml(f_name, pt);
	}catch(...){
		throw incorectfile();
	}
}
void si::file::File::load(std::string filename){
	f_name = filename;
	try{
		read_xml(f_name, pt);
	}catch(...){
		throw incorectfile();
	}
}
/*
void si::file::File::save(){
	write_xml(f_name,pt);
}
*/
int si::file::File::getint(std::string name){
	try{
		return pt.get<int>(name);
	}catch(...){
		throw inputerror();
	}
}
std::string si::file::File::getstring(std::string name){
	try{
		return pt.get<std::string>(name);
	}catch(...){
		throw inputerror();
	}
	
}
float si::file::File::getfloat(std::string name){
	try{
		return pt.get<float>(name);
	}catch(...){
		throw inputerror();
	}
	
}
/*
void si::file::File::putint(std::string name, int i){
	pt.put(name,i);
}
void si::file::File::putstring(std::string name, std::string s){
	pt.put(name,s);
}
*/
