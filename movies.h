#include <iostream>
#include <cstring>
#include <media.h>
using namespace std;
class movies {

	public:
		movies(char*, char*, int, int, float);
		~movies();
		char* getDirector();
		void setDirector(char*);
		int getDuration();
		void setDuration(int);
		float getRating();
		void setRating(float);
	private:
		char* director;
		int duration;
		float rating;
}
