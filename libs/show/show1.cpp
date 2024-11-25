#include "show1.h"
#include "LXSAMD21DMX.h"


Show1::Show1( const show_light_conf* lights, DMX_Manager *mgr)
    : _lights(lights), _ticks(0), _n(0), _mgr(mgr) {

}


void Show1::reset() {
    const show_light_conf*  light;
    const show_light_state* state;

    show_light_counter* cnt;

    _mgr->reset();

    _ticks = 0;

    // reset all to initial state
    for(uint8_t i = 0; i < 39; i++)
    {
        light = &_lights[i];
        cnt = &_counter[i];

        cnt->state = 0;
        cnt->ticks = 0;


        state = &(light->states[0]);

        // update all appliances
        if(state->state)
            _mgr->setAppliance(i, {255, SET, 2});
        else
            _mgr->setAppliance(i, {0, SET, 2});
    }

}


void Show1::tick( void ) {
    const show_light_conf* light;
    const show_light_state* state;

    show_light_counter* cnt;

    _n = (_n+1) % 2;
    if(_n == 0) return;

    _ticks++;

    for(uint8_t i = 0; i < 39; i++)
    {
        light = &_lights[i];
        cnt = &_counter[i];

        state = &(light->states[cnt->state]);

        if(_ticks - cnt->ticks < state->nticks)
            continue;

        // change state
        cnt->state = (cnt->state + 1) % (light->n);
        cnt->ticks = _ticks;

        // update light state
        if(state->state)
            _mgr->setAppliance(i, {255, SET, 8});
        else
            _mgr->setAppliance(i, {0, SET, 8});
    }
}
