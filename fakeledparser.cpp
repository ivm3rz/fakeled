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
	const std::string str = buffer + 13;
	bool state = (str == "on") ? true : false;
	answer = _fakeled->setState(state) ? "OK\n" : "FAILED\n";
	
	return true;
    }
    else if(std::strcmp(buffer, "get-led-state") == 0)
    {
	bool state = false;
	answer = _fakeled->getState(state) ? "OK " : "FAILED\n";
	if(state)
	{
	    answer += "on\n";
	}
	else 
	{
	    answer += "off\n";
	}
	return true;
    }
    else if(std::strcmp(buffer, "set-led-color") == 0)
    {
	const std::string color = buffer + 13;
	answer = _fakeled->setColor(color) ? "OK\n" : "FAILED\n";
	
	return true;
    }
    else if(std::strcmp(buffer, "get-led-color") == 0)
    {
	std::string color = "";
	answer = _fakeled->getColor(color) ? "OK " : "FAILED\n";
	answer += color;
	
	return true;
    }
    else if(std::strcmp(buffer, "set-led-rate") == 0)
    {
	const std::string str = buffer + 13;
	float rate = atof(str.c_str());
	answer = _fakeled->setRate(rate) ? "OK\n" : "FAILED\n";
	return true;
    }
    else 
    {
	answer = "Wrong command format\n";
    }
    return true;
}