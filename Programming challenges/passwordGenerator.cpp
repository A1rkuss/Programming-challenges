#include <iostream>
#include "Random.h"
#include "passwordGenerator.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution randNum{ 10, 16 }; // Size of the password for the cases when we use generatePasswordLoop()
int randomNum = randNum(gen);


int generatePassword(int choice);
int generatePasswordLoop(int num);
int randomChar(int firstNum, int secondNum);
int GeneratePasswordLoopWithoutX(int choice); 


int passwordGenerator() {

	std::cout << "Welcome to the Password Generator! Choose the option: " << '\n';
	std::cout << "1. Random password." << '\n';
	std::cout << "2. Random password with fixed count of characters." << '\n';
	std::cout << "3. Disable numbers/characters/symbols from password." << '\n';
	std::cout << "4. Close the program." << '\n', '\n';

	int choice{};
	std::cin >> choice;
	generatePassword(choice);
	

	return 0;
}

int generatePassword(int choice) {
	switch (choice) {
	case 1: // Random password
	{	
		int num = randNum(gen);

		for (int i = 0; i < num; i++) {
			randomChar(1, 4);
		}
		break;
	}

	case 2:
	{
		std::cout << "Input how many characters you need in your password: ";
		int characters{};
		std::cin >> characters;
		generatePasswordLoop(characters);
		break;
	}
	case 3:
	{
		std::cout << "Choose what you want to disable from password: " << '\n';
		std::cout << "1. Disable numbers." << '\n';
		std::cout << "2. Disable letters." << '\n';
		std::cout << "3. Disable symbols." << '\n\n';
		int input;
		std::cin >> input;

		GeneratePasswordLoopWithoutX(input);
	}
	
	}


	return 0;
}



int randomChar(int firstNum, int secondNum) {

	


	std::uniform_int_distribution randNumber{ firstNum, secondNum };
	int choice = randNumber(gen);
	switch (choice) {
	case 1:
		std::cout << static_cast<char>(Random::get(65, 90));  // Random smol letter
		break;
	case 2:
		std::cout << static_cast<char>(Random::get(97, 122)); // Random big letter
		break;
	case 3:
		std::cout << static_cast<char>(Random::get(35, 37));  // Random symbol
		break;
	case 4:
		std::cout << Random::get(0, 9); // Random number
		break;
	}
	
	return 0;
}


int generatePasswordLoop(int num) {


	for (int i = 0; i < num; i++) {
		randomChar(1, 4);
	}

	return 0;
}

int GeneratePasswordLoopWithoutX(int choice) {
	switch (choice) {
	case 1: // Without numbers
	{
		int num = randNum(gen);

		for (int i = 0; i < num; i++) {
			randomChar(1, 3);
		}
		break;
	}

	case 2: // Without letters
	{
		int num = randNum(gen);

		for (int i = 0; i < num; i++) {
			randomChar(3, 4);
		}
		break;
	}

	case 3: // Without symbols
	{
		int num = randNum(gen);

		for (int i = 0; i < num / 2; i++) {
			randomChar(1, 2);
			randomChar(4, 4);
		}
		break;
	}

	}
	return 0;
}