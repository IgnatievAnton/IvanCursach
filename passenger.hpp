#ifndef PASSENGER_HPP
#define PASSENGER_HPP
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Passenger
{
public:
    Passenger();
    Passenger(string numPass,string pathPass,string fsn,string date);
    ~Passenger();
    string getNumberPassport();
    string getpathPassport();
    void printA();
    string getFirstSecondName();
    string getDateB();
    void setNumberPassport(std::string str);
    void setpathPassport(std::string str);
    void setFirstSecondName(std::string str);
    void setDateB(std::string str);
    char character();
    bool operator==(const Passenger& rhs) const {
        return
           numberPassport == rhs.numberPassport
           && pathPassport == rhs.pathPassport
           && firsSecondName == rhs.firsSecondName
           && dateB == rhs.dateB
        ;
    }
private:
    string numberPassport = "";
    string pathPassport = "";
    string firsSecondName = "";
    string dateB = "";
    bool checkString(std::string s);

//    void set(std::string srt);
};

#endif // PASSENGER_HPP
