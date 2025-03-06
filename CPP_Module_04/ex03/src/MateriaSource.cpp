#include "MateriaSource.hpp"
#include "colors.h"
#include <iostream>

void MateriaSource::initMaterials() {
    for (int i = 0; i < MATERIA_CAPACITY; i++) {
        this->_materias[i] = NULL;
    }
}

MateriaSource::MateriaSource() {
    this->initMaterials();
    std::cout << GREEN << "Materia source created" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    this->initMaterials();
    for (int i = 0; i < MATERIA_CAPACITY; i++) {
        if (other._materias[i] != NULL)
            this->_materias[i] = other._materias[i]->clone();
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < MATERIA_CAPACITY; i++) {
        if (this->_materias[i] != NULL) {
            delete this->_materias[i];
            this->_materias[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this == &other)
        return *this;

    for (int i = 0; i < MATERIA_CAPACITY; i++) {
        if (this->_materias[i] != NULL) {
            delete this->_materias[i];
            this->_materias[i] = NULL;
        }
    }

    for (int i = 0; i < MATERIA_CAPACITY; i++) {
        if (other._materias[i] != NULL)
            this->_materias[i] = other._materias[i]->clone();
    }

    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL) {
        std::cout << RED << "Cannot learn a NULL Materia" << RESET << std::endl;
        return;
    }

    for (int i = 0; i < MATERIA_CAPACITY; i++) {
        if (this->_materias[i] == NULL) {
            std::cout << GREEN << "Materia learned: " << MAGENTA << m->getType() << RESET << std::endl;
            this->_materias[i] = m;
            return;
        }
    }
    std::cout << RED << "Materia source is full, cannot learn more" << RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < MATERIA_CAPACITY; i++) {
        if (this->_materias[i] != NULL && this->_materias[i]->getType() == type) {
            std::cout << CYAN << "Creating Materia: " << MAGENTA << type << RESET << std::endl;
            return this->_materias[i]->clone();
        }
    }
    std::cout << RED << "Materia type not found: " << MAGENTA << type << RESET << std::endl;
    return NULL;
}
