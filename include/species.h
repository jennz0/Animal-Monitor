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
    class Species {
    protected:
        string species;
        double temperature_to_mate;
        //vector<Animal> prey;
    public:
        Species(string setSpecies, double setIdealT);//, vector<Animal> setPrey);
        //void setPrey(vector<Animal> pr);
        void setSpecies(string sp);
        void setTemp(double setIdealT);
        string getSpecies();
        double getTemp();
        //vector<Animal> getPrey();

    };
}