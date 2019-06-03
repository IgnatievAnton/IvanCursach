#include "ticket.hpp"

ticket::ticket(int n, int t)
{
    nr = n;
    nt = t;
}

int ticket::numberReic()
{
    return  nr;
}

int ticket::numberTiket()
{
    return nt;
}
