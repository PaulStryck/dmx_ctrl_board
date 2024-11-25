#ifndef SHOW4_H
#define SHOW4_H

#include <inttypes.h>
#include "dmx_manager.h"
#include "show.h"

struct show4_pos {
    uint8_t col : 4;
    uint8_t row : 4;
} __attribute__((packed));

class Show4 : public Show {
public:
    Show4 (const uint8_t (*assoc[2])[8][6], DMX_Manager* mgr );
    // ~Show4 ( void );

    void tick( void ) override;
    void reset ( void ) override;

private:
    void update();

    DMX_Manager *_mgr;
    uint32_t _ticks;
    uint8_t col = 0;
    uint8_t ind = 0;
    show4_pos rows[20] = {{0xF, 0xF}};

    const uint8_t (*_assoc[2])[8][6];
};

#endif
