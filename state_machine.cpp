#include "state_machine.hpp"

template <class T>
void
StateMachine<T>::step()
{
	rootEvent.execute();
	for (auto &&transition : current->transitions)
	{
		if (transition.event->happens)
		{
			if (transition.targetState == nullptr)
			{
				transition.action;
			}
			else
			{
				transition.action;
				current = transition.targetState;
				break;
			}
		}
	}
}