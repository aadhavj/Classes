//Header Guards & Neccessary imports
#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>
using namespace std;

class media {
	//Public callable functions and contructors/destructors
	public:
		media(char*, int);
		~media();
		char* getTitle();
		int getYear();
		void setTitle(char*);
		void setYear(int);
		virtual void print();
	//Protected variables
	protected:
		char* title;
		int year;
};
//End of header guard
#endif
