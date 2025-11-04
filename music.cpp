#include <iostream>
#include <cstring>
#include "music.h"
using namespace std;

music::music(char* inputTitle, char* inputArtist, int inputYear, int duration, char* publisher):media(inputTitle, inputYear)
{
	artist = new char[80];
	strcpy(artist, inputArtist);
	duration = inputDuration;
	publisher = new char[80];
	strcpy(publisher, inputPublisher);
}
~music::music(){
	delete[] artist;
	delete[] publisher;
}
char* music::getArtist() {
	return artist;
}
void music::setArtist(char* inputArtist){
	strcpy(artist, inputArtist);
}
int music::getDuration(){
	return duration;
}
void music::setDuration(int inputDuration){
	duration = inputDuration;
}
char* music::getPublisher() {
	return publisher;
}
void music::setPublisher(char* inputPublisher){
	strcpy(publisher, inputPublisher);
}
