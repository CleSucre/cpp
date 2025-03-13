#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << BOLD << BLUE << "==== TEST 1: Creating Animals ====" << RESET << std::endl;
    const int arraySize = 100;
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

    std::cout << BOLD << BLUE << "==== TEST 4: Testing Deep Copy on Dogs ====" << RESET << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Chase the cat!");
    originalDog.getBrain()->setIdea(1, "Dig a hole!");
    originalDog.getBrain()->setIdea(2, "Bark at strangers!");

    std::cout << GREEN << "Original Dog's ideas:" << RESET << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << YELLOW << "Idea " << i << ": " << originalDog.getBrain()->getIdea(i) << RESET << std::endl;

    Dog copiedDog = originalDog;
    std::cout << CYAN << "Copied Dog's ideas before modification:" << RESET << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << YELLOW << "Idea " << i << ": " << copiedDog.getBrain()->getIdea(i) << RESET << std::endl;

    copiedDog.getBrain()->setIdea(0, "Eat the bone!");
    copiedDog.getBrain()->setIdea(1, "Run in the park!");

    std::cout << GREEN << "Original Dog's ideas after modification on copiedDog:" << RESET << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << YELLOW << "Idea " << i << ": " << originalDog.getBrain()->getIdea(i) << RESET << std::endl;

    std::cout << CYAN << "Copied Dog's ideas after modification:" << RESET << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << YELLOW << "Idea " << i << ": " << copiedDog.getBrain()->getIdea(i) << RESET << std::endl;

    std::cout << BOLD << BLUE << "==== TEST 5: Testing Deep Copy on Cats ====" << RESET << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Climb the tree!");
    originalCat.getBrain()->setIdea(1, "Sleep on the sofa!");
    originalCat.getBrain()->setIdea(2, "Catch the mouse!");

    std::cout << GREEN << "Original Cat's ideas:" << RESET << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << YELLOW << "Idea " << i << ": " << originalCat.getBrain()->getIdea(i) << RESET << std::endl;

    Cat copiedCat = originalCat;
    std::cout << CYAN << "Copied Cat's ideas before modification:" << RESET << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << YELLOW << "Idea " << i << ": " << copiedCat.getBrain()->getIdea(i) << RESET << std::endl;

    copiedCat.getBrain()->setIdea(0, "Knock things off the table!");
    copiedCat.getBrain()->setIdea(1, "Hide in a box!");

    std::cout << GREEN << "Original Cat's ideas after modification on copiedCat:" << RESET << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << YELLOW << "Idea " << i << ": " << originalCat.getBrain()->getIdea(i) << RESET << std::endl;

    std::cout << CYAN << "Copied Cat's ideas after modification:" << RESET << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << YELLOW << "Idea " << i << ": " << copiedCat.getBrain()->getIdea(i) << RESET << std::endl;

    std::cout << BOLD << BLUE << "==== TEST 6: Deleting Animals ====" << RESET << std::endl;
    for (int i = 0; i < arraySize; i++)
        delete animals[i];

    std::cout << BOLD << BLUE << "==== TEST 7: Creating WrongAnimals ====" << RESET << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << BOLD << BLUE << "==== TEST 8: Checking WrongAnimal Types ====" << RESET << std::endl;
    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

    std::cout << BOLD << BLUE << "==== TEST 9: Testing makeSound() with Wrong Classes ====" << RESET << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound();

    std::cout << BOLD << BLUE << "==== TEST 10: Testing References with Wrong Classes ====" << RESET << std::endl;
    const WrongAnimal& refWrongCat = *wrongCat;
    refWrongCat.makeSound();

    std::cout << BOLD << BLUE << "==== TEST 11: Deleting WrongAnimals ====" << RESET << std::endl;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
