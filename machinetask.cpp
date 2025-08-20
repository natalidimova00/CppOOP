#include <iostream>
#include <string>

class MachineTask {
private:
    std::string name;
    int duration;

public:
    MachineTask(const std::string& taskName, int taskDuration) {
        if (taskDuration <= 0){
            throw std::invalid_argument("Time should be positive number");
        }
        name = taskName;
        duration = taskDuration;
    }    
    
    std::string getName() const {
        return name;
    }

    int getDuration() const {
        return duration;
    }

    void setName(const std::string& taskName) {
        name = taskName;
    }

    void setDuration(int taskDuration) {
        if (taskDuration <= 0){
            throw std::invalid_argument("Time should be positive number");
        }
        duration = taskDuration;
    }

    void printInfo() const {
        std::cout << "Task: " << name
                  << ", duration: " << duration
                  << " minutes." << std::endl;
    }
};

int main() {
    MachineTask task1("Cutting metal", 30);
    task1.printInfo();

    MachineTask task2("Cutting tree", 15);
    task2.printInfo();

    task2.setDuration(10);
    task2.printInfo();
}