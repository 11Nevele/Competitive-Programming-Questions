#include <iostream>
class classB
{
    classA temp;
};
class classA
{
    int x, y;
    void func(classB temp);
};

void classA:: func(classB temp)
{
        //do something
        return;
}


int main()
{
    std::cout << "Hello World!\n";
}

