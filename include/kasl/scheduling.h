#ifndef __FEATHERLIB_SCHEDULING_H
#define  __FEATHERLIB_SCHEDULING_H


#include <Arduino.h>


namespace kasl {


static inline void
yieldFor(unsigned long ms)
{
	unsigned long	until = millis() + ms;
	while (millis() < until) yield();
}


// startScheduler does any initial setup.
void	startScheduler();

// startThread adds a thread to the scheduler.
void	scheduleThread(void (*thread)());

// runScheduler does a run through of the scheduler tasks.
void	runScheduler();


} // namespace kasl
#endif //  __FEATHERLIB_SCHEDULING_H
