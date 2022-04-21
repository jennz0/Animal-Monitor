//
// Created by znf on 4/13/22.
//

#pragma once
#include "species.h"
#include "animal.h"
#include "cinder/gl/gl.h"
using glm::vec2;


namespace petSimulator {
    class Container {
    private:
        vector<Animal> animals;
        double hunt_success_rate;
        double temperature;
    public:
        Container();

        vector<Animal> getAnimals();
        void Display() const;
        void AdvanceOneFrame();
        void AddAnimal(Animal animal_to_add);
        void setRate(double rate);
        void setTemperature(double rate);
    };
}
