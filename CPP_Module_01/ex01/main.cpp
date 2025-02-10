#include "Zombie.hpp"
#include <cstdlib>

int	main(int argc, char **argv) {
	int		N;
	Zombie*	horde;

	(void)argc;
	if (argc == 2) {
		N = atoi(argv[1]);
    } else {
		N = 5;
	}
	horde = zombieHorde(N, "Zombie");

    if (horde == NULL) {
		return 1;
	}

	for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

	delete [] horde;

	return 0;
}