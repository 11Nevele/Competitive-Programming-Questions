#include <iostream>
#include <string>
class MyStack
{
private:
    int* base;
    int topIndex;
    int maxSize;
    int defaultSize;
public:
    MyStack(int size)
    {
        defaultSize = size;
        base = new int[defaultSize];
        topIndex = -1;
        maxSize = defaultSize;
    }
    MyStack()
    {
        defaultSize = 100;
        base = new int[defaultSize];
        topIndex = -1;
        maxSize = defaultSize;
    }
    bool Empty()
    {
        if (topIndex < 0)
            return true;
        else
            return false;
    }
    void Push(int value)
    {
        if (topIndex >= maxSize - 1)
        {
            Resize(maxSize + defaultSize);
        }
        topIndex++;
        base[topIndex] = value;
        
        
    }
    int Peek()
    {
        if (!Empty())
            return base[topIndex];
        else
            std::cout << "Stack is Empty, cannot peek\n";
       
    }
    void Pop()
    {
        if (!Empty())
            topIndex--;
        else
            std::cout << "Stack is Empty, cannot pop\n" ;
    }
    int Count()
    {
        return topIndex + 1;
    }
    int MaxSize()
    {
        return maxSize;
    }
    bool Resize(int newSize)
    {
        maxSize = newSize;
        int* temp = (int*)realloc(base, newSize * sizeof(int));
        if (temp == NULL)
        {
            std::cout << "Resize Fails\n";
            return false;
        }
        else
        {
            base = temp;
            return true;
        }
    }
    ~MyStack()
    {
        
        free(base);
    }
};
int main()
{
    MyStack s(5);
    while (true)
    {
        std::string op;
        int v;
        std::cin >> op;
        if (op == "push")
        {
            std::cin >> v;
            s.Push(v);
        }
        else if (op == "peek")
        {
            std::cout << s.Peek() << '\n';
        }
        else if (op == "pop")
        {
            s.Pop();
        }
        else if (op == "count")
        {
            std::cout << s.Count() << '\n';
        }
        else if (op == "maxSize")
        {
            std::cout << s.MaxSize() << '\n';
        }
        else
        {
            std::cout << "Invalid Command\n";
        }
    }
}
