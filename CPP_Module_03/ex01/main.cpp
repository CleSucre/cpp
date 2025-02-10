#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  std::cout << BOLD << BLUE << "==== TEST 1: Creating ClapTrap ====" << RESET << std::endl;
  ClapTrap clap1("Clappy");
  ClapTrap clap2("Trapster");

  std::cout << BOLD << BLUE << "==== TEST 2: Creating ScavTrap ====" << RESET << std::endl;
  ScavTrap scav1("Guardian");
  ScavTrap scav2("Protector");

  std::cout << BOLD << BLUE << "==== TEST 3: Attacks ====" << RESET << std::endl;
  clap1.attack("a training dummy");
  scav1.attack("an intruder");

  std::cout << BOLD << BLUE << "==== TEST 4: Taking Damage & Repairing ====" << RESET << std::endl;
  clap2.takeDamage(5);
  clap2.beRepaired(3);

  scav2.takeDamage(20);
  scav2.beRepaired(10);

  std::cout << BOLD << BLUE << "==== TEST 5: Gate Keeper Mode ====" << RESET << std::endl;
  scav1.guardGate();

  std::cout << BOLD << BLUE << "==== TEST 6: Object Destruction ====" << RESET << std::endl;
  return 0;
}
