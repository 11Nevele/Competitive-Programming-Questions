#include <iostream>
using namespace std;
struct Event;
class c1;
class c2;
class c3;
class System;
template<class T>
class AllowedToken;

struct Event
{
    int a;
};
template<class T>
struct Event1
{
    int a;
};



template<class T>
class AllowedToken
{
private:
    AllowedToken() = default;
};

template<>
class AllowedToken<Event>
{
    friend c1; friend c2;
};

template<class T>
class AllowedToken<Event1<T>>
{
    friend c1; friend c2;
};



class System
{
public:
    template<class T>
    static void Invoke(const T& event, AllowedToken<T> token)
    {
        cout << event.a << endl;
    }
};
class c1
{
    void use()
    {
    }
};
class c2
{
    static void use()
    {
        AllowedToken<Event> t();
        AllowedToken<Event1<int>> t1();
    }
};
class c3
{
    void use()
    {

    }
};
int main()
{
    
}
