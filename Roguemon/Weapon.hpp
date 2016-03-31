

#ifndef Weapon_hpp
#define Weapon_hpp

#include <stdio.h>

class Weapon {
public:
    explicit Weapon(int s=6);
    virtual ~Weapon() {};
    virtual int useWeapon() = 0;
    
    int getStrenght() const;
    void setStrenght(int strenght);
    
protected:
    int strength;
};


#endif /* Weapon_hpp */
