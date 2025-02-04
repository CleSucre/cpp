#include "Zombie.hpp"

int	main(void) {
	Zombie zombie1("Zombie 1");
	Zombie *zombie2;

	zombie2 = newZombie("Zombie 2");

	zombie1.announce();
	zombie2->announce();

	randomChump("Zombie 3");

	delete zombie2;

	return 0;
}