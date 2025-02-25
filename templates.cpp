#include <iostream>
#include <utility>

template <typename T>
using Operator = T(*)(T);

template <typename T>
using Combinator = T(*)(T, T);

template <typename T>
T fold(const T a[], unsigned n, T null_val, Combinator<T> op)
{
    T accum = null_val;
    for (size_t i = 0; i < n; ++i)
    {
        accum = op(a[i], accum);
    }
    return accum;
}

template <typename T>
T id(T x)
{
    return x;
}

template <typename T>
T sq(T x)
{
    return x * x;
}

template <typename T>
T cube(T x)
{
    return x * x * x;
}

template <typename T>
T plus1(T x)
{
    return x + 1;
}

template <typename T>
using Comparator = bool(*)(T, T);

template <typename T>
unsigned findExtremum(const T a[], unsigned n, Comparator<T> pComp)
{
    unsigned extr = 0;
    for (size_t i = 1; i < n; ++i)
    {
        if (pComp(a[i], a[extr]))
        {
            extr = i;
        }
        
    }
    return extr;
}

template <typename T>
bool compLt(T x, T y)
{
    return x < y;
}

template <typename T>
bool compGt(T x, T y)
{
    return x > y;
}

int countTwos(int x)
{
    int twos = 0;

    while (x > 0)
    {
        twos += (x % 10 == 2);
        x /= 10;
    }
    
    return twos;
}

bool compNumberOfTwos(int x, int y)
{
    return (countTwos(x) > countTwos(y));
}

void sort(int a[], unsigned n, Comparator<int> pComp)
{
    for (size_t i = 0; i < n - 1; ++i)
    {
        unsigned extrRight = findExtremum<int>(a + i, n - i, pComp);
        std::swap(a[i], a[i+extrRight]);
    }
}

template <typename T>
void printArray(const T a[], unsigned n)
{
    std::cout << "{";
    for (size_t i = 0; i < n - 1; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << a[n-1] << "}" << std::endl;
}

template <typename T>
void map(T a[], unsigned n, Operator<T> op)
{
    for (size_t i = 0; i < n; ++i)
    {
        a[i] = op(a[i]);
    }
}

template <typename In, typename Out>
void map(In in[], Out out[], unsigned n, Out(*op)(In))
{
    for (size_t i = 0; i < n; ++i)
    {
        out[i] = op(in[i]);
    }
}

bool even(int x)
{
    return x % 2 == 0;
}

template <typename T>
T plus(T x, T y)
{
    return x + y;
}

template <typename T>
T multiply(T x, T y)
{
    return x * y;
}

int main()
{
    int intArr[] = {1, 2, 5, 7, 6, 152};
    double doubleArr[] = {1, 2, 5};
    char charArr[] = {'1', '2', '5'};

    printArray(intArr, 6);
    printArray(doubleArr, 3);
    printArray(charArr, 3);

    std::cout << fold(intArr, 6, 0, plus) << std::endl;
    std::cout << fold(intArr, 6, 1, multiply) << std::endl;

    std::cout << findExtremum(intArr, 6, compGt) << std::endl;
    std::cout << findExtremum(intArr, 6, compLt) << std::endl;

    int intArr2[] = {1, 2, 55, 7, 621, 152, 6, 2242, 12};

    std::cout << findExtremum(intArr2, 9, compNumberOfTwos) << std::endl;

    std::cout << findExtremum(intArr2, 9, compLt) << std::endl;
    std::cout << findExtremum(intArr2, 9, compGt) << std::endl;

    printArray(intArr2, 9);
    sort(intArr2, 9, compGt);
    printArray(intArr2, 9);
    sort(intArr2, 9, compLt);
    printArray(intArr2, 9);
    sort(intArr2, 9, compNumberOfTwos);
    printArray(intArr2, 9);

    map(intArr2, 9, plus1);
    printArray(intArr2, 9);

    bool tests[9] = {false};
    map(intArr2, tests, 9, even);
    printArray(tests, 9);
}