#include <iostream>
#include <cstring>
using namespace std;

class media {
	public:
		media(char*, int);
		~media();
		char* getTitle();
		int getYear();
		void setTitle(char*);
		void setYear(int);
	protected:
		char* title;
		int year;
};
