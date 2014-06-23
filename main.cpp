#include "fakeled.h"
#include "fifoserver.h"

int main(void)
{
    Fakeled fakeled(true, "red", 3.0);
    FifoServer fifoserver(&fakeled);
    
    return fifoserver.exec();    
}