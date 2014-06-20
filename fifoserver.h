#ifndef FIFOSERVER_H
#define FIFOSERVER_H

class Fakeled;

const char* const fifo = "fakeled_fifo";

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
