#include <iostream>

unsigned charCount(char c, const char* str)
{
    if (str == nullptr)
    {
        return 0;
    }
    
    unsigned count = 0;
    while (*str != '\0')
    {
        if (*str == c)
        {
            ++count;
        }
        ++str;
    }
    return count;
}

class DynArray
{
private:
    unsigned size = 0;
    int* first = nullptr;

    void copyFrom(const DynArray& other)
    {
        size = other.size;
        first = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            first[i] = other.first[i];
        }
    }

    void free()
    {
        delete[] first;
        first = nullptr;
    }

public:
    DynArray() = default;

    explicit DynArray(unsigned n)
    {
        first = new int[n] {};
        size = n;
    }

    DynArray(const char* str)
    {
        if (str == nullptr)
        {
            return;
        }
        size = charCount(' ', str) + 1;
        first = new int[size];
        unsigned index;

        while (*str != '\0')
        {
            unsigned temp = 0;
            while (*str != ' ' && *str != '\0')
            {
                temp *= 10;
                temp += (*str - '0');
                ++str;
            }
            first[index] = temp;
            ++index;
            ++str;
        }
    }

    DynArray(const DynArray& other)
    {
        copyFrom(other);
    }

    DynArray& operator=(const DynArray& other)
    {
        if (this == &other)
        {
            free();
            copyFrom(other);
        }
        
        return *this;
    }

    ~DynArray()
    {
        free();
    }

    void print() const
    {
        std::cout << "{";
        for (size_t i = 0; i < size - 1; ++i)
        {
            std::cout << first[i] << " ";
        }
        std::cout << first[size - 1] << "}, length: " << size << std::endl;
    }

    DynArray& operator+=(int x)
    {
        int *newBuffer = new int[size + 1];

        for (size_t i = 0; i < size; ++i)
        {
            newBuffer[i] = first[i];
        }
        
        newBuffer[size] = x;

        ++size;

        delete[] first;
        first = newBuffer;
        return *this;
    }

    DynArray operator+(const DynArray& b)
    {
        DynArray result;
        result.first = new int[size + b.size];
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

    bool isMember(int x) const
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

    friend bool operator==(const DynArray& a, const DynArray& b);

};

bool operator==(const DynArray& a, const DynArray& b)
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
    
}