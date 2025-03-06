#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define MATERIA_CAPACITY 4

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _materias[MATERIA_CAPACITY];

		void initMaterials();

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		virtual ~MateriaSource();

		MateriaSource &operator=(const MateriaSource &other);

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_HPP
