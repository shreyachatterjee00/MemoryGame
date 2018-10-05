#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "MemoryMatchGame.h"
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <Windows.h>
#include <unistd.h>
using namespace std;

void MemoryMatchGame::start() {
	askUser();
}

void MemoryMatchGame::askUser() {
	cout << "Note: In this game, rows and columns start at 0, instead of 1." << endl;
	cout << "Welcome to Memory Match Game!" << endl;
	cout << "Press 1 for a 4 x 4 easy board." << endl;
	cout << "Press 2 for a 6 x 6 medium board." << endl;
	cout << "Press 3 for a 8 x 8 difficult board." << endl;
	cin >> level;
	if (level == 1) {
		row = 4;
		column = 4;
		askUserTime();
		initArray(newAnimals1);
		for (int a = 0; a < 8; a++) {
			setRandomAnimal(newAnimals1);
		}
		loop(faceCards1, newAnimals1);
	}
	if (level == 2) {
		row = 6;
		column = 6;
		askUserTime();
		initArray(newAnimals2);
		for (int a = 0; a < 18; a++) {
			setRandomAnimal(newAnimals2);
		}
		loop(faceCards2, newAnimals2);
	}
	if (level == 3) {
		row = 8;
		column = 8;
		askUserTime();
		initArray(newAnimals3);
		for (int a = 0; a < 32; a++) {
			setRandomAnimal(newAnimals3);
		}
		loop(faceCards3, newAnimals3);
	}
}

//asks for number of seconds user wants cards to flip up for
void MemoryMatchGame::askUserTime() {
	cout << "When you choose which cards to flip, they cards will stay face up for some number of seconds." << endl << "Press 2 for 2 seconds, 4 for 4 seconds, and 6 for 6 seconds." << endl;
	cin >> seconds;
	
}

// init array to empty by setting all elements to NULL
//int row = # of rows array has
//int column = # of columns array as
template<std::size_t N>
void MemoryMatchGame::initArray(string arr[][N]) {
	for (int i = 0; i < row; i++) {  //i = rows, j = columns
		for (int j = 0; j < column; j++) {
			arr[i][j] = "NULL"; //setting everything to null value 
		}
	}
}

//picks a random animal and returns the animal if it has not been chosen before
template<std::size_t N>
string MemoryMatchGame::setRandomAnimal(string arr[][N]) {
	bool answer = true;
	string randomAnimal;
	srand(time(NULL));
	while (answer == true) {
		randomAnimal = animals[rand() % 50];
		answer = checkAnimalIsChosen(randomAnimal, arr);
		if (answer == false) {
			setCoord(arr); //sets two sets of coordinates 
			arr[xCoord1][yCoord1] = randomAnimal;
			arr[xCoord2][yCoord2] = randomAnimal;		
		}
	}
	return randomAnimal;
}

//checks if animal has already been chosen 
//if chosen already, run getRandomAnimal again 
//return value true = the animal is already chosen
//return value false = animal has not been chosen
template<std::size_t N>
bool MemoryMatchGame::checkAnimalIsChosen(string randomAnimal, string arr[][N]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (randomAnimal.compare(arr[i][j])==0) {
				return true;
			}
		}
	}
	return false;
}

//set random x and y coord
template<std::size_t N>
void MemoryMatchGame::setCoord(string arr[][N]) {
	bool loop = true;
		while (loop == true) {
				xCoord1 = rand() % (row);
				yCoord1 = rand() % (column);
				loop = checkPlace(xCoord1, yCoord1, arr);
			}
		loop = true;
		while (loop == true) {
			xCoord2 = rand() % (row);
			yCoord2 = rand() % (column);
			loop = checkPlace(xCoord2, yCoord2, arr) || ((xCoord1 == xCoord2) && (yCoord1 == yCoord2)); //set loop to true if either checkPlace = true or coordinates are the same
		}

}

//check if x and y coord is already used 
//returns false if space is empty
//returns true if space is filled
template<std::size_t N>
bool MemoryMatchGame::checkPlace(int x, int y, string arr[][N]) {
	if (arr[x][y].compare("NULL") == 0) {

		return false; 
	}
	return true;
}

template<std::size_t N>
void MemoryMatchGame::loop(string faceCard[][N], string newAnimals[][N]) {
	innit(faceCard);
	while (done(faceCard) == false) {
		//call print Array
		//call askForRowColumn
		//call done function 
		printArray(faceCard);
		askForRowColumn(faceCard, newAnimals);
	}
}

template<std::size_t N>
void MemoryMatchGame::innit(string faceCard[][N]) {
	//sets faceCard array to "ANIMAL" for all elements 
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			faceCard[i][j] = "//ANIMAL//";
		}
	}
}

template<std::size_t N>
void MemoryMatchGame::askForRowColumn(string faceCard[][N], string newAnimals[][N]) {
	//ask for row1 and column1 
	//ask for row2 and column2 
	//call checkIfMatch function
	//if checkIfMatch == true, call updateArray
	//if checkIfMatch == false, keep cards up for 2, 4, or 6 seconds, then flip back down 
	cout << "Row 1: ";
	cin >> row1;
	if (row1 > 3 || row1 < 0) {
		cout << "Please enter an integer between 0 and 3. Row 1: ";
		cin >> row1;
	}
	cout << endl << "Column 1: ";
	cin >> column1;
	if (column1 > 3 || column1 < 0) {
		cout << "Please enter an integer between 0 and 3. Column 1: ";
		cin >> column1;
	}
	cout << endl << "Row 2: ";
	cin >> row2;
	if (row2 > 3 || row2 < 0) {
		cout << "Please enter an integer between 0 and 3. Row 2: ";
		cin >> row2;
	}
	cout << endl << "Column 2: ";
	cin >> column2;
	if (column2 > 3 || column2 < 0) {
		cout << "Please enter an integer between 0 and 3. Column 2: ";
		cin >> column1;
	}
	//get animals in animal row1, column1, and row2, column2 
	faceCard[row1][column1] = newAnimals[row1][column1];
	faceCard[row2][column2] = newAnimals[row2][column2];
	printArray(faceCard);
	Sleep((seconds)*1000);
	if (checkIfMatch (newAnimals, row1, row2, column1, column2) == false) {
		faceCard[row1][column1] = "//ANIMAL//";
		faceCard[row2][column2] = "//ANIMAL//";
		printArray(faceCard);
	}
}

template<std::size_t N>
bool MemoryMatchGame::checkIfMatch(string newAnimals[][N], int row1, int row2, int column1, int column2) {
	//check if animal in row1, column1 = animal in row2, column2
	//returns true if animals are equal, returns false otherwise
	if ((newAnimals[row1][column1]).compare(newAnimals[row2][column2]) == 0) {
		return true; 
	}
	else {
		return false;
	}
}

template<std::size_t N>
void MemoryMatchGame::printArray(string faceCard[][N]) {
	//clear screen 
	system("CLS");
	cout << flush;
	//print faceCard array
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << faceCard[i][j] << "   ";
		}
		cout << endl;
	}
	cout << clock() / CLOCKS_PER_SEC << " seconds have passed during the game." << endl;
}

template<std::size_t N>
bool MemoryMatchGame::done(string faceCard[][N]) {
	//true if all cards are face up
	//false if some cards are still face down 
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (faceCard[i][j].compare("//ANIMAL//") == 0) {
				return false;
			}
			else {
				cout << "Congrats! You have won." << endl;
				return true;
			}
		}
	}
}
