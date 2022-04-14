//
// Created by znf on 4/14/22.
//

#include "animal.h"

namespace petSimulator {
    Animal::Animal(int setid, int setgender, Species setSpecies) {
        this-> id = setid;
        //this-> status = status1;
        this->gender = setgender;
        this -> species = setSpecies;
    }

    Species Animal::getSpecies() {return this->species;}
    Status Animal::getStatus() {return this->status;}
}