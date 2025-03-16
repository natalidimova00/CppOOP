#include <iostream>
#include <stdexcept>

class Time 
{
    private:
    int hours;
    int minutes;

    void validateTime()
    {
        if (hours < 0 || hours >= 24)
        {
            throw std::invalid_argument("Invalid hour!");
        }
        if (minutes < 0 || minutes >= 59)
        {
            throw std::invalid_argument("Invalid minutes!");
        }
    }

    public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m)
    {
        validateTime();
    }

    int getHours() const
    {
        return hours;
    }

    int getMinutes() const
    {
        return minutes;
    }

    void setHours(int h)
    {
        hours = h;
        validateTime();
    }

    void setMinutes(int m)
    {
        minutes = m;
        validateTime();
    }

    void addMinutes(int m)
    {
        int totalMins = hours * 60 + minutes + m;
        hours = (totalMins / 60) % 24;
        minutes = totalMins % 60;
        validateTime();
    }

    int totalMinutes() const
    {
        return hours * 60 + minutes;
    }

    bool operator<(const Time& other) const
    {
        return totalMinutes() < other.totalMinutes();
    }

    Time operator+(const Time& other) const
    {
        int totalMins = this->totalMinutes() + other.totalMinutes();
        return Time((totalMins / 60) % 24, totalMins % 60);
    }

    Time operator-(const Time& other) const
    {
        int totalMins1 = this->totalMinutes();
        int totalMins2 = other.totalMinutes();
        int diff;

        if (totalMins1 >= totalMins2)
        {
            diff = totalMins1 - totalMins2;
        } else {
            diff = totalMins2 - totalMins1;
        }
        
        return Time(diff / 60, diff % 60);
    }

    Time operator*(int n) const
    {
        int totalMins = this->totalMinutes() * n;
        return Time((totalMins / 60) % 24, totalMins % 60);
    }

    friend Time operator*(int n, const Time& t){
        return t * n;
    }

    void display() const
    {
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
                  << (minutes < 10 ? "0" : "") << minutes << std::endl;
    }
};

int main()
{
    Time t1(10, 30);
    Time t2(15, 45);

    std::cout << "T1: ";
    t1.display();
    std::cout << "T2: ";
    t2.display();

    std::cout << "T1 + T2 = ";
    (t1 + t2).display();

    std::cout << "T2 - T1 = ";
    (t2 - t1).display();
    
    std::cout << "T2 - T1 = ";
    (t1 - t2).display();

    Time t3 = t1 * 2;
    std::cout << "T1 * 2 = ";
    t3.display();

    Time t4 = 3 * t2;
    std::cout << "3 * T2 = ";
    t4.display();

    std::cout << "T1 is before T2: " << (t1 < t2 ? "Yes" : "No") << std::endl;

    t1.addMinutes(200);
    std::cout << "T1 + 200 minutes = ";
    t1.display();

    std::cout << "Minutes since the begining of the day: " << t1.totalMinutes() << std::endl;
}