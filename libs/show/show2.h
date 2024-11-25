#ifndef SHOW2_H
#define SHOW2_H

#include <inttypes.h>
#include "dmx_manager.h"
#include "show.h"


class Show2 : public Show {
public:
    Show2 ( DMX_Manager* mgr );
    // ~Show2 ( void );

    void tick( void ) override;
    void reset ( void ) override;

private:
    DMX_Manager *_mgr;
    uint32_t _ticks;
    uint8_t rnd[8];
};

#endif
