//
// Created by znf on 4/14/22.
//

#include "animal.h"

namespace petSimulator {
    Animal::Animal(int setid, int setgender, Species species, Status status) : species(species), status(status) {
        this-> id = setid;
        //this-> status = status1;
        this->gender = setgender;

        Species theSpecies(species.getSpecies(), species.getTemp());
        this->species = theSpecies;

        Status theStatus(status.getIdealHunger(), status.getMaxHunger(), status.getCurHunger(), status.getCurThirst(), status.getMinHunger(),
            status.getIdealThirst(), status.getMaxThirst(), status.getMinThirst());
        this->status = theStatus;
    }

    Species Animal::getSpecies() {return this->species;}
    //Status Animal::getStatus() {return this->status;}
}