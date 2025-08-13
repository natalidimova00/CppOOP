#include <iostream>

struct HistoryEntry {
    int month;
    std::string url;
};

class BrowserHistory {
    HistoryEntry* entries;
    size_t capacity;
    size_t size;
public:
    BrowserHistory(size_t n) 
        : capacity(n), size(0) {entries = new HistoryEntry[n];}
    BrowserHistory(const BrowserHistory& other)
        : capacity(other.capacity), size(other.size) {
        entries = new HistoryEntry[capacity];
        for (size_t i = 0; i < size; i++){
            entries[i] = other.entries[i];
        }
    }
    BrowserHistory& operator=(const BrowserHistory& other){
        if (this != &other){
            delete[] entries;
            capacity = other.capacity;
            size = other.size;
            entries = new HistoryEntry[capacity];
            for (size_t i = 0; i < size; i++){
                entries[i] = other.entries[i];
            }
        }
        return *this;
    }  
    ~BrowserHistory() {
        delete[] entries;
    }  
};