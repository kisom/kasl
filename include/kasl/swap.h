#ifndef __KASL_SWAP_H
#define __KASL_SWAP_H


#include <stdint.h>


// swap contains functions for swapping values in-place.


namespace kasl {


void	 swap_u8(uint8_t &a, uint8_t &b);
void	 swap_ul(unsigned long &a, unsigned long &b);


} // namespace kasl
#endif // __KASL_SWAP_H
