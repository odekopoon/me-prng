#include <stdio.h>
#include "genrand.c"

/* initialize state to random bits  */
static unsigned int state[16];
/* init should also reset this to 0 */
static unsigned int index = 0;
/* return 32 bit random number      */
unsigned int genrand_int32(void)
{
	unsigned int a, b, c, d;
	a = state[index];
	c = state[(index+13)&15];
	b = a^c^(a<<16)^(c<<15);
	c = state[(index+9)&15];
	c ^= (c>>11);
	a = state[index] = b^c;
	d = a^((a<<5)&0xDA442D24U);
	index = (index + 15)&15;
	a = state[index];
	state[index] = a^b^d^(a<<2)^(b<<18)^(c<<28); return state[index];
}


int main(void)
{
    return 0;
}
