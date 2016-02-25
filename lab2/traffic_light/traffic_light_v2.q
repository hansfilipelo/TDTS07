//This file was generated from (Academic) UPPAAL 4.0.13 (rev. 4577), September 2010

/*

*/
A[] not deadlock

/*

*/
A[] not ((TL0.green or TL1.green) and (TL2.green or TL3.green))

/*

*/
TL0.unhandled_vehicle1 --> TL0.green

/*

*/
TL0.unhandled_vehicle2 --> TL0.green

/*

*/
E<> TL0.green and TL1.green

/*

*/
E<> TL0.green and (not TL1.green)
