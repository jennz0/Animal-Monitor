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
        Container(Species spec1, Species spec2, Species spec3, Status state);
        vector<Animal> getAnimals();
        void hunt(Animal current_animal);

        void AddAnimal(Animal animal_to_add);
        void setRate(double rate);
        void setTemperature(double rate);

        void setup();

        void AdvanceOneFrame();

        vec2 findNearPond(vec2 cur_pos);
    };
}
