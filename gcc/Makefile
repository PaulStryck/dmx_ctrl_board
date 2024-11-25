SUB_DIRS += \
libs/LXSAMD21DMX/src \
libs/show \
libs/graph \
libs/rng

OBJS += \
libs/LXSAMD21DMX/src/LXSAMD21DMX.o \
libs/show/show1.o \
libs/show/show2.o \
libs/show/show3.o \
libs/show/show4.o \
libs/show/dmx_manager.o \
libs/graph/graph.o \
custom_driver_init.o

OBJS_AS_ARGS += \
"libs/LXSAMD21DMX/src/LXSAMD21DMX.o" \
"libs/show/show1.o" \
"libs/show/show2.o" \
"libs/show/show3.o" \
"libs/show/show4.o" \
"libs/show/dmx_manager.o" \
"libs/graph/graph.o" \
"custom_driver_init.o"

DIR_INCLUDES += \
-I"../libs/LXSAMD21DMX/src" \
-I"../libs/show" \
-I"../libs/graph" \
-I"../libs/rng"

DEPS_AS_ARGS += \
"libs/LXSAMD21DMX/src/LXSAMD21DMX.d" \
"libs/show/show1.d" \
"libs/show/show2.d" \
"libs/show/show3.d" \
"libs/show/show4.d" \
"libs/graph/graph.d" \
"libs/show/dmx_manager.d" \
"custom_driver_init.o"

include Makefile.mk.bak
