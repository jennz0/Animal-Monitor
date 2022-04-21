//
// Created by znf on 4/13/22.
//
#include "sim.h"
#include "sim_app.h"
#include "utility"
using std::pair;
using petSimulator::PetSimulator;

void prepareSettings(petSimulator::PetSimulator::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(PetSimulator, ci::app::RendererGl, prepareSettings);
