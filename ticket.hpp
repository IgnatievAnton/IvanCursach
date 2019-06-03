#ifndef TICKET_HPP
#define TICKET_HPP


class ticket
{
public:
    ticket(int n, int t);
    int numberReic();
    int numberTiket();
private:
    int nr = 0;
    int nt = 0;
};

#endif // TICKET_HPP
