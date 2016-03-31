

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <cstdlib>
#include <string>
#include "Weapon.hpp"




class Character {
public:
    Character(int hp, int l, int a=1, int x=0, int y=0);
    explicit Character(std::string n, int hp=10, int l=1);
    virtual ~Character();
    
    virtual void move(int x, int y) = 0;
    virtual int fight(Character& enemy) = 0;
    
    int getHp() const;
    void setHp(int hp);
    
    int getLevel() const;
    void setLevel(int level);
    
    const std::string& getName() const;
    void setName(const std::string& name);
    
    const Weapon* getWeapon() const;
    void setWeapon(Weapon* weapon);
    
protected:
    int hp;
    int posX, posY;
    int level;
    int armor;
    std::string name;
    Weapon* weapon;
};





#endif /* Character_hpp */


