#include <kasl/swap.h>
#include <stdint.h>


namespace kasl {


void
swap_u8(uint8_t &a, uint8_t &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}


void
swap_ul(unsigned long &a, unsigned long &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}


} // kasl
