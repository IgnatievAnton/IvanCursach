#ifndef PASSENGER_HPP
#define PASSENGER_HPP
#include <string>
#include <iostream>

using namespace std;

class Passenger
{
public:
    Passenger();
    Passenger(string numPass,string pathPass,string fsn,string date);
    ~Passenger();
    string getNumberPassport();
    string getpathPassport();
    string getFirstSecondName();
    string getDateB();
    void setNumberPassport(std::string str);
    void setpathPassport(std::string str);
    void setFirstSecondName(std::string str);
    void setDateB(std::string str);
    char character();
private:
    string numberPassport = "";
    string pathPassport = "";
    string firsSecondName = "";
    string dateB = "";
    bool checkString(std::string s);

//    void set(std::string srt);
};

#endif // PASSENGER_HPP
