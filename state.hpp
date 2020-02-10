#include <bits/stdc++.h>
#include "event.cpp"
template <class T>
class State;
template <class T>
struct Transition
{
	Transition(Event<T>* evt, State<T>* trgSt, void (T::* act)())
	{
		event = evt;
		targetState = trgSt;
		action = act;
	};
	Event<T>* event;
	State<T>* targetState;
	void (T::*action)();
};
template <class T>
class State
{
public:
	State(){};
	State(int i){id=i;};
	int id;
	std::vector<Transition<T>> transitions;
};