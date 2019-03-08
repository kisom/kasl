#include <Arduino.h>
#include <kasl/scheduling.h>
#include <kasl/trigger.h>


kasl::Trigger	triggerA(200);
kasl::Trigger	triggerB(250);


void
thread_a()
{
	if (triggerA.ready()) {
		Serial.print("+");
	} else {
		Serial.print("<");
	}
}



void
thread_b()
{
	if (triggerB.ready()) {
		Serial.print("-");
	} else {
		Serial.print("!");
	}
}


void
setup()
{
	Serial.begin(9600);
	while (!Serial) ;

	kasl::scheduleThread(thread_a);
	kasl::scheduleThread(thread_b);
	kasl::startScheduler();
}


void
loop()
{
	kasl::runScheduler();
	Serial.print(".");
}
