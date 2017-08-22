#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>

namespace sc = boost::statechart;

//forward declarations
struct Active;
struct Disconnected;

struct Mask : sc::state_machine< Mask, Active > {};

struct EvStartPairing : sc::event< EvStartPairing > {};
struct EvVolumeUp : sc::event< EvVolumeUp > {};
struct EvVolumeDown : sc::event< EvVolumeDown > {};
struct EvNextTrack : sc::event< EvNextTrack > {};
struct EvPreviousTrack : sc::event< EvPreviousTrack > {};


struct Active : sc::simple_state<
  Active, Mask, Disconnected > {};

struct Disconnected : sc::simple_state< Disconnected, Active > {};


