#include <iostream>
#include <cstring>
#include <vector>
#include "movies.h"
#include "music.h"
#include "videogame.h"
#include "media.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"
using namespace std;
int main(){
	//Basic parent vector
	vector<media*> mediaVector;

	//Bool loop
	bool quitLoop = false;

	//Command prompt info
        char add[] = "ADD";
	char search[] = "SEARCH";
	char del[] = "DELETE";
	char quit[] = "QUIT";
	char command[1000];

	//Command Add variables
	char mediaType[1000];
	char mediaTitle[1000];
	int mediaYear;
	char mediaDirector[1000];
	char mediaArtist[1000];
	char mediaPublisher[1000];
	int mediaDuration;
	float mediaRating;

	//Command Search variable(s)
	char searchBy[1000];

	//Command Delete variable(s)
	char deleteConfirm;
	int deleteIndex = 0;
	
		
	//Command loop
	while (!quitLoop){

		//Show optional commands and take in command from user
		cout << "\nPlausible Commands (CASE-SENSITIVE): ADD, SEARCH, DELETE, QUIT" << endl;
		cout << "\nEnter command here: ";
		cin >> command;
		command[6] ='\0';

		//Checks for which command, if any valid, is entered
		if (strcmp(command, add) == 0){
			
			//Decide media type
			cout << "Which type of media do you want to add? (Movie, Music, Videogame): ";
			cin >> mediaType;
			cin.ignore();

			if (strcmp(mediaType,"Movie" ) == 0 || strcmp(mediaType, "Music") == 0 || strcmp(mediaType, "Videogame") == 0){
				
				//Obtain common info across media types
				cout << "\nPlease Enter Title: ";
				cin.get(mediaTitle, 999);
				cin.get();
				cout << "\nPlease Enter Year: ";
				cin >> mediaYear;
				cin.ignore();

				//Get specific info across specific media types and add to media vector
				if (strcmp(mediaType, "Movie") == 0){
					cout << "\nWho is the director of the movie?: ";
					cin.get(mediaDirector, 999);
					cin.get();
					cout << "\nHow many minutes long is the movie? (Integer): ";
					cin >> mediaDuration;
					cin.ignore();
					cout << "\nWhat is the rating of the movie?: ";
					cin >> mediaRating;
					cin.ignore();
					movies* m = new movies(mediaTitle, mediaDirector, mediaYear, mediaDuration, mediaRating);
					
					mediaVector.push_back(m);
				}
				else if (strcmp(mediaType, "Music") == 0){
					cout << "\nWho is the artist?: ";
					cin.get(mediaArtist, 999);
					cin.get();
					cout << "\nHow many minutes long is the music? (Integer): ";
					cin >> mediaDuration;
					cin.ignore();
					cout << "\nWho is the publisher?: ";
					cin.get(mediaPublisher,999);
					cin.get();
					music* u = new music(mediaTitle, mediaArtist, mediaYear, mediaDuration, mediaPublisher);
					mediaVector.push_back(u);
				}
				else if (strcmp(mediaType, "Videogame") == 0){
					cout << "\nWho is the publisher?: ";
					cin.get(mediaPublisher,999);
					cin.get();
					cout << "\nWhat is the rating of the videogame?: ";
					cin >> mediaRating;
					cin.ignore();
					videogame* v = new videogame(mediaTitle, mediaYear, mediaPublisher, mediaRating);
					mediaVector.push_back(v);
				}
			}
			else{
				//User enters invalid media type option
				cout << "\nInvalid media type. Please try again." << endl;
			}
		}
		else if (strcmp(command, search) == 0){

			//Get which they wanna search by, title or year
			cout << "\nWhat would you like to search by? Title or Year: ";
			cin >> searchBy;
			cin.ignore();
			searchBy[5] = '\0';

			//Print all matching titles
			if (strcmp(searchBy, "Title") == 0){
				cout << "\nWhat is the title: ";
				cin.get(mediaTitle, 999);
				cin.get();
				for (media* obj : mediaVector){
					if (strcmp(obj->getTitle(), mediaTitle) == 0){
						obj->print();
					}
						
				}
			}
			//Print all matching years
			else if (strcmp(searchBy, "Year") == 0){
				cout << "\nWhat is the year: ";
				cin >> mediaYear;
				cin.ignore();
				for (media* obj : mediaVector){
					if (mediaYear == obj->getYear()){
						obj->print();	
					}
				}
			}
			else{
				cout << "Unrecognizable command, returning you to command prompt";
			}
		}
		//Deletes objects from mediaVector
		else if (strcmp(command, del) == 0){

			//Provide warning and ask which they wanna search the object they wanna delete by
			cout << "WARNING: You are deleting media object!";
			cout << "\nWhat would you like to DELETE by? Title or Year: ";
                        cin >> searchBy;
                        cin.ignore();
                        searchBy[5] = '\0';

			//List all titles that match and ask which they wanna delete
                        if (strcmp(searchBy, "Title") == 0){
                                cout << "\nWhat is the title: ";
                                cin.get(mediaTitle, 999);
                                cin.get();
				cout << "Objects below: " << endl;
				for (int i = 0; i < mediaVector.size();i++){
					if (strcmp(mediaVector[i]->getTitle(), mediaTitle) == 0){
						cout << i << ". ";
						mediaVector[i]->print();
					}
				}
				cout << "Please enter the index of the object you would like to delete: ";
				cin >> deleteIndex;
				cin.ignore();
				cout << "Chosen deletion: " << endl;
				mediaVector[deleteIndex]->print();
				cout << RED << "\nAre you sure you want to delete this objects? (Y/N): " << RESET;
				cin >> deleteConfirm;
				cin.ignore();
				if (deleteConfirm == 'Y'){
					delete mediaVector[deleteIndex];
					mediaVector.erase(mediaVector.begin()+deleteIndex);
					cout << "\n.....Objects terminated....." << endl;
				}
				else if (deleteConfirm == 'N'){
					cout << RED << "\nDeletion process terminated. Returning you to command line." << RESET;
				}
				else{
					cout << "\nUnrecognized response, returning you to command prompt";
				}
                        }
			//List all years that match and ask which they wanna delete
                        else if (strcmp(searchBy, "Year") == 0){
                                cout << "\nWhat is the year: ";
                                cin >> mediaYear;
                                cin.ignore();
				cout << "\nObjects below: " << endl;
				for (int i = 0;i < mediaVector.size();i++){
					if (mediaVector[i]->getYear() == mediaYear){
						cout << i << ". ";
						mediaVector[i]->print();
					}
				}
				cout << "Please enter the index of the object you would like to delete: ";
				cin >> deleteIndex;
				cin.ignore();
				cout << "Chosen deletion: " << endl;
				mediaVector[deleteIndex]->print();
				cout << "\nAre you sure you want to delete this objects (Y/N): ";
				cin >> deleteConfirm;
				cin.ignore();
				if (deleteConfirm == 'Y'){
					delete mediaVector[deleteIndex];
					mediaVector.erase(mediaVector.begin() + deleteIndex);
					cout << "\n.....Objects terminated.....";
				}
				else if (deleteConfirm == 'N'){
					cout << "\nDeletion process terminated. Returning you to command line.";
				}
				else{
					cout << "\nUnrecognized response, returning you to command prompt";
				}
                        }
                        else{
                                cout << "Unrecognizable command, returning you to command prompt";
                        }

		}
		//Exit program
		else if (strcmp(command, quit) == 0){
			cout << "\nQuitting now. Exiting Command Prompt.";
			quitLoop = true;
		}
		else{
			cout << "\nUnrecognized prompt";
		}
		
	}
	
	return 0;
}
