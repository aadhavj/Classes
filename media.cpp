#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;
//Media constructor
media::media(char* inputTitle, int inputYear){
	title = new char[80];
	strcpy(title, inputTitle);
	year = inputYear;
}
//Media destructor
media::~media(){
	delete[] title;
}

//Media functions specific
char* media::getTitle(){
	return title;
}

int media::getYear() {
	return year;
}
void media::setTitle(char* inputTitle){
	strcpy(title, inputTitle);
}
void media::setYear(int inputYear){
	year = inputYear;
}
void media::print(){
	cout << "Title: " << title << "\tYear: " << year << endl;
}
