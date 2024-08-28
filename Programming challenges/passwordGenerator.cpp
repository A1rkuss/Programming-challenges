#include <iostream>
#include "Random.h"
#include "passwordGenerator.h"

int randomChar() {

	std::random_device rd;       
	std::mt19937 gen(rd());


	std::uniform_int_distribution randNum{ 1, 4 };
	int choice = randNum(gen);
	switch (choice) {
	case 1:
		std::cout << static_cast<char>(Random::get(65, 90)); // Random smol letter
		break;
	case 2:
		std::cout << Random::get(0, 9);
		break;
	case 3:
		std::cout << static_cast<char>(Random::get(35, 37)); //Random symbol
		break;
	case 4:
		std::cout << static_cast<char>(Random::get(97, 122)); // Random big letter
		break;
	}

	return 0;
}

int password(int num) {
	for (int i = 0; i < num; i++) {
		randomChar();
	}
	
	return 0;
}


int passwordGenerator() {
	std::cout << "Input how many characters you need in your password: ";
	int characters{};
	std::cin >> characters;
	password(characters);
	
	return 0;
}