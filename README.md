fakeled
========

fakeled is a simple tool for control "FakeLED".
fakeled is client-server software.

 BUILD
=========
To build and install fakeled software just run make.

 RUN
========
Run command ./fakeled to start server, and run ./fakeled.sh to start client.
Client sends fakeled commands, described in protocol (see ...), server handles
commands and sends answers.

Example:

Request: "get-led-state\n"
Answer:	 "OK on\n"

Request: "set-led-color yellow\n"
Answer:  "FAILED\n"

 NOTES
========
This software tested on OpenSuse 12.3 and Ubuntu 11.10.