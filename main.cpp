#include "fakeled.h"
#include "fifoserver.h"

int main(void)
{
    Fakeled fakeled;
    FifoServer fifoserver(&fakeled);
    
    return fifoserver.exec();    
}