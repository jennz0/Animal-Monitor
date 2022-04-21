//
// Created by znf on 4/21/22.
//
#include "sim_app.h"

namespace petSimulator {
    PetSimulator::PetSimulator() {
        Species spec1 = Species("zebra", 30);
        Status state1 = Status(100, 30, 60,0, 100, 20, 60,0);
        Animal toadd = Animal(0, 0, spec1, state1);
        //this->container_->AddAnimal(toadd);
        //std::cout<< this->container_->getAnimals().size() << std::endl;
        ci::app::setWindowSize(kWindowSize, kWindowSize);
    }

    void PetSimulator::setup()
    {
        auto img = loadImage( cinder::app::loadAsset( "zebra.png" ) );
        mTex = cinder::gl::Texture2d::create(img);
    }

    void PetSimulator::draw() {
        ci::Color background_color("green");
        ci::gl::clear(background_color);
        ci::gl::setMatricesWindow(getWindowSize());
        ci::gl::pushModelMatrix();
        ci::gl::translate(20,20);
        ci::gl::scale(0.2f,0.2f);
        ci::gl::color(ci::Color("white"));
        cinder::gl::draw( mTex);
        ci::gl::popModelMatrix();
        container_->Display();
    }

    void PetSimulator::update() {
        container_->AdvanceOneFrame();
    }
}