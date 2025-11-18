//Header guards and imports
#ifndef VIDEOGAME_H
#define VIDOEGAME_H
#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;
class videogame:public media {
	//Publicly accessible constructor, destructor, and functions
	public:
		videogame(char*, int, char*, float);
		~videogame();
		char* getPublisher();
		void setPublisher(char*);
		float getRating();
		void setRating(float);
		void print();
	//Privately accesible variables
	private:
		char* publisher;
		float rating;

};
//End of ehader guards
#endif
