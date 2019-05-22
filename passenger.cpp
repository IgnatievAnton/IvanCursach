#include "Passenger.hpp"

//TODO: Проверку на дурочка доделай потом когда будет не скучно
Passenger::Passenger()
{
    std::string temp ;
//    int a;
    cout << "For create passanger:" << endl;
    cout << "Enter number pasport: ";
    getline(cin,temp);

    setNumberPassport(temp);
    cout << "Enter Place and date of passport issue:" << endl;
    getline(cin,temp);
    setpathPassport(temp);
    cout << "Enter Last Name, First Name, Patronymic: ";
    getline(cin,temp);
    setFirstSecondName(temp);
    cout << "Enter date of birth: " <<endl;
    getline(cin,temp);
    setDateB(temp);
}

Passenger::Passenger(string numPass, string pathPass, string fsn, string date)
{
    setNumberPassport(numPass);
    setpathPassport(pathPass);
    setDateB(date);
    setFirstSecondName(fsn);
}

Passenger::~Passenger()
{

}

string Passenger::getNumberPassport()
{
    return numberPassport;
}

string Passenger::getpathPassport()
{
    return pathPassport;
}

string Passenger::getFirstSecondName()
{
    return firsSecondName;
}

string Passenger::getDateB()
{
    return dateB;
}

bool Passenger::checkString(string s)
{
    if (s.empty())
        return false;
    else
        return 1;
}

void Passenger::setNumberPassport(const string str)
{
    size_t sz = std::strlen(str.c_str());
    if (sz > 11 || sz < 11)
    {
        cerr << "error 1: cant create numberPassport passanger" << endl;
        cout << "You need enter 11 simbol" << endl;
        cout << "Enter number pasport: ";
        string temp;
        getline(cin,temp);
        setNumberPassport(temp);
    }
    else
        if (str[4] == '-')
            numberPassport = str;
        else
        {
            cerr << "error 1: cant create numberPassport passanger" << endl;
            cout << "Need 11 simbol and on 4 state -!" << endl;
            cout << "Enter number pasport: ";
            string temp;
            getline(cin,temp);
            setNumberPassport(temp);
        }
}

void Passenger::setpathPassport(string str)
{
    pathPassport = str;
}

void Passenger::setFirstSecondName(string str)
{
    firsSecondName = str;
}

void Passenger::setDateB(string str)
{
    dateB = str;
}

char Passenger::character()
{
    if (getFirstSecondName() == "")
    {
        cerr << "error: cant return first character, but string is clear!";
        return NULL;
    }
//    else if
//    {

//    }

}

