//
// Created by znf on 4/28/22.
//

#include "motion.h"
using glm::vec2;


namespace petSimulator {
    Motion::Motion (vector<double> pos, vector<double> vel) {
        position = vec2(pos[0],pos[1]);
        velocity = vec2(vel[0],vel[1]);
    }

    void Motion::setVelocity(vec2 vel) {
        this->velocity = vec2(vel[0],vel[1]);
    }
    void Motion::setPosition(vec2 pos) {
        std::cout << 77 << std::endl;
        this->position += pos;//vec2(pos[0],pos[1]);
    }
    void Motion::accumulate(vec2 vel) {
        this ->position += vel;
    }
    vec2 Motion::getVelocity() {
        return this->velocity;
    }
    vec2 Motion::getPosition() {
        return this->position;
    }




}