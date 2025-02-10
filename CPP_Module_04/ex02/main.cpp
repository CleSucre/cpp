#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void testAbstractAnimal() {
	std::cout << BOLD << BLUE << "==== TEST 0: Checking if Animal is Abstract ====" << RESET << std::endl;

	Animal* animal = NULL;
	Dog dog;
	Cat cat;

	animal = &dog;
	std::cout << GREEN << "Animal pointer assigned to Dog instance. Type: " << animal->getType() << RESET << std::endl;
	animal->makeSound();

	animal = &cat;
	std::cout << GREEN << "Animal pointer assigned to Cat instance. Type: " << animal->getType() << RESET << std::endl;
	animal->makeSound();

	std::cout << BOLD << BLUE << "==== TEST 0.1: Checking if WrongAnimal behaves differently ====" << RESET << std::endl;

	WrongAnimal* wrongAnimal = NULL;
	WrongAnimal wrongBase;
	WrongCat wrongCat;

	wrongAnimal = &wrongBase;
	std::cout << GREEN << "WrongAnimal pointer assigned to WrongAnimal instance. Type: " << wrongAnimal->getType() << RESET << std::endl;
	wrongAnimal->makeSound();

	wrongAnimal = &wrongCat;
	std::cout << GREEN << "WrongAnimal pointer assigned to WrongCat instance. Type: " << wrongAnimal->getType() << RESET << std::endl;
	wrongAnimal->makeSound();
}

int main() {
	testAbstractAnimal();

	std::cout << BOLD << BLUE << "==== TEST 1: Creating Animals ====" << RESET << std::endl;
	const int arraySize = 6;
	Animal* animals[arraySize];

	for (int i = 0; i < arraySize; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << BOLD << BLUE << "==== TEST 2: Checking Animal Types ====" << RESET << std::endl;
	for (int i = 0; i < arraySize; i++)
		std::cout << "Animal[" << i << "] is a " << animals[i]->getType() << std::endl;

	std::cout << BOLD << BLUE << "==== TEST 3: Testing makeSound() ====" << RESET << std::endl;
	for (int i = 0; i < arraySize; i++)
		animals[i]->makeSound();

	std::cout << BOLD << BLUE << "==== TEST 4: Creating WrongAnimals ====" << RESET << std::endl;
	const WrongAnimal* wrongAnimal1 = new WrongAnimal();
	const WrongAnimal* wrongCat1 = new WrongCat();

	std::cout << BOLD << BLUE << "==== TEST 5: Checking WrongAnimal Types ====" << RESET << std::endl;
	std::cout << "WrongAnimal type: " << wrongAnimal1->getType() << std::endl;
	std::cout << "WrongCat type: " << wrongCat1->getType() << std::endl;

	std::cout << BOLD << BLUE << "==== TEST 6: Testing makeSound() with Wrong Classes ====" << RESET << std::endl;
	wrongAnimal1->makeSound();
	wrongCat1->makeSound();

	std::cout << BOLD << BLUE << "==== TEST 7: Testing References with Wrong Classes ====" << RESET << std::endl;
	const WrongAnimal& refWrongCat = *wrongCat1;
	refWrongCat.makeSound();

	std::cout << BOLD << BLUE << "==== TEST 8: Deleting Animals ====" << RESET << std::endl;
	for (int i = 0; i < arraySize; i++)
		delete animals[i];

	std::cout << BOLD << BLUE << "==== TEST 9: Deleting WrongAnimals ====" << RESET << std::endl;
	delete wrongAnimal1;
	delete wrongCat1;

	return 0;
}
