#!/bin/bash
echo "Running fakeled client..."
fifo_server=fakeled_fifoserver
fifo_client=fakeled_fifoclient

if [[ ! -p $fifo_server ]]; then
    echo "Server not running"
    exit 1
fi

if [[ ! -p $fifo_client ]]; then
    mkfifo $fifo_client
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
    
    echo "$input" >$fifo_server
    
    cat $fifo_client
 #   if read output <$fifo_client; then
 #       echo $output
 #   fi
    
done

rm $fifo_client

usage ()
{
    echo "Fakeled client - a tool for remote control a fakeled"
    echo 'Usage : '
    exit
}