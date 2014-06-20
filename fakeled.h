#ifndef FAKELED_H
#define FAKELED_H

#include <string>

class Fakeled
{
public:
    Fakeled();
    Fakeled(bool state, std::string color, float rate);
    ~Fakeled();
    
    int setState(bool);
    inline bool getState(bool& state) const
    { state = _state; return true; }
    
    int setRate(float);
    inline bool getRate(float& rate) const
    { rate = _rate; return true; }
    
    int setColor(std::string);
    inline bool getColor(std::string& color)
    { color = _color; return true; }
    
private:
    std::string _color;
    float _rate;
    bool _state;
};

#endif // FAKELED_H
