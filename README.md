# CUDD_BDD_IoT

In this project we create with CUDD library (https://github.com/ivmai/cudd) BDD (Binary Decision Diagram) of MQTT, 
AMQP and CoAP protocols. These procotols have fixed headers, we constructed a BDD for every types of packets and then
a BDD with all the types of packets of every protocol. 
Then we applied reduction algorithms and tried to apply a decomposition to reduce the rules.

