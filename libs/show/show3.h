#ifndef SHOW3_H
#define SHOW3_H

#include <inttypes.h>
#include "dmx_manager.h"
#include "show.h"


class Show3 : public Show {
public:
    Show3 ( DMX_Manager* mgr );
    // ~Show3 ( void );

    void tick( void ) override;
    void reset ( void ) override;

private:
    DMX_Manager *_mgr;
    uint32_t _ticks;
    uint8_t rnd[8];
};

#endif
