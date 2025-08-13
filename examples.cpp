#include <iostream>

class Word {
    char data[21];
    size_t len;
public:
    Word() : len(0) {data[0]='\0';}
    Word(const char* str){
        std::strncpy(data, str, 20);
        data[20] = '\0';
        len = strlen(data);
    }
    Word(const Word& other){
        strcpy(data, other.data);
        len = other.len;
    }

    Word& operator=(const Word& other){
        if (this != &other){
            strcpy(data, other.data);
            len = other.len;
        }
        return *this;
    }
};

class NumbersSummator {
    int sumValue;
    int changes;
    int totalDelta;
public:
    // initializer list
    NumbersSummator(int start) 
        : sumValue(start), changes(0), totalDelta(0) {}
};