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
	check = chck;

}

template <class T>
bool
Event<T>::execute()
{
	happens = (owner->*check)();
	for (auto &&child : m_children)
	{
		child->execute();
	}
	return happens;
}