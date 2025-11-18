#include <iostream>
#include <cstring>
#include "videogame.h"
using namespace std;

//Videogame constructor
videogame::videogame(char* inputTitle,int inputYear, char* inputPublisher, float inputRating):media(inputTitle, inputYear)
{
	publisher = new char[80];
	strcpy(publisher, inputPublisher);
	rating = inputRating;
}

//Videogame destructor
videogame::~videogame(){
	delete[] publisher;
}

//Neccessary functions
char* videogame::getPublisher(){
	return publisher;
}
void videogame::setPublisher(char* inputPublisher){
	strcpy(publisher, inputPublisher);
}
float videogame::getRating(){
	return rating;
}
void videogame::setRating(float inputRating){
	rating = inputRating;
}
void videogame::print(){
	cout << "Title: " << title << "\tYear: " << year << "\tPublisher: " << publisher << "\tRating: " << rating << endl;
}
