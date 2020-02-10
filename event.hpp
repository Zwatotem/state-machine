#include <bits/stdc++.h>

template<class T>
class Event
{
public:
	Event();
	Event(T*);
	Event(T*,bool (T::*) (), std::vector<Event<T>*>);
	// Event(T*,bool (T::*) (), std::vector<Event<T>*, std::allocator<Event<T>>>);
	Event(T*,bool (T::*) ());
	bool happens;
	T* owner;
	std::vector<Event<T>*> children;
	bool execute();
	bool (T::* check)();
};