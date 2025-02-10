#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << BOLD << BLUE << "==== TEST 1: Creating DiamondTrap ====" << RESET << std::endl;
    DiamondTrap dt1("Warrior");
    DiamondTrap dt2("Champion");

    std::cout << BOLD << BLUE << "==== TEST 2: Testing whoAmI() ====" << RESET << std::endl;
    dt1.whoAmI();
    dt2.whoAmI();

    std::cout << BOLD << BLUE << "==== TEST 3: Attacks ====" << RESET << std::endl;
    dt1.attack("a training dummy");
    dt2.attack("an enemy robot");

    std::cout << BOLD << BLUE << "==== TEST 4: Taking Damage & Repairing ====" << RESET << std::endl;
    dt1.takeDamage(30);
    dt1.beRepaired(20);

    dt2.takeDamage(80);
    dt2.beRepaired(50);

    std::cout << BOLD << BLUE << "==== TEST 5: Energy Points ====" << RESET << std::endl;
    for (int i = 0; i < 5; ++i) {
        dt1.attack("an enemy");
    }

    std::cout << BOLD << BLUE << "==== TEST 6: Object Destruction ====" << RESET << std::endl;
    return 0;
}
