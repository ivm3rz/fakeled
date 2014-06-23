// named pipe server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <linux/stat.h>
#include "fifoserver.h"
#include "fakeled.h"
#include "fakeledparser.h"

FifoServer::FifoServer(Fakeled *fakeled)
{
    if(fakeled != NULL)
    {
	_fakeled = fakeled;

    }
    /* Create the FIFO if it does not exist */
    mkfifo(fifo_server, 0777);
}

FifoServer::~FifoServer()
{
    remove(fifo_server); // delete the fifo file
}

int FifoServer::exec()
{
    const size_t size = 32;
    char buf[size];
    
    fprintf(stderr, "Fifo server running...\n");

    // try to open fifo file. it may already exist from
    // an earlier aborted execution
    int server_fifo_fd = open(fifo_server, O_RDONLY);
 
    // if the fopen failed, the fifo file does not exist
    if(-1 == server_fifo_fd)
    {
	fprintf(stderr, "Open server fifo failed\n");
	return -1;
    }
    printf("Receiving...\n");
    
    FakeledParser parser(_fakeled);
    std::string answer;
 
    while(true)
    {
	memset(buf, 0, sizeof(buf));
	
	if(read(server_fifo_fd, buf, sizeof(buf)) > 0)
	{
	    answer.clear();
	    
	    if(parser.parse(buf, answer))
	    {
		printf("Request: %sAnswer:%s\n", buf, answer.c_str());
	
		int client_fifo_fd = open(fifo_client, O_WRONLY);
		if(client_fifo_fd != -1)
		{
		    write(client_fifo_fd, answer.c_str(), answer.length() + 1);
		    close(client_fifo_fd);
		}
	    }
	    else
	    {
		printf("%s", answer.c_str());
	    }
	    fflush(stdout);
	}
    }

    close(server_fifo_fd); // close the fifo file
    fprintf(stderr, "Fifo server terminating.\n");
    return 0;
}