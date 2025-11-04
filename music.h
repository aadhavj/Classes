#include <iostream>
#include <cstring>
#include <media.h>
using namespace std;
class music {

	public:
		music(char*, char*, int, int, char*);
		~music();
		char* getArtist();
		void setArtist(char*);
		int getDuration();
		void setDuration(int);
		char* getPublisher();
		void setPublisher(char*);
	
	private:
		char* artist;
		int duration;
		char* publisher;
};
