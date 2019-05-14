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
    Passenger pas;
    table.insert(&pas);
//    int a = table.hash_function("ctest");
//    cout << a << endl;

    return 0;
}
