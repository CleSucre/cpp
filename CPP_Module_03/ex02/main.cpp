#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << BOLD << BLUE << "==== TEST 1: Creating ClapTrap ====" << RESET << std::endl;
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trapster");

    std::cout << BOLD << BLUE << "==== TEST 2: Creating ScavTrap ====" << RESET << std::endl;
    ScavTrap scav1("Guardian");
    ScavTrap scav2("Protector");

    std::cout << BOLD << BLUE << "==== TEST 3: Creating FragTrap ====" << RESET << std::endl;
    FragTrap frag1("Destroyer");
    FragTrap frag2("Demolisher");

    std::cout << BOLD << BLUE << "==== TEST 4: Attacks ====" << RESET << std::endl;
    clap1.attack("a training dummy");
    scav1.attack("an intruder");
    frag1.attack("a robot enemy");

    std::cout << BOLD << BLUE << "==== TEST 5: Taking Damage & Repairing ====" << RESET << std::endl;
    clap2.takeDamage(5);
    clap2.beRepaired(3);

    scav2.takeDamage(20);
    scav2.beRepaired(10);

    frag2.takeDamage(30);
    frag2.beRepaired(20);

    std::cout << BOLD << BLUE << "==== TEST 6: Special Abilities ====" << RESET << std::endl;
    scav1.guardGate();
    frag1.highFivesGuys();

    std::cout << BOLD << BLUE << "==== TEST 7: Object Destruction ====" << RESET << std::endl;

    return 0;
}
