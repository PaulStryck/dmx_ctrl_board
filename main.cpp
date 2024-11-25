#include <atmel_start.h>
#include "LXSAMD21DMX.h"
#include "dmx_manager.h"
#include "show.h"
#include "show1.h"
#include "show2.h"
#include "show3.h"
#include "show4.h"
#include "rng.h"
#include "graph.h"


struct xorshift32_state rng_state = {1234};

const show_light_conf lights[39] = {
    // DOOR 1
    {.states=(const show_light_state[]){{.state=false, .nticks=100} },  .n=1},
    {.states=(const show_light_state[]){{.state=false, .nticks=200}, {.state=true,  .nticks=10}  },  .n=2},
    {.states=(const show_light_state[]){{.state=true,  .nticks=20},  {.state=false, .nticks=60}  },  .n=2},
    {.states=(const show_light_state[]){{.state=false, .nticks=200}, {.state=true,  .nticks=10}  },  .n=2},
    {.states=(const show_light_state[]){{.state=true,  .nticks=20},  {.state=false, .nticks=150} },  .n=2},
    {.states=(const show_light_state[]){{.state=false, .nticks=60}, {.state=true,  .nticks=10}  },  .n=2},
    {.states=(const show_light_state[]){{.state=false, .nticks=60}, {.state=true,  .nticks=20}  },  .n=2},

    // DOOR 2
    {.states=(const show_light_state[]){{.state=false, .nticks=120}, {.state=true,  .nticks=10}, {.state=false, .nticks=250}, {.state=true,  .nticks=10} },  .n=4},
    {.states=(const show_light_state[]){{.state=false, .nticks=100}, {.state=true,  .nticks=20}, {.state=false, .nticks=300}, {.state=true,  .nticks=5}  },  .n=4},
    {.states=(const show_light_state[]){{.state=false, .nticks=100}, {.state=true,  .nticks=20}  },  .n=2},
    {.states=(const show_light_state[]){{.state=true,  .nticks=30},  {.state=false, .nticks=3},  {.state=true, .nticks=30},   {.state=false, .nticks=300}},  .n=4},
    {.states=(const show_light_state[]){{.state=false, .nticks=100}, {.state=true,  .nticks=20}  },  .n=2},
    {.states=(const show_light_state[]){{.state=false, .nticks=100}, {.state=true,  .nticks=20}, {.state=false, .nticks=10}, {.state=true,  .nticks=10}  },  .n=4},

    // Door 3
    {.states=(const show_light_state[]){{.state=false, .nticks=30}, {.state=true,  .nticks=3}, {.state=false, .nticks=3}, {.state=true,  .nticks=3}  },  .n=4},
    {.states=(const show_light_state[]){{.state=true,  .nticks=5},  {.state=false, .nticks=50},  {.state=true, .nticks=10},   {.state=false, .nticks=10},  {.state=true, .nticks=10},   {.state=false, .nticks=60}},  .n=6},
    {.states=(const show_light_state[]){{.state=false, .nticks=100}}, 1},
    {.states=(const show_light_state[]){{.state=false, .nticks=5}, {.state=true,  .nticks=32}, {.state=false, .nticks=10}, {.state=true,  .nticks=10}  },  .n=4},
    {.states=(const show_light_state[]){{.state=true,  .nticks=5},  {.state=false, .nticks=50},  {.state=true, .nticks=10},   {.state=false, .nticks=10},  {.state=true, .nticks=10},   {.state=false, .nticks=60}},  .n=6},
    {.states=(const show_light_state[]){{.state=false, .nticks=100}}, 1},
    {.states=(const show_light_state[]){{.state=false, .nticks=30}, {.state=true,  .nticks=3}, {.state=false, .nticks=3}, {.state=true,  .nticks=3}  },  .n=4},

    // Door 4
    {.states=(const show_light_state[]){{true , 50}, {false, 100}}, .n=2},
    {.states=(const show_light_state[]){{true , 40}, {false, 30}},  .n=2},
    {.states=(const show_light_state[]){{false, 55}, {true,  10}, {false, 40}, {true, 10}}, .n=4},
    {.states=(const show_light_state[]){{false, 55}, {true,  10}, {false, 40}, {true, 10}}, .n=4},
    {.states=(const show_light_state[]){{true,  10}, {false, 100}}, .n=2},
    {.states=(const show_light_state[]){{false, 20}, {true,  20}},  .n=2},

    // Door 5
    {.states=(const show_light_state[]){{false, 100}, {true,  20}}, .n=2},
    {.states=(const show_light_state[]){{false, 100}, {true,  20},  {false, 10},  {true,  10 }}, .n=4},
    {.states=(const show_light_state[]){{false, 100}, {true,  20},  {false, 10},  {true,  10 }}, .n=4},
    {.states=(const show_light_state[]){{true,  15},  {false, 20},  {true,  100}, {false, 120}}, .n=4},
    {.states=(const show_light_state[]){{false, 15},  {true,  100}, {false, 100}, {true,  30 }}, .n=4},
    {.states=(const show_light_state[]){{true,  15},  {false, 60},  {true,  10},  {false, 40 }}, .n=4},
    {.states=(const show_light_state[]){{false, 200}, {true,  20}}, .n=2},

    // Door 6
    {.states=(const show_light_state[]){{false, 100}}, .n=1},
    {.states=(const show_light_state[]){{true,  15}, {false, 30}, {true, 20},  {false, 70}}, .n=4},
    {.states=(const show_light_state[]){{false, 100}}, .n=1},
    {.states=(const show_light_state[]){{false, 150}, {true, 40},  {false, 20}, {true, 10} }, .n=4},
    {.states=(const show_light_state[]){{false, 100}}, .n=1},
    {.states=(const show_light_state[]){{true,  5},  {false, 50}, {true, 5},   {false, 5}, {true, 10}, {false, 50}}, .n=6}
};

