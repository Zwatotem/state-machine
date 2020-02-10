#include <algorithm>

template<class T>
class Event
{
public:
	Event();
	Event(T*);
	Event(T*,bool (T::*) (),std::vector<Event*>);
	Event(T*,bool (T::*) ());
	bool happens;
	T* owner;
	std::vector<Event<T>*> children;
	bool execute();
	bool (T::* check)();
};