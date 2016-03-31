

#include "Weapon.hpp"

#include <iostream>

Weapon::Weapon(int s) : strength(s) {
    
}

int Weapon::getStrenght() const {
    return strength;
}

void Weapon::setStrenght(int strength) {
    this->strength = strength;
}

