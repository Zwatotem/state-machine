#include "object.hpp"
#include "state_machine.cpp"

class SampleObject : BaseObject, StateMachine<SampleObject>
{
public:
	float x, y;
	char c;
	SampleObject() : 
	rootEvent(
		this,
		&SampleObject::update,
		std::vector<Event<SampleObject>*>
		{
			&is_on_screen_event,
			&input_event
		}
	),
	is_on_screen_event(
		this,
		&SampleObject::is_on_screen
	),
	is_off_screen_event(
		this,
		&SampleObject::is_off_screen
	),
	input_event(
		this,
		&SampleObject::input
	),

	basicState(
		std::vector<Transition<SampleObject>>
		{
			Transition<SampleObject>(
				&rootEvent,
				std::vector<void (SampleObject::*)()>
				{
					&SampleObject::noth
				}
			),
			Transition<SampleObject>
			(
				&is_off_screen_event,
				std::vector<void (SampleObject::*)()>
				{
					&SampleObject::endgame
				}
			)
		}
	)
	{};

public:
	bool update()
	{
		return true;
	}
	bool is_on_screen()
	{
		return x > 0 && y > 0 && x < 1200 && y < 1200;
	}
	bool is_off_screen()
	{
		return !is_on_screen();
	}
	bool input()
	{
		return c!=' ';
	}
	void endgame()
	{
		exit(0);
	}
	Event<SampleObject> rootEvent;
	Event<SampleObject> is_on_screen_event;
	Event<SampleObject> is_off_screen_event;
	Event<SampleObject> input_event;
	State<SampleObject> basicState;
};