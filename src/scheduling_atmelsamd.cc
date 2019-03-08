#if defined(ARDUINO_ARCH_SAMD)
#include <Arduino.h>
#include <Scheduler.h>
#include <kasl/scheduling.h>


namespace kasl {


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


} //namespace kasl
#endif // defined(ATMELSAMD) && !defined(DISABLE_ARDUINO_SCHEDULER)
