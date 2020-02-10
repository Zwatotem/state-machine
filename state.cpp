#include "state.hpp"

template <class T>
State<T>::State(std::vector<Transition<T>> table)
{
	transitions = table;
}