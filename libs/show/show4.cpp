#include "show4.h"
#include "graph.h"
#include "rng.h"

extern xorshift32_state rng_state;


Show4::Show4 (const uint8_t (*assoc[2])[8][6], DMX_Manager* mgr)
    :  _mgr(mgr), _ticks(0) {
        _assoc[0] = assoc[0];
        _assoc[1] = assoc[1];
}

// Show4::~Show4(){}

void Show4::reset() {
    _mgr->reset();
    _ticks = 0;
}

void Show4::tick(){
    _ticks = (_ticks + 1) % 42;
    uint8_t rnd;

    if(_ticks%7 == 0)
        update();

    if(_ticks != 0)
        return;

    rnd = random(&rng_state, 0, 5);

    if(rnd > 5) return;

    ind++;
    if(!(ind < 20))
        ind = 0;

    rows[ind] = {.col=rnd, .row=0};

    rnd = random(&rng_state, 6, 11);

    if(rnd > 11) return;

    ind++;
    if(!(ind < 20))
        ind = 0;

    rows[ind] = {.col=rnd, .row=0};
}

void Show4::update() {
    uint8_t side = 0;
    uint8_t col = 0;
    uint8_t row = 0;

    for(uint8_t i = 0; i < 20; i++) {
        if(rows[i].col == 0xF) continue;

        if(rows[i].col < 6) {
            side = 0;
            col = rows[i].col;
        } else {
            side = 1;
            col = rows[i].col - 6;
        }

        row = rows[i].row;

        // start fading out last block
        if(rows[i].row > 0) {
            _mgr->setAppliance(
                    (*_assoc[side])[row-1][col],
                    {0, DIMM, 1}
            );
        }

        if(!(row < 8)) {
            rows[i] = {0xF, 0xF};
            continue;
        }

        // Set current block
        _mgr->setAppliance(
                (*_assoc[side])[row][col],
                {200, DIMM, 4}
        );

        rows[i].row++;
    }
}
