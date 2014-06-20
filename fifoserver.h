#ifndef FIFOSERVER_H
#define FIFOSERVER_H

class Fakeled;

const char* const fifo_server = "fakeled_fifoserver";
const char* const fifo_client = "fakeled_fifoclient";

struct FifoData
{
    pid_t client_pid;
    char data[16];
};

class FifoServer
{
public:
    explicit FifoServer(Fakeled *fakeled);
    ~FifoServer();
    
    int exec(void);
    
private:
    Fakeled *_fakeled;
};

#endif // FIFOSERVER_H
