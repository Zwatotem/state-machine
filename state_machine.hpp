#include <algorithm>
#include <bits/stdc++.h>
#include "state.hpp"

template <class T>
class StateMachine
{
protected:
	State<T>* current;
	Event<T> rootEvent;
	void step();
};