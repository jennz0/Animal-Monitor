//
// Created by znf on 4/13/22.
//

#include <cinder/app/AppBase.h>
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

    void Container::setup()
    {
        auto img = loadImage( cinder::app::loadAsset( "zebra.png" ) );
        auto img1 = loadImage( cinder::app::loadAsset( "bison.png" ) );
        auto img2 = loadImage( cinder::app::loadAsset( "lion.png" ) );

        mTex = cinder::gl::Texture2d::create(img);
        mTex1 = cinder::gl::Texture2d::create(img1);
        mTex2 = cinder::gl::Texture2d::create(img2);
    }

    void Container::Display() {
        ci::gl::color(ci::Color("blue"));
        ci::gl::drawSolidEllipse(vec2(600, 350), 100.0f, 50.0f);
        ci::gl::drawSolidEllipse(vec2(400, 150), 80.0f, 50.0f);

        ci::gl::setMatricesWindow(cinder::app::getWindowSize());
        ci::gl::pushModelMatrix();
        ci::gl::translate(20,20);
        ci::gl::scale(0.2f,0.2f);
        ci::gl::color(ci::Color("white"));
        //Container::setup();
        auto img1 = loadImage( cinder::app::loadAsset( "bison.png" ) );
        mTex1 = cinder::gl::Texture2d::create(img1);

        cinder::gl::draw(mTex1);
//        ci::gl::popModelMatrix();
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