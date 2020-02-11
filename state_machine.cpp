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
			for (auto &&act : transition.action)
			{
				act();
			}
			if (transition.targetState != nullptr)
			{
				current = transition.targetState;
				break;
			}
		}
	}
}