const uint8_t (*graph_schrank[2])[8][6] = {&graph_assoc_front, &graph_assoc_back};

// ***************** DMX Driver on SERCOM0  ***************
LXSAMD21DMX SAMD21DMX(SERCOM0, DMX_USART_CONF_SAMPLE);

DMX_Manager dmx_mgr(&SAMD21DMX);

Show1 show4(lights, &dmx_mgr);
Show2 show1(&dmx_mgr);
Show3 show2(&dmx_mgr);
Show4 show3(graph_schrank, &dmx_mgr);

Show* current = &show1;


void SERCOM0_Handler()
{
    SAMD21DMX.IrqHandler();
}

void vTaskSetter( void * pvParameters )
{
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 20 / portTICK_PERIOD_MS;

    // Initialise the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();

    for( ;; )
    {
        // Wait for the next cycle.
        vTaskDelayUntil( &xLastWakeTime, xFrequency );

        dmx_mgr.tick();
    }
}

void vTaskShow( void * pvParameters)
{
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 100 / portTICK_PERIOD_MS;

    xLastWakeTime = xTaskGetTickCount();

    for( ;; )
    {
        vTaskDelayUntil( &xLastWakeTime, xFrequency );

        current->tick();
    }
}


// **************************** Lightshow select button interrupts  ***************
static void button_BTN_1_pressed(void)
{
    UBaseType_t uxSavedInterruptStatus;
    uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();

    gpio_set_pin_level(LED_1, true);
    gpio_set_pin_level(LED_2, false);
    gpio_set_pin_level(LED_3, false);
    gpio_set_pin_level(LED_4, false);

    show1.reset();

    current = &show1;

    taskEXIT_CRITICAL_FROM_ISR( uxSavedInterruptStatus );
}

static void button_BTN_2_pressed(void)
{
    UBaseType_t uxSavedInterruptStatus;
    uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();

    gpio_set_pin_level(LED_1, false);
    gpio_set_pin_level(LED_2, true);
    gpio_set_pin_level(LED_3, false);
    gpio_set_pin_level(LED_4, false);

    show2.reset();

    current = &show2;
    taskEXIT_CRITICAL_FROM_ISR( uxSavedInterruptStatus );
}

static void button_BTN_3_pressed(void)
{
    UBaseType_t uxSavedInterruptStatus;
    uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();

    gpio_set_pin_level(LED_1, false);
    gpio_set_pin_level(LED_2, false);
    gpio_set_pin_level(LED_3, true);
    gpio_set_pin_level(LED_4, false);

    show3.reset();

    current = &show3;
    taskEXIT_CRITICAL_FROM_ISR( uxSavedInterruptStatus );
}

static void button_BTN_4_pressed(void)
{
    UBaseType_t uxSavedInterruptStatus;
    uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();

    gpio_set_pin_level(LED_1, false);
    gpio_set_pin_level(LED_2, false);
    gpio_set_pin_level(LED_3, false);
    gpio_set_pin_level(LED_4, true);

    show4.reset();

    current = &show4;
    taskEXIT_CRITICAL_FROM_ISR( uxSavedInterruptStatus );
}




// ********************** Lightshow & DMX dimmer   ***************
// DMX_Manager dmx_mgr(&SAMD21DMX);
// Show show(lightshow_1, 9, &dmx_mgr);

int main(void)
{
    /* Initializes MCU, drivers and middleware */
    atmel_start_init();

    ext_irq_register(PIN_PA17, button_BTN_1_pressed);
    ext_irq_register(PIN_PA15, button_BTN_2_pressed);
    ext_irq_register(PIN_PA11, button_BTN_3_pressed);
    ext_irq_register(PIN_PA09, button_BTN_4_pressed);

    gpio_set_pin_level(LED_1, true);
    gpio_set_pin_level(LED_2, false);
    gpio_set_pin_level(LED_3, false);
    gpio_set_pin_level(LED_4, false);


    show1.reset();
    show2.reset();
    show3.reset();
    show4.reset();
    dmx_mgr.reset();

    SAMD21DMX.startOutput();

    xTaskCreate( vTaskSetter, "Dimmer",   128, NULL, 2, NULL);
    xTaskCreate( vTaskShow,   "ShowTick", 64, NULL, 1, NULL);

    vTaskStartScheduler();

    /* Replace with your application code */
    for(;;);
}
