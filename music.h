//Header guard and neccessary imports
#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;
class music:public media {
	//Publicly accessible constructor, destructor, and functions
	public:
		music(char*, char*, int, int, char*);
		~music();
		char* getArtist();
		void setArtist(char*);
		int getDuration();
		void setDuration(int);
		char* getPublisher();
		void setPublisher(char*);
		void print();
	//Privately accessible variables
	private:
		char* artist;
		int duration;
		char* publisher;
};
//End of header guard
#endif
