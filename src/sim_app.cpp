//
// Created by znf on 4/21/22.
//
#include "sim_app.h"

namespace petSimulator {
    PetSimulator::PetSimulator() {
        Species spec1 = Species("zebra", 30);
        Species spec2 = Species("lion", 30);
        Species spec3 = Species("bison", 30);

        Status default_state = Status(100, 30, 60,0, 100, 20, 60,0);
        Motion motion1 = Motion(vector<double>{300.0,300.0}, vector<double>{3.0, 3.0});
        Animal toadd = Animal(0, 0, spec1, default_state, motion1);

        this->container_ = new Container(spec1, spec2, spec3, default_state);
        this->container_->AddAnimal(toadd);
        std::cout<< this->container_->getAnimals().size() << std::endl;
        ci::app::setWindowSize(kWindowSize, kWindowSize);
    }

    void PetSimulator::setup()
    {
        auto grass = loadImage( cinder::app::loadAsset( "grass.png" ) );

        auto img = loadImage( cinder::app::loadAsset( "zebra.png" ) );
        auto img1 = loadImage( cinder::app::loadAsset( "bison.png" ) );
        auto img2 = loadImage( cinder::app::loadAsset( "lion.png" ) );

        mTex = cinder::gl::Texture2d::create(img);
        mTex1 = cinder::gl::Texture2d::create(img1);
        mTex2 = cinder::gl::Texture2d::create(img2);
        mTex3 = cinder::gl::Texture2d::create(grass);

    }

    void PetSimulator::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);

        this->Display();
        this->DisplayString();
        this->Legends();
        //this->DisplayGrass();

    }

    void PetSimulator::update() {
        this->container_->AdvanceOneFrame();
    }

    void PetSimulator::setRate(double rate) {
        this-> hunt_success_rate = rate;
    }

    void PetSimulator::setTemperature(double rate) {
        this->temperature = rate;
    }

    void PetSimulator::Display() {
        ci::gl::color(ci::Color("green"));

        ci::gl::drawSolidRect(ci::Rectf(vec2(70, 30), vec2(700, 700)));
        ci::gl::color(ci::Color("blue"));
        ci::gl::drawSolidEllipse(vec2(200, 520), 100.0f, 50.0f);
        ci::gl::drawSolidEllipse(vec2(500, 150), 80.0f, 50.0f);

        ci::gl::setMatricesWindow(cinder::app::getWindowSize());
        ci::gl::color(ci::Color("white"));

        //ci::gl::pushModelMatrix();

        ci::gl::color(ci::Color("white"));

        for (Animal ani : this->container_->getAnimals()) {
            if (ani.getSpecies().getSpecies().compare("zebra") == 0) {
                ci::gl::color(ci::Color("white"));
                ci::gl::drawSolidCircle(ani.motion.position, 20.0);
            }
            if (ani.getSpecies().getSpecies().compare("lion") == 0) {
                ci::gl::color(ci::Color("orange"));
                ci::gl::drawSolidCircle(ani.getMotion().getPosition(), 20.0);
            }
            if (ani.getSpecies().getSpecies().compare("bison") == 0) {
                ci::gl::color(ci::Color("brown"));
                ci::gl::drawSolidCircle(ani.getMotion().getPosition(), 20.0);
            }
        }

    }
    void PetSimulator::DisplayString() {
        ci::gl::color(ci::Color("white"));
        ci::gl::drawString("Legends", vec2(800, 30));
    }

    void PetSimulator::DisplayGrass() {
        ci::gl::scale(0.1f,0.1f);
        cinder::gl::draw(mTex3);
        ci::gl::translate(0,800);
    }
    void PetSimulator::Legends() {

        ci::gl::setMatricesWindow(cinder::app::getWindowSize());
        ci::gl::pushModelMatrix();
        ci::gl::translate(20,20);
        ci::gl::color(ci::Color("white"));
        this->setup();
        ci::gl::scale(0.2f,0.2f);
        ci::gl::translate(3500,300);

        cinder::gl::draw(mTex1);
        ci::gl::translate(0,800);

        cinder::gl::draw(mTex);

        ci::gl::scale(0.25f,0.15f);
        ci::gl::translate(0,5800);

        cinder::gl::draw(mTex2);


        ci::gl::popModelMatrix();
    }

}