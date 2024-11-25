#include "show3.h"
#include "dmx_manager.h"
#include "rng.h"

extern xorshift32_state rng_state;

Show3::Show3(DMX_Manager *mgr) :  _mgr(mgr), _ticks(0) {
    for(uint8_t i = 0; i < 4; i++){
        rnd[i] = random(&rng_state, 1, APPLIANCES);
        _mgr->setAppliance(rnd[i], {255, DIMM, 8});
    }
}

// Show3::~Show3(){}

void Show3::reset() {
    _mgr->reset();
    _ticks = 0xFFFFFFFF;
}

void Show3::tick(){
    _ticks = (_ticks + 1) % 40;

    if(_ticks == 0)
    {
        for(uint8_t i = 0; i < 2; i++){
            _mgr->setAppliance(rnd[i], {0, DIMM, 8});
            rnd[i] = random(&rng_state, 0, 38);
            _mgr->setAppliance(rnd[i], {255, DIMM, 8});
        }

        for(uint8_t i = 2; i < 4; i++){
            _mgr->setAppliance(rnd[i], {0, DIMM, 8});
            rnd[i] = random(&rng_state, 40, APPLIANCES-1);
            _mgr->setAppliance(rnd[i], {255, DIMM, 8});
        }
    }

    int foo = random(&rng_state, 0, 50);
    if(foo > 27 && foo < 30)
    {
        for(uint8_t i = 4; i < 6; i++){
            _mgr->setAppliance(rnd[i], {0, DIMM, 8});
            rnd[i] = random(&rng_state, 0, 38);
            _mgr->setAppliance(rnd[i], {255, DIMM, 8});
        }

        for(uint8_t i = 6; i < 8; i++){
            _mgr->setAppliance(rnd[i], {0, DIMM, 8});
            rnd[i] = random(&rng_state, 40, APPLIANCES-1);
            _mgr->setAppliance(rnd[i], {255, DIMM, 8});
        }
    }
}
