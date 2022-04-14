//
// Created by znf on 4/14/22.
//

#ifndef IDEAL_GAS_ANIMAL_H
#define IDEAL_GAS_ANIMAL_H

#include "vector"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "species.h"
#include "status.h"

using std::string;
using std::vector;

namespace petSimulator {
    class Animal {
    private:
        int id;
        int gender;
        Species species;
        Status status;

    public:
        Animal (int setid, int setgender, Species setSpecies, Status setStatus);
        Species getSpecies();
        Status getStatus();
    };
}



#endif //IDEAL_GAS_ANIMAL_H
