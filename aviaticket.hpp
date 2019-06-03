#ifndef AVIATICKET_H
#define AVIATICKET_H
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class aviaReis
{
public:
    aviaReis();
    string reicN();
    string nameCompany();
    string portOut();
    string portIn();
    string dateOut();
    string timeOut();
    void chengeCountFreeMest();
    int countM();
    int freeM();
    int numberR();
    void print();
private:
    string numberReic = "";
    string nameAviaCompany = "";
    string nameAirPortOut = "";
    string nameAirPortIn = "";
    string date = "";
    string time = "";
    int countMest = 0;
    int freeMest = 0;
    string checkTrueReic(string s);
    bool simbolfirst(string s);
    bool simbolSecond(string s);

};

#endif // AVIATICKET_H
