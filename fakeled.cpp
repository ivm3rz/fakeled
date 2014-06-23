#include "fakeled.h"
#include <stdlib.h>
#include <cstring>

Fakeled::Fakeled()
{
    _state = false;
    
}

Fakeled::Fakeled(bool state, const std::string &color, float rate)
{
    setState(state);
    setColor(color);
    setRate(rate);
}

Fakeled::~Fakeled()
{
    
}

int Fakeled::setState(bool state)
{
    _state = state;
    return 0;
}

int Fakeled::setColor(const std::string &color)
{
    if((std::strcmp(color.c_str(), "green") == 0) ||
	(std::strcmp(color.c_str(), "blue") == 0) ||
	(std::strcmp(color.c_str(), "red") == 0))
    {
	_color = color;
	return 0;
    }
    else
    {
	
	return -1;
    }
}

int Fakeled::setRate(float rate)
{
    if(rate < 0.0 || rate > 5.0)
    {
	return -1;
    }
    else
    {
	_rate = rate;
	return 0;
    }
}