#include <stdio.h>
#include <string.h>
#include "genrand.c"

#define KEY_LENGTH 16
/* initialize state to random bits  */
static unsigned int state[KEY_LENGTH];

/* init should also reset this to 0 */
static unsigned int idx = 0;

void init_by_array(unsigned int init_key[], int key_length)
{
	idx = 0;
	memcpy(state, init_key, sizeof(int) * key_length);
}

/* return 32 bit random number      */
unsigned int genrand_int32(void)
{
	unsigned int a, b, c, d;
	a = state[idx];
	c = state[(idx+13)&15];
	b = a^c^(a<<16)^(c<<15);
	c = state[(idx+9)&15];
	c ^= (c>>11);
	a = state[idx] = b^c;
	d = a^((a<<5)&0xDA442D24U);
	idx = (idx + 15)&15;
	a = state[idx];
	state[idx] = a^b^d^(a<<2)^(b<<18)^(c<<28); return state[idx];
}
