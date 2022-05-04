//
// Created by znf on 4/13/22.
//

#include <cinder/app/AppBase.h>
#include "sim.h"

namespace petSimulator {
    Container::Container(Species spec1, Species spec2, Species spec3, Status state) {
        for (int i = 0; i < 5; i++) {
            double random_num1 = rand() % 550 + 100;
            double random_num2 = rand() % 550 + 100;
            Motion motion1 = Motion(vector<double>{random_num1, random_num2}, vector<double>{1.0, 1.0});
            Animal toadd = Animal(0, 0, spec1, state, motion1);
            this->animals.push_back(toadd);
        }
        for (int i = 0; i < 5; i++) {
            double random_num1 = rand() % 550 + 100;
            double random_num2 = rand() % 550 + 100;

            Motion motion1 = Motion(vector<double>{random_num1, random_num2}, vector<double>{1.0, 1.0});
            Animal toadd = Animal(0, 0, spec3, state, motion1);

            this->animals.push_back(toadd);
        }

        for (int i = 0; i < 2; i++) {
            double random_num1 = rand() % 550 + 100;
            double random_num2 = rand() % 550 + 100;
            Motion motion1 = Motion(vector<double>{random_num1, random_num2}, vector<double>{1.0, 1.0});
            Animal toadd = Animal(0, 0, spec2, state, motion1);
            this->animals.push_back(toadd);
        }
        std::cout << this->animals[0].motion.velocity << std::endl;
    }


    void Container::AddAnimal(Animal animal_to_add) {
        this->animals.push_back(animal_to_add);
    }

//    void Container::setRate(double rate) {
//        this-> hunt_success_rate = rate;
//    }
//
//    void Container::setTemperature(double rate) {
//        this->temperature = rate;
//    }

    vector<Animal> Container::getAnimals() {
        return this->animals;
    }

    void Container::AdvanceOneFrame() {

        for (Animal ani : this -> animals) {
            Status animal_status = ani.getStatus();
            if (animal_status.getCurHunger() < animal_status.getIdealHunger()) {
                //hunt for the nearest prey with 1.5speed
            }
            if (animal_status.getCurThirst() < animal_status.getIdealThirst()) {
                //go for water source
            }
            if (this->temperature >= ani.getSpecies().getTemp()) {
                //go for reproducing
            }
            std::cout << ani.getMotion().getPosition();
            //std::cout << ani.getMotion().getPosition() + ani.getMotion().getVelocity();

            ani.motion.position[0] += ani.motion.velocity[0];
            ani.motion.position[1] += ani.motion.velocity[1];
            std::cout << ani.motion.position;

            ani.setMotion(ani.motion.velocity, ani.motion.velocity);
            std::cout << ani.motion.position << std::endl;
        }
    }

}