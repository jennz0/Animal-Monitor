//
// Created by znf on 4/14/22.
//
#include "species.h"

namespace petSimulator {
    Species::Species(string setSpecies, double idealT) {//, vector<Animal> setPrey) {
        this-> species = setSpecies;
        this->temperature_to_mate = idealT;
//        if (setPrey.size() > 0) {
//            for (Animal p : setPrey) {
//                this->prey.push_back(p);
//            }
//        }
    }

    //void Species::setPrey(vector<Animal> pr) {this->prey = pr;}
    void Species::setSpecies(string sp) {this-> species = sp;}

    void Species::setTemp(double setIdealT) {this->temperature_to_mate = setIdealT;}
    //vector<Animal> Species::getPrey() {return this->prey;}
    string Species::getSpecies() {return this-> species;}

    double Species::getTemp() {return this->temperature_to_mate;}
}
