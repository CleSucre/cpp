#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "colors.h"
#include <iostream>

int main() {
    std::cout << BOLD << CYAN << "\n=========================================" << RESET << std::endl;
    std::cout << BOLD << CYAN << "=== STARTING FULL MATERIA SYSTEM TEST ===" << RESET << std::endl;
    std::cout << BOLD << CYAN << "=========================================\n" << RESET << std::endl;

    std::cout << BOLD << YELLOW << "\n----- [1] CREATING MATERIA SOURCE -----\n" << RESET;
    IMateriaSource* src = new MateriaSource();

    std::cout << BOLD << YELLOW << "\n----- [2] LEARNING MATERIAS -----\n" << RESET;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << BOLD << YELLOW << "\n----- [3] CREATING CHARACTERS -----\n" << RESET;
    ICharacter* hero = new Character("Hero");
    ICharacter* enemy = new Character("Enemy");

    std::cout << BOLD << YELLOW << "\n----- [4] CREATING AND EQUIPPING MATERIAS -----\n" << RESET;
    AMateria* ice = src->createMateria("ice");
    hero->equip(ice);

    AMateria* cure = src->createMateria("cure");
    hero->equip(cure);

    src->createMateria("fire");

    std::cout << BOLD << YELLOW << "\n----- [5] USING MATERIAS -----\n" << RESET;
    hero->use(0, *enemy);
    hero->use(1, *enemy);
    hero->use(2, *enemy);

    std::cout << BOLD << YELLOW << "\n----- [6] UNEQUIPPING A MATERIA -----\n" << RESET;
    hero->unequip(0);
    hero->use(0, *enemy);

    std::cout << BOLD << YELLOW << "\n----- [7] COPYING CHARACTERS -----\n" << RESET;
    ICharacter* heroCopy = new Character(*(Character*)hero);
    heroCopy->use(1, *enemy);

    std::cout << BOLD << YELLOW << "\n----- [8] TESTING ASSIGNMENT OPERATOR -----\n" << RESET;
    *heroCopy = *(Character*)hero;
    heroCopy->use(1, *enemy);

    std::cout << BOLD << RED << "\n----- [9] CLEANING UP MEMORY -----\n" << RESET;
    delete hero;
    delete heroCopy;
    delete enemy;
    delete src;
    delete ice;

    std::cout << BOLD << GREEN << "\n========================================" << RESET << std::endl;
    std::cout << BOLD << GREEN << "=== ALL OBJECTS SUCCESSFULLY DELETED ===" << RESET << std::endl;
    std::cout << BOLD << GREEN << "========================================\n" << RESET << std::endl;

    return 0;
}
