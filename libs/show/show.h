#ifndef SHOW_H
#define SHOW_H

#include <inttypes.h>
#include "dmx_manager.h"


class Show {
    public:
        virtual void tick( void ) = 0;
        virtual void reset( void ) = 0;

    protected:
        ~Show(void) {};
};

#endif
