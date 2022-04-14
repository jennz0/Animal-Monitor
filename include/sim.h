//
// Created by znf on 4/13/22.
//

#ifndef FINAL_PROJECT_SAMUELZNF_SIM_H
#define FINAL_PROJECT_SAMUELZNF_SIM_H
#include "species.h"
#include "animal.h"

namespace petSimulator {
    class Container {
    private:
        vector<Animal> animals;
        double hunt_success_rate;
        double temperature;
    public:
        Container();

        void Display() const;
        void AdvanceOneFrame();
        void AddAnimal(Animal animal_to_add);
        void setRate(double rate);
        void setTemperature(double rate);
    };
}
#endif //FINAL_PROJECT_SAMUELZNF_SIM_H
