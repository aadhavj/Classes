#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
using namespace std;
int main(){
	vector<media> parentVector;
	bool quitLoop = false;
        char add[] = "ADD";
	char search[] = "SEARCH";
	char del[] = "DELETE";
	char quit[] = "QUIT";
	char command[100];
	while (!quitLoop){
		cout << "Enter command here: ";
		cin >> command;
		command[6] ='\0';

		if (strcmp(command, add) == 0){
			cout << "Add stuff here";
		}
		else if (strcmp(command, search) == 0){
			cout << "Search stuff here";
		}
		else if (strcmp(command, del) == 0){
			cout << "Delete stuff here";
		}
		else if (strcmp(command, quit) == 0){
			cout << "Quit here";
		}
		else{
			cout << "Unrecognized prompt";
		}
		
	}
	
	return 0;
}
//Destructors complete them
//Use virtual functions
