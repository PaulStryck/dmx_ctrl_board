#ifndef GRAPH_H
#define GRAPH_H

#include <inttypes.h>

// Association Grid number -> DMX appliance

// Row major representation of DMX Grid
const uint8_t graph_assoc_front[8][6] = {
    {0,  1,   7,  7,   13, 14},
    {2,  3,   8,  9,   15, 16},
    {4,  5,   10, 10,  15, 17},
    {4,  6,   11, 12,  18, 19},

    {20, 21,  26, 27,  33, 33},
    {20, 22,  28, 29,  34, 35},
    {23, 22,  38, 30,  36, 37},
    {24, 25,  31, 32,  36, 38}
};


const uint8_t graph_assoc_back[8][6] = {
    {39, 40,  46, 47,  53, 53},
    {41, 42,  48, 49,  54, 55},
    {41, 43,  50, 51,  56, 57},
    {44, 45,  50, 52,  56, 58},

    {59, 59,  65, 66,  72, 73},
    {60, 61,  67, 68,  74, 74},
    {62, 63,  69, 69,  75, 76},
    {62, 64,  70, 71,  77, 78}
};

#endif
