// FastIOTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct IO
{
    FILE* file;
#define MAXSIZE (1 << 15)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], * p1, * p2;
    char pbuf[MAXSIZE], * pp;
#if DEBUG
#else

    IO() : p1(buf), p2(buf), pp(pbuf) {}

    ~IO() { fwrite(pbuf, 1, pp - pbuf, file); }

    void flush()
    {
        fwrite(pbuf, 1, pp - pbuf, file);
    }
#endif
    char gc() {
#if DEBUG  // 调试，可显示字符
        return getchar();
#endif
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }

    bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }

    template <class T>
    void read(T& x) {
        double tmp = 1;
        bool sign = 0;
        x = 0;
        char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign) x = -x;
    }

    void read(char* s) {
        char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
    }

    void read(char& c) {
        for (c = gc(); blank(c); c = gc())
            ;
    }

    void push(const char& c) {
        if (pp - pbuf == MAXSIZE)
            fwrite(pbuf, 1, MAXSIZE, file), pp = pbuf;
        *pp++ = c;
    }

    template <class T>
    void writeNum(T x) {
        if (x < 0) x = -x, push('-');  // 负数输出
        static T sta[35];
        T top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top) push(sta[--top] + '0');
    }

    void write(const std::string& x)
    {
        for (int i = 0; i < x.size(); ++i)
            push(x[i]);
    }
};
IO io;
int main()
{
    FILE* file = fopen("test.txt", "w");
    io.file = file;
    
    io.write("string\n");
    io.writeNum(123123);
    io.flush();
    fclose(file);
    std::cout << "test" << std::endl;
    std::cout << "Hello World!\n";
    return 0;
}