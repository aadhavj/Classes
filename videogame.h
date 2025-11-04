#include <iostream>
#include <cstring>
#include <media.h>
using namespace std;
class videogame {

	public:
		videogame(char*, int, char*, float);
		~videogame();
		char* getPublisher();
		void setPublisher(char*);
		float getRating();
		void setRating(float);
	private:
		char* publisher;
		float rating;

};
