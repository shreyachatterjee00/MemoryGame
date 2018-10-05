#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <random>
using namespace std;


class MemoryMatchGame {
private: 
	string animals[50] = { "dog", "goose","horse", "deer", "donkey", "cow", "turtle", "rabbit", "whale", "rhino", "seal", "lion", "tiger", "wolf", "alpaca", "llama", "bear", "sloth", "chicken", "dolphin", "parrot", "lizard", "panther", "stingray", "snake", "kangaroo", "monkey", "hippo", "pig", "rat", "elephant", "otter", "giraffe", "goat", "platypus", "anteater", "zebra", "shark", "seahorse", "hawk", "eagle", "cheetah", "ape", "moose", "orca", "flamingo", "turkey", "fish", "crow", "ostrich"};
	int level;
	string newAnimals1[4][4];
	string newAnimals2[6][6];
	string newAnimals3[8][8];
	string faceCards1[4][4];
	string faceCards2[6][6];
	string faceCards3[8][8];
	int xCoord1;
	int yCoord1;
	int xCoord2;
	int yCoord2;
	int row;
	int column;
	int row1;
	int column1;
	int row2;
	int column2;
	int seconds;
  
public:
	void askUser();
	template<std::size_t N>
	void initArray(string arr[][N]);
	template<std::size_t N>
	string setRandomAnimal(string arr[][N]);
	template<std::size_t N>
	bool checkAnimalIsChosen(string randomAnimal, string arr[][N]);
	template<std::size_t N>
	void setCoord(string arr[][N]);
	template<std::size_t N>
	bool checkPlace(int x, int y, string arr[][N]);
	template<std::size_t N>
	void loop(string faceCard[][N], string newAnimals[][N]);
	template<std::size_t N>
	void innit(string faceCard[][N]);
	template<std::size_t N>
	void askForRowColumn(string faceCard[][N], string newAnimals[][N]);
	template<std::size_t N>
	bool checkIfMatch(string newAnimals[][N], int row1, int row2, int column1, int column2);
	template<std::size_t N>
	void printArray(string faceCard[][N]);
	template<std::size_t N>
	bool done(string faceCard[][N]);
	void askUserTime();
	void start();
};
