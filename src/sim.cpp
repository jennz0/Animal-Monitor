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
        this -> temperature = 35;
    }


    void Container::AddAnimal(Animal animal_to_add) {
        this->animals.push_back(animal_to_add);
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
    void Container::hunt(Animal current_animal) {
        string animal_species = current_animal.getSpecies().getSpecies();
        Status animal_status = current_animal.getStatus();
        if (animal_status.getCurHunger() < animal_status.getIdealHunger() && animal_species.compare("lion") == 0) {
            //hunt for the nearest prey with 1.5speed
            for (int j = 0; j < this->animals.size(); j++) {
                string prey_species = animals[j].getSpecies().getSpecies();
                if (prey_species.compare("bison") || prey_species.compare("zebra")) {
                    vec2 target_coord = animals[j].motion.position;
                    vec2 direction = target_coord - current_animal.motion.position;
                    if (direction.length() <= 100) {
                        current_animal.getStatus().setCurHunger(current_animal.getStatus().getMaxHunger());
                        animals[j].getStatus().setAlive();
                        break;
                    }
                    direction /= sqrt(direction[0]*direction[0] + direction[1]*direction[1]);
                    direction *= 1.5;
                    current_animal.motion.velocity = direction;
                }
            }
        }
    }

    vec2 Container::findNearPond(vec2 cur_pos) {
        double dist1 = (vec2(200, 520)-cur_pos).length();
        double dist2 = (vec2(500, 150)-cur_pos).length();
        if (dist1 < dist2) {
            return vec2(200, 520);
        }
        return vec2(500, 150);
    }

    void Container::AdvanceOneFrame() {

        for (int i = 0; i < this->animals.size(); i++) {
            Animal ani = animals[i];
            Status animal_status = ani.getStatus();
            if (!animal_status.getAlive()) {
                this->animals.erase(animals.begin() + i);
                continue;
            }
            this->hunt(ani);
            if (animal_status.getCurThirst() < animal_status.getIdealThirst()) {
                //go for water source
                vec2 direction = findNearPond(ani.motion.position) - ani.motion.position;
                if (direction.length() <= 100) {
                    ani.getStatus().setCurThirst(ani.getStatus().getMaxThirst());
                    continue;
                }
                direction /= sqrt(direction[0]*direction[0] + direction[1]*direction[1]);
                direction *= 1.5;
                ani.motion.velocity = direction;
            }
            if (this->temperature >= ani.getSpecies().getTemp()) {
                //go for reproducing
            }
            //std::cout << ani.getMotion().getPosition();

            ani.motion.position[0] += ani.motion.velocity[0];
            ani.motion.position[1] += ani.motion.velocity[1];
            //std::cout << ani.motion.position;

            ani.setMotion(ani.motion.velocity, ani.motion.velocity);
            std::cout << ani.motion.position << std::endl;

            if (ani.motion.position[0] <= 100 || ani.motion.position[0] >= 650) {
                ani.motion.velocity[0] *= -1;
            }
            if (ani.motion.position[1] <= 100 || ani.motion.position[1] >= 650) {
                ani.motion.velocity[1] *= -1;
            }
            ani.getStatus().setCurThirst(ani.getStatus().getCurThirst()-5);
            ani.getStatus().setCurHunger(ani.getStatus().getCurHunger()-5);

        }
    }

}