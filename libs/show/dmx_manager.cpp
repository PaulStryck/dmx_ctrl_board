#include <atmel_start.h>
#include "dmx_manager.h"
#include <utils.h>
#include "task.h"


DMX_Manager::DMX_Manager( LXSAMD21DMX* dmx_ctrl ) : _dmx_ctrl(dmx_ctrl){}
DMX_Manager::~DMX_Manager( void ){}


void DMX_Manager::setAppliance(uint8_t appl, dmx_manager_appliance config)
{
    if(appl >= APPLIANCES)
        return;

    _appliances[appl] = config;
}


void DMX_Manager::reset( void )
{
    for(uint8_t i = 0; i < APPLIANCES; i++)
    {
        _appliances[i] = {0, SET, 0};
        _dmx_ctrl->setSlot(i+1, 0);
    }
}


void DMX_Manager::tick( void )
{
    uint8_t curr = 0;
    uint8_t updated = 0;
    dmx_manager_appliance* appl;

    for(int i = 0; i < APPLIANCES; i++)
    {
        appl = &_appliances[i];

        // Slot indices start at 1
        curr = _dmx_ctrl->getSlot(i+1);


        if(curr != appl->target_value)
        {
            switch(appl->operation)
            {
                case ACK:
                    // Broken state if this happens
                    // Revert to set expected value
                case SET:
                    _dmx_ctrl->setSlot(i+1, appl->target_value);
                    appl->operation = ACK;
                    break;
                case DIMM:
                    updated = 0;
                    if(curr < appl->target_value)
                        updated = min(curr + 2*appl->crement, appl->target_value);
                    else
                        updated = max(curr - 2*appl->crement, appl->target_value);

                    _dmx_ctrl->setSlot(i+1, updated);

                    if(updated == appl->target_value)
                        appl->operation = ACK;
                    break;
            }
        }
    }
}
