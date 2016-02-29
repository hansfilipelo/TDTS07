//This file was generated from (Academic) UPPAAL 4.0.13 (rev. 4577), September 2010

/*
The system can not deadlock.
*/
A[] not deadlock

/*
Messages sent by the sender are eventually received by the receiver \
(sender is in wait0 after it has sent an message and receiver reaches recv0 when it has received the message)
*/
A<> Sender.wait0 imply Receiver.recv0

/*
The receiver might send an acknowledgment \
(the sender can't be in wait1 if it has never received an ack)
*/
E<> Sender.wait1

/*
The channel is lossy
*/
E<> (lost_message == true and lost_ack == true)
