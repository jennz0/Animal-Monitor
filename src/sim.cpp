//
// Created by znf on 4/13/22.
//

#include "sim.h"

namespace petSimulator {
    Container::Container() {
        this->animals = vector<Animal>();
    }


    void Container::AddAnimal(Animal animal_to_add) {
        this-> animals.push_back(animal_to_add);
    }

    void Container::setRate(double rate) {
        this-> hunt_success_rate = rate;
    }

    void Container::setTemperature(double rate) {
        this->temperature = rate;
    }

    vector<Animal> Container::getAnimals() {
        return this->animals;
    }
    void Container::Display() const {
        ci::gl::color(ci::Color("red"));
        ci::gl::drawSolidRect(ci::Rectf(vec2(600, 350), vec2(900, 500)));
    }
    void Container::AdvanceOneFrame() {
//        for (Animal animal: this->animals) {
//            Status animal_status = animal.getStatus();
//            if (animal_status.getCurHunger() < animal_status.getIdealHunger()) {
//                //hunt for the nearest prey with 1.5speed
//            }
//            if (animal_status.getCurThirst() < animal_status.getIdealThirst()) {
//                //go for water source
//            }
//            if (this->temperature >= animal.getSpecies().getTemp()) {
//                //go for reproducing
//            }

//        }
    }
}