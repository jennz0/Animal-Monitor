//
// Created by znf on 4/14/22.
//

#include "status.h"

namespace petSimulator {
    Status::Status ( int setMaxHunger,int setIdealHunger, int setCurHunger, int setMinHunger,int setMaxThirst, int setIdealThirst, int setCurThirst,  int setMinThirst) {
        this->alive = true;
        this-> current_hunger = setCurHunger;
        this -> current_thirst = setCurThirst;
        this-> max_hunger = setMaxHunger;
        this-> min_hunger = setMinHunger;
        this-> ideal_hunger = setIdealHunger;
        this->ideal_thirst = setIdealThirst;
        this-> max_thirst = setMaxThirst;
        this-> min_thirst = setMinThirst;
    }

    void Status::setAlive() {this -> alive = !alive;}
    void Status::setMinThirst(int hunger_level) {this -> min_thirst = hunger_level;}
    void Status::setMaxThirst(int hunger_level) {this -> max_thirst = hunger_level;}
    void Status::setIdealThirst(int hunger_level) {this -> ideal_thirst = hunger_level;}
    void Status::setIdealHunger(int hunger_level) {this -> ideal_hunger = hunger_level;}
    void Status::setMinHunger(int hunger_level) {this -> min_hunger = hunger_level;}
    void Status::setMaxHunger(int hunger_level) {this -> max_hunger = hunger_level;}
    void Status::setCurHunger(int hunger_level) {this->current_hunger = hunger_level;}
    void Status::setCurThirst(int hunger_level) {this->current_thirst = hunger_level;}

    bool Status::getAlive() {return this->alive;}
    int Status::getIdealHunger() {return this->ideal_hunger;}
    int Status::getMaxHunger() {return this->max_hunger;}
    int Status::getMinHunger() {return this->min_hunger;}
    int Status::getIdealThirst() {return this->ideal_thirst;}
    int Status::getMaxThirst() {return this->max_thirst;}
    int Status::getMinThirst() {return this->min_thirst;}
    int Status::getCurHunger() {return this->current_hunger;}
    int Status::getCurThirst() {return this->current_thirst;}


}

