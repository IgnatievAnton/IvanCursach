#include <iostream>
#include <passenger.hpp>
#include <hashtableopen.hpp>

using namespace std;

int main()
{
//    passenger a;
//    a.setNumberPassport("1234-567891");
    cout << "Hello World!" << endl;
    hashTableOpen table;
//    Passenger pas();
    Passenger pas("1234-123456","wgadv","dhwuad","1234,123123.213");
    Passenger pas2("1234-123456","wgadv","dhwuad","1234,123123.213");
    Passenger pas3("3234-123456","wgadv","dhwuad","1234,123123.213");
    table.insert(&pas);
    table.insert(&pas2);
//    table.insert(&pas2);
//    table.insert(&pas3);
    table.printHashNode();
//    table.hash_function("9",0);
    //table.insert(&pas);
//    int a = table.hash_function("ctest");
//    cout << a << endl;

    return 0;
}
