//This file was generated from (Academic) UPPAAL 4.0.13 (rev. 4577), September 2010

/*
The system can not deadlock
*/
A[] not deadlock

/*
lights on perpendicular directions must not simultaneously be green.
*/
A[] not ((TL0.green or TL1.green) and (TL2.green or TL3.green))

/*
if a vehicle arrives at the crossing (as detected by the respective sensor),
it will eventually be granted green light
*/
A<> TL0.unhandled_vehicle imply TL0.green
