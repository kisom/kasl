#if !defined(ARDUINO_ARCH_SAMD)
#include <Arduino.h>
#include <TaskScheduler.h>
#include <kasl/scheduling.h>


#ifndef SCHEDULER_FREQUENCY
#define SCHEDULER_FREQUENCY	50
#endif // SCHEDULER_FREQUENCY


#ifndef MAX_TASKS
#define MAX_TASKS	8
#endif


static Scheduler	scheduler;
Task			tasks[MAX_TASKS];
uint8_t			taskCount;


void
startScheduler()
{
	scheduler.init();

	for (uint8_t i = 0; i < taskCount; i++) {
		Serial.println(i);
		scheduler.addTask(tasks[i]);
		tasks[i].enable();
	}
}


void
scheduleThread(void (*thread)())
{
	if (taskCount < MAX_TASKS) {
		tasks[taskCount].setIterations(TASK_FOREVER);
		tasks[taskCount].setInterval(SCHEDULER_FREQUENCY);
		tasks[taskCount].setCallback(thread);
		taskCount++;
	}
}


void
runScheduler()
{
	scheduler.execute();
}


#endif // !defined(ATMELSAMD)
