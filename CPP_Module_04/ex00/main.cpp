#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << BOLD << BLUE << "==== TEST 1: Creating Animals ====" << RESET << std::endl;
    const Animal* animal = new Dog();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << BOLD << BLUE << "==== TEST 2: Checking Animal Types ====" << RESET << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << BOLD << BLUE << "==== TEST 3: Testing makeSound() ====" << RESET << std::endl;
    dog->makeSound();
    cat->makeSound();

    std::cout << BOLD << BLUE << "==== TEST 4: Testing References ====" << RESET << std::endl;
    const Animal& refDog = *dog;
    const Animal& refCat = *cat;
    refDog.makeSound();
    refCat.makeSound();

    std::cout << BOLD << BLUE << "==== TEST 5: Deleting Animals ====" << RESET << std::endl;
    delete animal;
    delete dog;
    delete cat;

    std::cout << BOLD << BLUE << "==== TEST 6: Creating Wrong Animals ====" << RESET << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << BOLD << BLUE << "==== TEST 7: Checking WrongAnimal Types ====" << RESET << std::endl;
    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

    std::cout << BOLD << BLUE << "==== TEST 8: Testing makeSound() with Wrong Classes ====" << RESET << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound();

    std::cout << BOLD << BLUE << "==== TEST 9: Testing References with Wrong Classes ====" << RESET << std::endl;
    const WrongAnimal& refWrongCat = *wrongCat;
    refWrongCat.makeSound();

    std::cout << BOLD << BLUE << "==== TEST 10: Deleting Wrong Animals ====" << RESET << std::endl;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
