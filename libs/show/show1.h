#ifndef SHOW1_H
#define SHOW1_H

#include <inttypes.h>
#include "dmx_manager.h"
#include "show.h"


struct show_light_state {
    bool state;
    uint16_t nticks;
};


struct show_light_conf {
    const struct show_light_state* states;
    uint8_t n;
};


struct show_light_counter {
    uint8_t state;
    uint16_t ticks;
};


class Show1 : public Show
{
public:
    Show1 ( const show_light_conf* lights, DMX_Manager* mgr );

    void tick ( void ) override;
    void reset ( void ) override;

private:
    const show_light_conf* _lights;

    uint32_t _ticks;

    uint8_t _n;
    DMX_Manager *_mgr;

    show_light_counter _counter[39] = {{.state=0, .ticks=0}};
};

#endif
