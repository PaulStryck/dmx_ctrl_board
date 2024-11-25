#ifndef INCLUDED_XOROSHIRO128P_H
#define INCLUDED_XOROSHIRO128P_H

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>

struct xorshift32_state {
    uint32_t a;
};

/* The state must be initialized to non-zero */
static inline uint32_t xorshift32(struct xorshift32_state *state)
{
    /* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
    uint32_t x = state->a;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return state->a = x;
}

static inline uint8_t random(struct xorshift32_state *state, uint8_t l, uint8_t u)
{
    uint8_t rnd_c;

    if(l >= u) return l;

    rnd_c = l + (xorshift32(state) % (u+1));

    return rnd_c;
}

#ifdef __cplusplus
}
#endif
#endif // Include guard
