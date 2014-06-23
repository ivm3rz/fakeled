#include "fakeledparser.h"
#include "fakeled.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib> // EXIT_FAILURE


FakeledParser::FakeledParser(Fakeled *fakeled)
    : _fakeled(fakeled)
{
}

void FakeledParser::PrintMessage(const std::string &message)
{
    std::cout << message << std::endl;
}

bool FakeledParser::parse(const char* buffer, std::string &answer)
{
    if(std::strcmp(buffer, "set-led-state") == 0)
    {
	const char *str = buffer + 14;
	bool state = (std::strcmp(str, "on") == 0) ? true : false;
	if(_fakeled->setState(state))
	{
	    answer = "OK\n";
	}
	else
	{
	    answer = "FAILED\n";
	}
	return true;
    }
    else if(std::strcmp(buffer, "get-led-state\n") == 0)
    {
	bool state = false;
	bool ret = _fakeled->getState(state);
	answer = ret ? "OK " : "FAILED\n";
	if(ret)
	{
	    if(state)
	    {
		answer += "on\n";
	    }
	    else 
	    {
		answer += "off\n";
	    }
	}
	return true;
    }
    else if(std::strcmp(buffer, "set-led-color") == 0)
    {
	const std::string color = buffer + 13;
	answer = _fakeled->setColor(color) ? "OK\n" : "FAILED\n";
	
	return true;
    }
    else if(std::strcmp(buffer, "get-led-color\n") == 0)
    {
	std::string color = "";
	bool ret = _fakeled->getColor(color);
	answer = ret ? "OK " : "FAILED\n";
	if(ret)
	{
	    answer += color;
	    answer += '\n';
	}
	return true;
    }
    else if(std::strcmp(buffer, "set-led-rate") == 0)
    {
	const std::string str = buffer + 13;
	float rate = atof(str.c_str());
	answer = _fakeled->setRate(rate) ? "OK\n" : "FAILED\n";
	return true;
    }
    else if(std::strcmp(buffer, "get-led-rate\n") == 0)
    {
	float rate = 0.0;
	bool ret = _fakeled->getRate(rate);
	std::ostringstream oss;
	oss << rate;
	answer = ret ? "OK " : "FAILED\n";
	if(ret)
	{
	    answer += oss.str();
	    answer += '\n';
	}
	return true;
    }
    else 
    {
	answer = "Wrong command format\n";
	return false;
    }
    return true;
}