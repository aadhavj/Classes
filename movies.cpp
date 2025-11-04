#include <iostream>
#include <cstring>
#include "movies.h"
using namespace std;

movies::movies(char* inputTitle, char* inputDirector, int inputYear, int inputDuration, float inputRating):media(inputTitle,inputYear){
	director = new char[80];
	strcpy(direction, inputDirector);
	duration = inputDuration;
	rating = inputRating;
}

~movies::movies(){
	delete[] director;
}

char* movies::getDirector() {
	return director;
}
void movies::setDirector(char* inputDirector){
	strcpy(director, inputDirector);
}
int movies::getDuration(){
	return duration;
}
void movies::setDuration(int inputDuration){
	duration = inputDuration;
}
float movies::getRating() {
	return rating;
}
void movies::setRating(float inputRating){
	rating = inputRating;
}
