#include "fakeled.h"

Fakeled::Fakeled()
{
    _state = false;
    
}

Fakeled::Fakeled(bool state, std::string color, float rate)
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

int Fakeled::setColor(std::string color)
{
    if(color != "green" || color != "blue" || color != "red")
    {
	return -1;
    }
    else
    {
	_color = color;
	return 0;
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