#pragma once
#include "../../../include/cinder/app/App.h"
#include "../../../include/cinder/Cinder.h"
#include "../../../include/cinder/app/cocoa/AppMac.h"

#include "../../../include/cinder/app/RendererGl.h"
#include "../../../include/cinder/gl/gl.h"
#include "sim.h"

namespace petSimulator {

class PetSimulator : public ci::app::App {
    public:
        PetSimulator();

        void draw() override;
        void update() override;
        void setup() override;

        const int kWindowSize = 875;
        const int kMargin = 100;


private:
        Container* container_;
        cinder::gl::Texture2dRef mTex;
    };

}
