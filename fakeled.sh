#!/bin/bash
echo "Running fakeled client..."
fifo=fakeled_fifo

if [[ ! -p $fifo ]]; then
    echo "Server not running"
    exit 1
fi

while true
do
    echo "Enter command: "
    read input
    if [ "$input" = 'quit' ]
    then
	exit 0
    elif [ "$input" = 'help' ]
    then 
	usage
    fi
    echo "$input" >$fifo
done

usage ()
{
    echo "Fakeled client - a tool for remote control a fakeled"
    echo 'Usage : '
    exit
}