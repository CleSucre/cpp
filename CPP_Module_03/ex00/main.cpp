#include "ClapTrap.hpp"

int main() {
  std::cout << BOLD << BLUE << "==== TEST 1: Creating ClapTraps ====" << RESET << std::endl;
  ClapTrap a("Bob");
  ClapTrap b("Alice");

  std::cout << BOLD << BLUE << "==== TEST 2: Attacking and energy management ====" << RESET << std::endl;
  a.attack("Alice");
  b.attack("Bob");

  std::cout << BOLD << BLUE << "==== TEST 3: Bob takes damage ====" << RESET << std::endl;
  a.takeDamage(5);
  a.takeDamage(4);
  a.takeDamage(2);

  std::cout << BOLD << BLUE << "==== TEST 4: Alice repairs ====" << RESET << std::endl;
  b.beRepaired(3);
  b.beRepaired(4);
  b.beRepaired(2);

  std::cout << BOLD << BLUE << "==== TEST 5: Bob tries to repair himself while dead ====" << RESET << std::endl;
  a.beRepaired(5);

  std::cout << BOLD << BLUE << "==== TEST 6: Draining Alice's energy ====" << RESET << std::endl;
  for (int i = 0; i < 10; ++i) {
    b.attack("a wall");
  }
  b.attack("a wall");

  std::cout << BOLD << BLUE << "==== TEST 7: Copy and assignment ====" << RESET << std::endl;
  ClapTrap c = b;
  ClapTrap d;
  d = b;

  std::cout << BOLD << BLUE << "==== TEST 8: Modification after copy ====" << RESET << std::endl;
  b.takeDamage(3);
  c.takeDamage(2);
  d.beRepaired(4);

  std::cout << BOLD << BLUE << "==== END OF TESTS ====" << RESET << std::endl;
  return 0;
}
