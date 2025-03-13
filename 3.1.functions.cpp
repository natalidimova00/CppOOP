#include <iostream>
#include <functional>

struct MyStruct
{
    int operator()()
    {return 1;}
    double operator()(double x, double y)
    {
        return x + x * y;
    }
};

std::function<double(double, double)> apply(char c)
{
    MyStruct s;
    switch (c)
    {
        case '+' : return [](double x, double y) -> double {return x + y;}; 
        case '-' : return [](double x, double y) -> double {return x - y;};
        case '*' : return [](double x, double y) -> double {return x * y;}; 
        case '/' : return [](double x, double y) -> double {return x / y;};  
        case '$' : return s; 
        default: return nullptr;
    }
}

std::function<double(double)> makePower(unsigned n)
{
    return [n](double x) -> double
    {
        double result = 1;
        for (size_t i = 0; i < n; ++i)
        {
            result *= x;
        }
        return result;
    };
}

class Power
{
    public:
    Power(unsigned n)
    {
        p = n;
    }

    double operator()(double x)
    {
        double result = 1;
        for (size_t i = 0; i < p; ++i)
        {
            result *= x;
        }
        return result;
    }

    private:
    unsigned p;
};

class CallCounter
{
    public:
    CallCounter(){count = 0;}

    unsigned operator()()
    {
        return count++;
    }

    private:
    unsigned count;
};

int main()
{
    
}