#include "event.hpp"
template <class T>
Event<T>::Event()
{
}

template <class T>
Event<T>::Event(T* ownr)
{
	owner = ownr;
}

template <class T>
Event<T>::Event(T* ownr,bool (T::* chck) (),std::vector<Event*> chldrn)
{
	owner = ownr;
	check = chck;
	children = chldrn;
}

template <class T>
Event<T>::Event(T* ownr,bool (T::* chck) ())
{
	owner = ownr;
	check = chck;
	children = std::vector<T>();
}

template <class T>
bool
Event<T>::execute()
{
	happens = (owner->*check)();
	for (auto &&child : children)
	{
		child->execute();
	}
	return happens;
}