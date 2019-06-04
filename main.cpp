#include <iostream>
#include <passenger.hpp>
#include <listhash.hpp>
#include <aviaticket.hpp>
#include <avlcp.hpp>
#include <vector>

using namespace std;

struct lisst
{
    int key = -1;
    string numberReic = 0;
    string keyNumberSell = 0;
    Passenger *name;
    lisst *prev = NULL;
    lisst *next = NULL;
};


void nextList(struct lisst* l)
{

    if (l == NULL)
        ;
    else
    {
        l->name->printA();
        nextList(l);
    }
}

string test9Element(string num)
{
    if (num.length() > 9)
    {
        cout << "Enter 9 element" << endl;
        string str;
        getline(cin,str);
        test9Element(str);
    }
    bool ok = true;
    for (int i = 0; i < 9; i++)
    {
        if (ok == false)
        {
            cout << "enter only number[0;9], 9 elements" << endl;
            string str;
            getline(cin,str);
            test9Element(str);
        }
        else
        {
            if (num[i]>= '0' || num[i] <= '9')
                ;
            else
                ok = false;
        }
    }

}

lisst* returnLast(lisst* listInfoPass)
{
    if (listInfoPass->next == NULL)
        return listInfoPass;
    else
        returnLast(listInfoPass->next);
}

lisst* init (int key,string numberReic, string keyNumberSell, Passenger* name)
{
    lisst *lst;
    lst = (struct lisst*)malloc(sizeof (struct lisst));
    lst->key = key;
    lst->numberReic = numberReic;
    lst->keyNumberSell = keyNumberSell;
    lst->name = name;
    lst->prev = NULL;
    lst->next = NULL;
    return  lst;
}

lisst* insert(lisst* lst,int key,string numberReic, string keyNumberSell, Passenger* name)
{
    lisst *temp;
    lisst *p;
    temp = (struct lisst*)malloc(sizeof (struct lisst));
    p = lst->next;
    lst->next = temp;
    temp->key = key;
    temp->numberReic = numberReic;
    temp->keyNumberSell = keyNumberSell;
    temp->name = name;
    temp->prev = lst;
    temp->next = NULL;
    if (p != NULL)
        p->prev = temp;
    return temp;
}

lisst* deliteList(lisst* lst)
{
    lisst* prev;
    lisst* next;
    prev = lst->prev;
    next = lst->next;
    if (prev != NULL)
        prev->next = lst->next;
    if (next != NULL)
        next->prev = lst->prev;
    free(lst);
    return prev;
}

lisst *delitehead(lisst* lst)
{
    lisst *temp;
    temp = lst->next;
    temp->prev = NULL;
    free (lst);
    return temp;
}

void prLs(lisst* lst)
{
    lisst *p;
    p = lst;
    do
    {
        cout << "Information:" <<endl;
        // тут сделать нужный вывод всего чего надо
        p = p->next;
    } while (p != NULL);
}

void printUf(Passenger* p, lisst*lst)
{
    if (lst != NULL)
    {
        if (lst->name == p)
        {
            cout << "===================="<<endl;
            cout <<"Number reic:" <<lst->numberReic << endl;
            cout <<"Number tiket" <<lst->keyNumberSell << endl;
            cout << "===================="<<endl;
            printUf(p,lst->next);
        }
        else
            printUf(p,lst->next);
    }
    else {
        cout << "it's all info"<<endl;
    }
}

