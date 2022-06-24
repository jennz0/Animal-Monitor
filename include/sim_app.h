#pragma once
#include "../../../include/cinder/app/App.h"
#include "../../../include/cinder/Cinder.h"
#include "../../../include/cinder/app/cocoa/AppMac.h"

#include "../../../include/cinder/app/RendererGl.h"
#include "../../../include/cinder/gl/gl.h"
#include "sim.h"
#include "species.h"
#include "animal.h"

namespace petSimulator {

class PetSimulator : public ci::app::App {
    public:
        PetSimulator();


        vector<Animal> getAnimals();
        void Display();
        //void AdvanceOneFrame();
        void AddAnimal(Animal animal_to_add);
        void setRate(double rate);
        void setTemperature(double rate);

        void draw() override;
        void update() override;
        void setup() override;

        const int kWindowSize = 1000;
        const int kMargin = 100;


private:
        Container* container_;

        vector<Animal> animals;
        double hunt_success_rate;
        double temperature;

        cinder::gl::Texture2dRef mTex;
        cinder::gl::Texture2dRef mTex1;
        cinder::gl::Texture2dRef mTex2;
        cinder::gl::Texture2dRef mTex3;


    void Legends();

    void DisplayString();

    void DisplayGrass();
};

}
