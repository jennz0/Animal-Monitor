//
// Created by znf on 4/28/22.
//

#pragma once

#include "vector"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "cinder/gl/gl.h"

using glm::vec2;


using std::string;
using std::vector;

namespace petSimulator {
    class Motion {
    protected:
        vec2 position;
        vec2 velocity;

    public:
        Motion(vector<double> pos, vector<double> vel);
        void setVelocity(vec2 vel);
        void setPosition(vec2 pos);
        vec2 getVelocity();
        vec2 getPosition();


        void accumulate(vec2 vel);
    };
}