int main()
{
    vector<Passenger> vPes;
    vector<int> reic;
    avltree avl;
    nodeptr a = NULL;
    lisst* listInfoPass = NULL;
    while (true)
    {
        cout << "enter what you want to do:" <<endl; //+
        cout << "1: registration of a new passenger" <<endl; //+
        cout << "2: removal of passenger data" <<endl;//+
        cout << "3: view all registered passengers" <<endl;//++
        cout << "4: passenger data cleaning" << endl; //+
        cout << "5: search of a passenger on the \"number of passport\"." <<endl; //-
        cout << "6: a search of the passenger for his name." <<endl; //-
        cout << "7: adding a new flight" <<endl; //+
        cout << "8: delete flight information" <<endl; //+
        cout << "9: view all flights" <<endl;//+
        cout << "10: clear data about flights" <<endl;//+
        cout << "11: flight search by \"flight number\"" <<endl;//-
        cout << "12: flight search by fragments of the name of the airport of arrival" <<endl;//-
        cout << "13: registration of ticket sale to the passenger;"<<endl; //-
        cout << "14: registration of ticket refund by the passenger" <<endl; //-
        cout << "15: clear monitor" << endl; //-
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
                cout << "no have this passanger or this list clear !" << endl;
            break;
        }
        case 3:
        {
            if (listInfoPass == NULL)
                cout << "there are no registered passengers " << endl;
            else
            {
                listInfoPass->name->printA();
                nextList(listInfoPass->next);
            }
            break;
        }
        case 4:
        {
            vPes.clear();
            cout << "list is empty" << endl;
            break;
        }
        case 5:
        {
            cout << "Enter number passport passanger:";
            string temp;
            getline(std::cin,temp);
            getline(cin,temp);
            cout << temp << endl;
            int number = -19;
            for(int i = 0 ; i < vPes.size();i++)
            {
                if( vPes.at(i).getNumberPassport() == temp )
                {
                    vPes.at(i).printA();
                }
            }
            if (number != -19 && number >= 0 )
                printUf(&vPes.at(number),listInfoPass);
            cout << "It's all passanger" <<endl;
            cout << "If you no have this passanger then he no have in data base" <<endl;
            break;
        }
        case 7:
        {
            aviaReis* reicTmp = new aviaReis;
            avl.insert(reicTmp,a,reicTmp->numberR());
            break;
        }
        case 8:
        {
            cout << "for delite reic enter next information:" <<endl;
            cout << "entrer number reic" << std::endl;
            string str;
            getline(cin,str);
            str.erase(0,4);
            int number = atoi(str.c_str());
            avl.del(number,a);
            break;
        }
        case 9:
        {
            if (a == NULL)
                cout << "no have avia reic" << endl;
            else
            {
                cout << "-------------------------" <<endl;
                avl.printAllNode(a);
            }
            break;
        }
        case 10:
        {
            avl.makeempty(a);
            cout << "all information about all reic delited" <<endl;
            break;
        }
        case 13:
        {
            cout << "Enter number passport:" << endl;
            string temp;
            getline(cin,temp);
            int passenger = -19;
            for (int i = 0; i < vPes.size();i++)
            {
                if (vPes.at(i).getNumberPassport() == temp)
                    passenger =i;
            }
            if (passenger == -19)
                cout << "No have information about this passanger please add on sistem" << endl;

            cout << "enter number reic" << endl;
            getline(cin,temp);
            temp.erase(0,4);
            int key = atoi(temp.c_str());
            aviaReis* s = avl.find(key,a);
            if (s != NULL && passenger != 19)
            {
                cout << "enter number tiket only number [0;9]:" << endl;
                getline(cin,temp);
                if(temp.length() == 9)
                {
//                    if (listInfoPass == NULL)
//                    {
//                        string one = temp.erase(1,7);
//                        listInfoPass.key = atoi(temp.c_str());
//                        listInfoPass.keyNumberSell = temp;
//                        listInfoPass.numberReic = s->reicN();
//                        listInfoPass.name = &vPes.at(passenger);
//                        listInfoPass.next = NULL;
//                        listInfoPass.prev = NULL;
//                    }
//                    else
//                    {
//                        lisst t ;
//                        string one = temp.erase(1,7);
//                        t.key = atoi(temp.c_str());
//                        t.keyNumberSell = temp;
//                        t.numberReic = s->reicN();
//                        t.name = &vPes.at(passenger);
//                        t.next = NULL;

//                        t.prev = returnLast(listInfoPass);
//                    }
                }
//                else
//                {
//                    cout<<"9 element"
//                }

            }
        }
        case 98:
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
        case 99:
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
//        case 5:
//        {

//        }


//        case 9:

//            break;
//        case 10:
//            break;
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
