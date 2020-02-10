#include <algorithm>

template<class T>
class Event
{
public:
	Event();
	Event(T*);
	Event(T*,bool (T::*) (),std::vector<Event*>);
	bool happens;
	T* owner;
	std::vector<Event<T>*> m_children;
	bool execute();
	bool (T::* check)();
};