#if defined(ARDUINO_ARCH_SAMD)
#include <Arduino.h>
#include <Scheduler.h>
#include <kasl/scheduling.h>


void
startScheduler()
{
	// The Arduino scheduler is already defined.
	return;
}


void
scheduleThread(void (*thread)())
{
	Scheduler.startLoop(thread);
}


void
runScheduler()
{
	// The Arduino scheduler already handles this.
}
#endif // defined(ATMELSAMD) && !defined(DISABLE_ARDUINO_SCHEDULER)
