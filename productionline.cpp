#include <iostream>
#include <functional>

template <typename T>
class ProductionLine {
private:
    T initial;
    size_t n;
    std::function<T(T)> process;
public:
    ProductionLine(T initial, size_t n, std::function<T(T)> process)
        : initial(initial), n(n), process(process) {} 
        
    T operator[](size_t index) const {
        if (index >= n) {
            throw std::out_of_range("Index out of range");
        }
        T result = initial;
        for (size_t i = 0; i < index; i++){
            result = process(result);
        }
        return result;
    }    
    
    size_t size() const {
        return n;
    }
};

int doubleUp(int x) {
    return x * 2;
}

int main() {
    ProductionLine<int> doublingLine(1, 5, doubleUp);

    for (size_t i = 0; i < doublingLine.size(); i++){
        std::cout << doublingLine[i] << " ";
    }
    std::cout << std::endl;
}