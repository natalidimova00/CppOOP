#include <iostream>

template <typename T>
void input(T array[], int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> array[i];
    }
}

template <typename T>
void print(T array[], int n)
{
    std::cout << "{";
    for (size_t i = 0; i < n - 1; ++i)
    {
        std::cout << array[i] << ", ";
    }
    std::cout << array[n-1] << "}" << std::endl;
}

template <typename T>
bool ordered(T array[], int n)
{
    for (size_t i = 0; i < n - 1; ++i)
    {
        if (array[i] >= array[i+1])
        {
            return false;
        }
    }
    return true;
}

template <typename T, typename U>
bool member(T array[], int n, U x)
{
    for (size_t i = 0; i < n; ++i)
    {
        if (array[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    const int size = 3;
    int intArray[size];
    double doubleArray[size];

    std::cout << "Enter whole numbers: " << std::endl;
    input(intArray, size);

    std::cout << "Enter decimal numbers: " << std::endl;
    input(doubleArray, size);

    print(intArray, size);
    print(doubleArray, size);

    std::cout << ordered(intArray, size) << std::endl;
    std::cout << ordered(doubleArray, size) << std::endl;

    std::cout << member(intArray, size, 3) << std::endl;
    std::cout << member(intArray, size, 5) << std::endl;
    std::cout << member(intArray, size, 3.3) << std::endl;
    std::cout << member(doubleArray, size, 3) << std::endl;
    std::cout << member(doubleArray, size, 3.3) << std::endl;
}