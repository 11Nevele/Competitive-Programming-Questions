#include <iostream>
class MyStack
{
private:
    int* base;
    int topIndex;
    int maxSize;
    int defaultSize;
public:
    MyStack()
    {
        defaultSize = 10;
        base = new int[defaultSize];
        maxSize = defaultSize;
        topIndex = -1;
    }
    MyStack(int size)
    {
        if (size <= 0)
        {
            defaultSize = 10;
        }
        else
            defaultSize = size;
        base = new int[defaultSize];
        maxSize = defaultSize;
        topIndex = -1;
    }
    //push
    void Push(int value)
    {
        if (topIndex >= maxSize - 1)
        {
            Resize(maxSize + defaultSize);
        }
        topIndex++;
        base[topIndex] = value;
    }
    //peek
    int Peek()
    {
        if (Empty())
        {
            std::cout << "Cannot Peek, stack is empty!\n";
            return -1;
        }
        return base[topIndex];
    }
    //pop
    void Pop()
    {
        if (Empty())
        {
            std::cout << "Cannot Pop, stack is empty!\n";
            return;
        }
        topIndex--;
    }
    //count
    int Count()
    {
        return topIndex + 1;
    }
    //empty
    bool Empty()
    {
        if (topIndex < 0)
            return true;
        else
            return false;
    }
    //resize
    void Resize(int newSize)
    {
        int* temp = (int*)realloc(base, newSize * sizeof(int));
        maxSize = newSize;
        if (temp == NULL)
        {
            std::cout << "Resize Fail!\n";
        }
        else
        {
            base = temp;
        }
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
        else
        {
            std::cout << "Invalid Command\n";
        }
    }
}
