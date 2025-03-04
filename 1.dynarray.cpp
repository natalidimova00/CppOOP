#include <iostream>

class DynArray
{
    public:
    int *first;
    unsigned size;

    void print()
    {
        std::cout << "{";
        for (size_t i = 0; i < size - 1; ++i)
        {
           std::cout << first[i] <<  " ";
        }
        std::cout << first[size - 1];
        std::cout << "}, length: " << size << std::endl;
    }

    void operator+=(int x)
    {
        int *newBuffer = new int[size + 1];

        for (size_t i = 0; i < size; ++i)
        {
            newBuffer[i] = first[i];
        }
        
        newBuffer[size] = x;

        ++size;

        delete first;
        first = newBuffer;
    }

    DynArray operator+(DynArray b)
    {
        DynArray result;
        result.first = new int [size + b.size];
        result.size = size + b.size;

        for (size_t i = 0; i < size; ++i)
        {
            result.first[i] = first[i];
        }
        
        for (size_t i = size; i < size + b.size; ++i)
        {
            result.first[i] = b.first[i - size];
        }
        
        return result;
    }

    bool member(int x)
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (first[i] == x)
            {
                return true;
            }
        }
        return false;
    }
};

bool eq(DynArray a, DynArray b)
{
    if (a.size != b.size)
    {
        return false;
    }
    
    for (size_t i = 0; i < a.size; ++i)
    {
        if (a.first[i] != b.first[i])
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    DynArray array = {nullptr, 0},
             array2 = {nullptr, 0};

    array += 10;
    array += 20;
    array += 30;
    array += 40;
    array += 50;
    array += 60;

    array2 += 30;
    array2 += 60;
    array2 += 90;

    array.print();
    array2.print();

    array.operator+(array2).print();

    (array + array2).print();

    array.print();
    array2.print();

    array = array + array2;

    if (array.member(90))
    {
        std::cout << "90 is member!" << std::endl;
    }

    array.print();
}