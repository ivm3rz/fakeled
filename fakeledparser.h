#ifndef FAKELED_PARSER_H
#define FAKELED_PARSER_H

#include <string>

class Fakeled;

class FakeledParser
{
public:
    explicit FakeledParser(Fakeled *fakeled);

    bool parse(const char *buffer, std::string &answer);
    
protected:

    /**
     * Print help text to the console.
     */
    static void PrintHelp();

    /**
     * Print message (to console?).
     */
    static void PrintMessage(const std::string &message);

private:
    Fakeled *_fakeled;
};

#endif // FAKELED_PARSER_H
