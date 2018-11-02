#ifndef FILE_H
#define FILE_H

#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace si{
namespace file{

class inputerror{};
class incorectfile{};

using boost::property_tree::ptree;

class File{
	public:
		File(){};  //makes new objects
		File(std::string filename);//makes new object and loads in a file
		void load(std::string filename);//loads in a file
		int getint(std::string name);//gets a specific int from the file
		std::string getstring(std::string name);//gets a specific string from the file
		float getfloat(std::string name);//gets a specific float from the file
		//void save();
		//void putint(std::string name, int i);
		//void putstring(std::string name, std::string s);
	private:
		ptree pt;
		std::string f_name;

};


}
}

#endif
