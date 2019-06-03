#include <iostream>
#include <passenger.hpp>
#include <listhash.hpp>
#include <aviaticket.hpp>
#include <avlcp.hpp>
#include <vector>

using namespace std;

struct lisst
{
    int keyReic = 0;
    int keyNumberSell;
    Passenger *name;
    lisst *prev = NULL;
    lisst *next = NULL;
};



int main()
{
    setlocale (LC_ALL,"RUSSIAN");
    vector<Passenger> vPes;
    vector<int> reic;
    avltree avl;
    nodeptr a = NULL;

    while (true)
    {
        cout << "enter what you want to do:" <<endl;
        cout << "1: registration of a new passenger" <<endl;
        cout << "2: deleting passenger data" <<endl;
        cout << "3: view all registered passengers" <<endl;
        cout << "4: search of a passenger on the \"number of passport\"." <<endl;
        cout << "5: a search of the passenger for his name." <<endl;
        cout << "6: adding a new flight" <<endl;
        cout << "7: delete flight information" <<endl;
        cout << "8: view all flights" <<endl;
        cout << "9: clear data about flights" <<endl;
        cout << "10: flight search by \"flight number\"" <<endl;
        cout << "11: flight search by fragments of the name of the airport of arrival" <<endl;
        cout << "12: registration of ticket sale to the passenger;"<<endl;
        cout << "13: registration of ticket refund by the passenger" <<endl;
        cout << "14: clear monitor" << endl;
        cout << "Enter:";
        int z;
        cin >> z;
        switch (z) {
        case 1:
        {
            Passenger pas;
            vPes.push_back(pas);
            break;
        }
        case 2:
        {
            cout << "Enter next date for delited information on passanger:" <<endl;
            Passenger pas;
            bool test = false;
            for (int i = 0; i < vPes.size();i++)
            {
                if (vPes.at(i) == pas)
                {
                    vPes.erase(vPes.begin() + i);
                    test = true;
                }
            }
            if (test == false)
                cout << "" << endl;
            break;
        }
        case 3:
        {
            cout << "Enter number passport passanger:";
            string temp;
            getline(std::cin,temp);
            getline(cin,temp);
            cout << temp << endl;

            for(int i = 0 ; i < vPes.size();i++)
            {
                if( vPes.at(i).getNumberPassport() == temp )
                {
                    vPes.at(i).printA();
                }
            }
            cout << "It's all passanger" <<endl;
            break;
        }
        case 4:
        {
            cout << "Enter FIO:" << endl;
            string temp;
            getline(std::cin,temp);
            getline(cin,temp);
            for (int i = 0 ; i < vPes.size(); i++)
            {
                if (vPes.at(i).getNumberPassport() == temp)
                {
                    cout << "------------------------"<<endl;
                    cout << "Number Passport:" << vPes.at(i).getNumberPassport();
                    cout << "FIO:" << vPes.at(i).getFirstSecondName();
                    cout << "------------------------"<<endl;
                }
            }
            break;
        }
        case 5:
        {
            aviaReis* reicTmp = new aviaReis;
            avl.insert(reicTmp,a,reicTmp->numberR());
            break;
        }
        case 6:
        {
            cout << "for delite reic enter next information:" <<endl;
            aviaReis reicTmp;
            avl.del(reicTmp.numberR(),a);
            break;
        }
        case 7:
            break;
        case 8:
        {
//            if (avl == NULL)

            avl.printAllNode(a);
            break;
        }
        case 9:

            break;
        case 10:
            break;
        default:
            break;
        }

    }
    cout << "Привет World!" << endl;
//    Passenger pas("1234-123456","Vas9","dhwuad","1234,123123.213");
//    Passenger pas2("1234-123456","wgadv","dhwuad","1234,123123.213");
//    Passenger pas3("3234-123456","wgadv","dhwuad","1234,123123.213");
//    listHash a;
//    aviaReis av;
    avltree tre;

//    avltree zz;
//    zz.insert(0,test);
//    zz.
//    a.addElement(&pas);
//    a.addElement(&pas2);
//    a.print(0);
//    a.print(1);
    return 0;
}
