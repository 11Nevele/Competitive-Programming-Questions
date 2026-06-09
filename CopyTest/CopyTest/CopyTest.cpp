// CopyTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Test
{
public:
    int a;
    Test() = default;
    Test(int t): a(t)
    {
        cout << "in " << a << '\n';
    }
    Test(const Test& other) = delete;
    Test(Test&& other)noexcept :a(other.a) {
        cout << "move constructor called\n";
    }
    ~Test()
    {
        cout << "out " << a << '\n';
    }
};
class A
{
public:
    
    virtual ~A() = default;
    virtual void f1() = 0;
    virtual void f2() = 0;
};
class B :public A
{
public:
    int t1, t2;
    B(int a, int b) { ; }
    B() = default;
    virtual ~B() override { ; }
    virtual void f1() override { 
        ;
    }
    virtual void f2() override { ; }
};
int main()
{
    vector<Test> v(0);
    int* a = new int[10];
    
    for (int i = 0; i < 100; ++i)
    {
        v.emplace_back(i);
    }

    //shared_ptr<A> ptr = make_shared<B>(new B());
    cout << '\n';
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
