Scheduling
==========

This package supports a common interface for running tasks and background
threads. This support is included with ``kasl/scheduling.h``; three functions
are provided:

+ ``void kasl::scheduleThread`` adds a thread to be scheduled. This should be
  called before ``startScheduler``.
+ ``void kasl::startScheduler`` initialises the scheduler.
+ ``void kasl::runScheduler`` runs an interation of the scheduler. This should be
  placed in the main loop.


Platform specific notes
-----------------------

+ Atmel SAMD boards (``src/scheduling_atmelsamd.cc``):

  + ``startScheduler`` and ``runScheduler`` are nops provided to keep a
    common interface for code that needs to run on multiple architectures.
  + The standard `Arduino Scheduler <https://www.arduino.cc/en/Reference/Scheduler>`__
    is used.
  + There isn't a hard limit on the number of threads that can be run.

+ Other boards (``src/scheduling_default.cc``):

  + There is a limit to the number of tasks that can be scheduled; this is
    controlled by the ``MAX_TASKS`` define, with a default of 8. This can
    be tuned to save memory, e.g. on the AVR boards.
  + Threads are scheduled to run every ``SCHEDULER_FREQUENCY`` milliseconds;
    the default is 50.
  + These settings can be changed under ``build_flags`` in the environment. See
    ``examples/schedutest`` for an example.

