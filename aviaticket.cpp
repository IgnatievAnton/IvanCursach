#include "aviaticket.hpp"

aviaReis::aviaReis()
{
    cout << "enter number avia reic: ";
    string temp;
    getline(cin,temp);
    getline(cin,temp);
    numberReic = checkTrueReic(temp);
    cout << "tut:" << numberReic;
    numberR();
    cout << "name avia company: ";
    getline(cin,temp);
    nameAviaCompany = temp;
    cout << "name air port out: ";
    getline(cin,temp);
    nameAirPortOut = temp;
    cout << "name air port in: ";
    getline(cin,temp);
    nameAirPortIn = temp;
    cout << "date : ";
    getline(cin,temp);
    date = temp;
    cout << "time: ";
    getline(cin,temp);
    time = temp;
    cout << "count mest: ";
    int a;
    cin >> a;
    countMest = a;
    cout << "count free mest: ";
    cin >> a;
    freeMest = a;
}

string aviaReis::reicN()
{
    return numberReic;
}

string aviaReis::nameCompany()
{
    return nameAviaCompany;
}

string aviaReis::portOut()
{
    return nameAirPortOut;
}

string aviaReis::portIn()
{
    return nameAirPortIn;
}

string aviaReis::dateOut()
{
    return date;
}

string aviaReis::timeOut()
{
    return time;
}

void aviaReis::chengeCountFreeMest()
{
    freeMest--;
}

int aviaReis::countM()
{
    return countMest;
}

int aviaReis::freeM()
{
    return freeMest;
}


int aviaReis::numberR()
{
    string str = numberReic;
    str.erase(0,4);
    int a = atoi(str.c_str());
    return a;
}

string aviaReis::checkTrueReic(string s)
{
    bool t = false;
    string temp;
    size_t sz = std::strlen(s.c_str());
    if (sz > 0 && sz > 7)
    {
        cout << "pliace enter 7 element!" << endl;
        cout << "Ex: \"AAA-NNN\"" << endl;
        cout << "AAA - only latinec simbol" <<endl;
        cout << "NNN - only number simbol" <<endl;
        cout << "enter number avia reic: ";
        cin >> temp;
        checkTrueReic(temp);
    }
    else if (sz > 0 && sz < 7)
    {
        cout << "pliace enter 7 element!" << endl;
        cout << "Ex: \"AAA-NNN\"" << endl;
        cout << "AAA - only latinec simbol" <<endl;
        cout << "NNN - only number simbol" <<endl;
        cout << "enter number avia reic: ";
        cin >> temp;
        checkTrueReic(temp);
    }
    else if ( s[3] != '-' )
    {
        cout << "you need 3 simbol /'-/'";
        cout << "pliace enter 7 element: ";
        cin >>temp;
        checkTrueReic(temp);
    }
    else if (simbolfirst(s) == false)
    {
        cout << "3 first simbol only [a;z]"<<endl;
        cout << "pliace enter 7 element: " << endl;
        cin >> temp;
        checkTrueReic(temp);
    }
    else if (simbolSecond(s) == false)
    {
       cout << "4 second simbol only [0;9]"<<endl;
       cout << "pleace enter 7 element:";
       cin >> temp;
    }

    return s;

}

void aviaReis::print()
{
    cout << "Info about reic:" << reicN() << endl;
    cout << "name Avia Company:"<< nameCompany() << endl;
    cout << "name Air Port Out:"<< portOut() << endl;
    cout << "name air port in:"<< portIn() << endl;
    cout << "departure date: "<< dateOut() << endl;
    cout << "departure time: "<< timeOut() << endl;
    cout << "count mest: "<< countM() <<endl;
    cout << "free mest: "<< freeM() <<endl;
}

bool aviaReis::simbolfirst(string s)
{
    if (((s[0] >= 'A' && s[0]<= 'Z') &&
        (s[1] >= 'A' && s[1]<= 'Z') &&
        (s[2] >= 'A' && s[2]<= 'Z'))
            ||
        ((s[0] >= 'a' && s[0]<= 'z') &&
         (s[1] >= 'a' && s[1]<= 'z') &&
         (s[2] >= 'a' && s[2]<= 'z')))
        return true;
    else
        return false;


}

bool aviaReis::simbolSecond(string s)
{
    if ((s[4] >= '0' && s[4]<= '9') &&
        (s[5] >= '0' && s[5]<= '9') &&
        (s[6] >= '0' && s[6]<= '9') )
        return true;
    else
        return false;
}


