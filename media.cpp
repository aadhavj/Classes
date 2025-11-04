#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

media::media(char* inputTitle, int inputYear){
	title = new char[80];
	strcpy(title, inputTitle);
	year = inputYear;
}
~media::media(){
	delete[] title;
}

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
