//
// Created by znf on 4/14/22.
//

#include "animal.h"

namespace petSimulator {
    Animal::Animal(int setid, int setgender, Species species, Status status, Motion motion) : species(species), status(status),
                                                                                              motion(motion) {
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
    Motion Animal::getMotion() {return this->motion;}
    Status Animal::getStatus() {return this->status;}

    void Animal::setMotion(vec2 pos, vec2 vel) {
        std::cout <<22;

        this->motion.setPosition(pos);
        this->motion.setVelocity(vel);
    }
}