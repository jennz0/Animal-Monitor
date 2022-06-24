//
// Created by znf on 4/14/22.
//

#pragma once

#include "vector"
#include <string>
#include <stdio.h>
#include <stdlib.h>

using std::string;
using std::vector;

namespace petSimulator {
    class Status {
    protected:
        bool alive;

        int current_hunger;
        int max_hunger;
        int min_hunger;
        int ideal_hunger;

        int current_thirst;
        int max_thirst;
        int min_thirst;
        int ideal_thirst;

    public:
        Status(int setIdealHunger, int setMaxHunger, int setCurHunger, int setCurThirst,
               int setMinHunger, int setIdealThirst, int setMaxThirst, int setMinThirst);

        void setAlive();
        bool getAlive();

        void setMaxHunger(int hunger_level);
        int getMaxHunger();

        void setMinHunger(int hunger_level);
        int getMinHunger();

        void setIdealHunger(int hunger_level);
        int getIdealHunger();

        void setIdealThirst(int hunger_level);
        int getIdealThirst();

        void setMaxThirst(int hunger_level);
        int getMaxThirst();

        void setMinThirst(int hunger_level);
        int getMinThirst();

        void setCurThirst(int hunger_level);
        int getCurThirst();

        void setCurHunger(int hunger_level);
        int getCurHunger();


    };
}

