//This file was generated from (Academic) UPPAAL 4.0.13 (rev. 4577), September 2010

/*

*/
A[] not deadlock

/*

*/
E<> Receiver.recv0

/*

*/

Sender.wait0 --> (Sender.send0 or Sender.send1)

/*

*/
Sender.send0 --> Link.m0

/*

*/
Link.m0 --> (Link.m0a or Link.wait)

/*

*/
Link.m0a -->Receiver.recv0