#include "show2.h"
#include "dmx_manager.h"
#include "rng.h"

extern xorshift32_state rng_state;

Show2::Show2(DMX_Manager *mgr) :  _mgr(mgr), _ticks(0) {
    for(uint8_t i = 0; i < 4; i++){
        rnd[i] = random(&rng_state, 1, APPLIANCES);
        _mgr->setAppliance(rnd[i], {255, DIMM, 8});
    }
}


// Show2::~Show2(){}

void Show2::reset() {
    _mgr->reset();
    _ticks = 0xFFFFFFFF;
}

void Show2::tick(){
    _ticks = (_ticks + 1) % 120;
    if(_ticks > 0) return;

    uint8_t ls;

    ls = random(&rng_state, 1, 4);

    for(uint8_t i = 0; i < 4; i++){
        if(rnd[i] != 0xFF)
            _mgr->setAppliance(rnd[i], {0, DIMM, 8}); // reset old

        if(i < ls) {
            rnd[i] = random(&rng_state, 0, 38);
            _mgr->setAppliance(rnd[i], {255, DIMM, 4});
        } else {
            rnd[i] = 0xFF;
        }
    }

    for(uint8_t i = 4; i < 8; i++){
        if(rnd[i] != 0xFF)
            _mgr->setAppliance(rnd[i], {0, DIMM, 8}); // reset old

        if(i < ls+4) {
            rnd[i] = random(&rng_state, 39, 78);
            _mgr->setAppliance(rnd[i], {255, DIMM, 4});
        } else {
            rnd[i] = 0xFF;
        }
    }
}
