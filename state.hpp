#include "event.cpp"
template <class T>
class State;
template <class T>
struct Transition
{
	Transition(Event<T>* evt, std::vector<void (T::*)()> act, State<T>* trgSt)
	{
		event = evt;
		targetState = trgSt;
		action = act;
	};
	Transition(Event<T>* evt, std::vector<void (T::*)()> act)
	{
		event = evt;
		targetState = nullptr;
		action = act;
	};
	Event<T>* event;
	State<T>* targetState;
	std::vector<void (T::*)()> action;
};
template <class T>
class State
{
public:
	State(){};
	State(int i){id=i;};
	State(std::vector<Transition<T>> table)
	{
		transitions = table;
	}
	int id;
	std::vector<Transition<T>> transitions;
};