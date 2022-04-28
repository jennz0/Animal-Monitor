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
        auto img1 = loadImage( cinder::app::loadAsset( "bison.png" ) );
        auto img2 = loadImage( cinder::app::loadAsset( "lion.png" ) );

        mTex = cinder::gl::Texture2d::create(img);
        mTex1 = cinder::gl::Texture2d::create(img1);
        mTex2 = cinder::gl::Texture2d::create(img2);
    }

    void PetSimulator::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);

        this->Display();
        this->DisplayString();
        this->Legends();

    }

    void PetSimulator::update() {
        this->AdvanceOneFrame();
    }

    void PetSimulator::AddAnimal(Animal animal_to_add) {
        this-> animals.push_back(animal_to_add);
    }

    void PetSimulator::setRate(double rate) {
        this-> hunt_success_rate = rate;
    }

    void PetSimulator::setTemperature(double rate) {
        this->temperature = rate;
    }

    vector<Animal> PetSimulator::getAnimals() {
        return this->animals;
    }



    void PetSimulator::Display() {
        ci::gl::color(ci::Color("green"));

        ci::gl::drawSolidRect(ci::Rectf(vec2(70, 30), vec2(700, 700)));
        ci::gl::color(ci::Color("blue"));
        ci::gl::drawSolidEllipse(vec2(200, 520), 100.0f, 50.0f);
        ci::gl::drawSolidEllipse(vec2(500, 150), 80.0f, 50.0f);

        ci::gl::setMatricesWindow(cinder::app::getWindowSize());
        ci::gl::pushModelMatrix();

        ci::gl::color(ci::Color("white"));

    }
    void PetSimulator::DisplayString() {
        ci::gl::color(ci::Color("white"));
        //ci::gl::scale(10.0f,10.0f);

        ci::gl::drawString("Legends", vec2(800, 30));
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
        ci::gl::translate(0,800);

        cinder::gl::draw(mTex2);

        ci::gl::popModelMatrix();
    }
    void PetSimulator::AdvanceOneFrame() {

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