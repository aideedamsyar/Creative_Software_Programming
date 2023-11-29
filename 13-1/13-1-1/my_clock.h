#ifndef __MY_CLOCK_H__
#define __MY_CLOCK_H__

#include <iostream> 
class MyClock {
    public:
        void Tick(int seconds = 1);
        bool SetTime(int hour, int minute, int second);
        // If input is invalid, it returns false and does not change the time
        int hour() const;
        int minute() const;
        int second() const;
    private:
        int _hour = 0, _min = 0, _sec = 0;
        // You can add any function if needed
    };

// The format for input/output is hh:mm:ss
std::ostream& operator<<(std::ostream& os, const MyClock& c);
std::istream& operator>>(std::istream& is, MyClock& c);

#endif // __MY_CLOCK_H__