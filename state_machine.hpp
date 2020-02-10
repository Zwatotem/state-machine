#include "state.cpp"

template <class T>
class StateMachine
{
protected:
	State<T>* current;
	Event<T> rootEvent;
	void step();
};