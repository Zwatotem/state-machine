#include "object.hpp"
#include "state_machine.cpp"

class SampleObject : BaseObject, StateMachine<SampleObject>
{
public:
	float x, y;
	char c;
	SampleObject()
	{
		//Events
		//rootEvent = Event<SampleObject>();
		rootEvent.owner = this;
		rootEvent.check = &SampleObject::update;
		std::vector<Event<SampleObject> *> temp
		{
			&is_on_screen_event,
			&input_event
		};
		rootEvent.m_children = temp;

		is_on_screen_event.owner = this;
		is_on_screen_event.check = &SampleObject::is_on_screen;


		input_event.owner = this;
		input_event.check = &SampleObject::input;
		//States
		basicState.transitions.push_back(Transition<SampleObject>(
			&rootEvent,
			&basicState,
			&SampleObject::noth
		)
		);
	};

public:
	bool update()
	{
		return true;
	}
	bool is_on_screen()
	{
		return x > 0 && y > 0 && x < 1200 && y < 1200;
	}
	bool input()
	{
		return c!=' ';
	}
	Event<SampleObject> rootEvent;
	Event<SampleObject> is_on_screen_event;
	Event<SampleObject> input_event;
	State<SampleObject> basicState;
};