#include "custom_driver_init.h"
#include <peripheral_clk_config.h>
/* #include <utils.h>*/
/* #include <hal_init.h>*/
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>
/* #include <lxsamd21dmx.h>*/

/* struct dmx_descriptor DMX;*/

void DMX_CLOCK_init(){
    /* _pm_enable_bus_clock(PM_BUS_APBC, SERCOM0);*/
    /* _gclk_enable_channel(SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC);*/
}

void DMX_PORT_init() {
	/* gpio_set_pin_function(PA04, PINMUX_PA04D_SERCOM0_PAD0);*/

	/* gpio_set_pin_function(PA05, PINMUX_PA05D_SERCOM0_PAD1);*/
}


void DMX_init(void){
    /* DMX_CLOCK_init();*/
    /* dmx_init(&DMX, SERCOM0);*/
    /* DMX_PORT_init();*/
}

void custom_system_init(void){
    /* DMX_init();*/
}
