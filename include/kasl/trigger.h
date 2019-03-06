#ifndef __KASL_TRIGGER_H
#define __KASL_TRIGGER_H
namespace kasl {


// A Trigger ensures that some time delta has passed before
// a task is fired.
class Trigger {
public:
	Trigger(unsigned long delta) : next(0), delta(delta) {}
	Trigger(unsigned long delta, bool skipFirst);
	bool	ready();
	bool	ready(unsigned long now);
	void	reset();
	void	reset(unsigned long now);

private:
	unsigned long	next;
	unsigned long	delta;
};


} // namespace kasl
#endif // __KASL_TRIGGER_H
