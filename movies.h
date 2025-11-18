//Header guards and imports
#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;
class movies:public media {

	//Define public constructor, destructor, and functinos
	public:
		movies(char*, char*, int, int, float);
		~movies();
		char* getDirector();
		void setDirector(char*);
		int getDuration();
		void setDuration(int);
		float getRating();
		void setRating(float);
		void print();
	//Define private accessible variables
	private:
		char* director;
		int duration;
		float rating;
};
//End of header guard
#endif
