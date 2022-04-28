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

        cinder::gl::Texture2dRef mTex;
        cinder::gl::Texture2dRef mTex1;
        cinder::gl::Texture2dRef mTex2;
    public:
        Container();

        vector<Animal> getAnimals();
        void Display();
        void AdvanceOneFrame();
        void AddAnimal(Animal animal_to_add);
        void setRate(double rate);
        void setTemperature(double rate);

        void setup();
    };
}
