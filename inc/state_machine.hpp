#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>


namespace sc = boost::statechart;

struct EvStartStop : sc::event< EvStartStop > {};
