// named pipe server

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

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
    umask(0);
    mknod(fifo, S_IFIFO|0666, 0);
}

FifoServer::~FifoServer()
{
    remove(fifo); // delete the fifo file
}

int FifoServer::exec()
{
    FILE *fp;
    const size_t size = 16;
    char buf[size];

    fprintf(stderr, "Fifo server running...\n");

    // try to open my fifo file. it may already exist from
    // an earlier aborted execution
    fp = fopen(fifo, "r");

    // if the fopen failed, the fifo file does not exist
    if(NULL == fp)
    {
	fprintf(stderr, "fopen() failed\n");	
    }
    printf("Receiving...\n");
    
    FakeledParser parser(_fakeled);
    std::string answer;
    while(true)
    {
	fgets(buf, size, fp);
	parser.parse(buf, answer);
	printf("%s", buf);
//	fread(fifo, answer.c_str());
	fflush(stdout);
    }

    fclose(fp); // close the fifo file
    fprintf(stderr, "Fifo server terminating.\n");
    return 0;
}