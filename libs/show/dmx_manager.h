#ifndef DMX_MANAGER_H
#define DMX_MANAGER_H

#include <inttypes.h>
#include "LXSAMD21DMX.h"

#define APPLIANCES 79


enum dmx_manager_states: uint8_t {
    SET = 1,
    DIMM,
    ACK
};

struct dmx_manager_appliance {
    uint8_t target_value;
    dmx_manager_states operation : 4;
    uint8_t crement : 4;
};

class DMX_Manager {
    public:
        DMX_Manager ( LXSAMD21DMX* dmx_ctrl);
        ~DMX_Manager ( void );

        void setAppliance(const uint8_t appl, dmx_manager_appliance config);
        void reset ( void );

        void tick( void );

    private:
        dmx_manager_appliance _appliances[APPLIANCES];
        LXSAMD21DMX* _dmx_ctrl;
};

#endif // ifndef DMX_MANAGER_H
