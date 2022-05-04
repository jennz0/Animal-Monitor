//
// Created by znf on 4/14/22.
//
#pragma once
#include "vector"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "species.h"
#include "status.h"
#include "motion.h"

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
        Motion motion;

        Animal(int setid, int setgender, Species species, Status status, Motion motion);
        Species getSpecies();
        Status getStatus();
        Motion getMotion();

        void setMotion(vec2 pos, vec2 vel);
    };
}