#include "my_clock.h"

using namespace std;

void MyClock::Tick(int seconds) {
    seconds = (seconds % 86400 + 86400) % 86400; // Handle positive, negative and exceeding 1 day input
    _sec += seconds;

    _min += _sec / 60;
    _sec %= 60;
    
    _hour += _min / 60;
    _min %= 60;
    
    _hour %= 24;
}

bool MyClock::SetTime(int hour, int minute, int second) {
    if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60) {
        _hour = hour;
        _min = minute;
        _sec = second;
        return true;
    }

    // Manually add leading zeros to minutes and seconds if they are less than 10
    cout << "Invalid time: " << hour << ":";
    if (minute < 10) cout << "0";
    cout << minute << ":";
    if (second < 10) cout << "0";
    cout << second << endl;

    return false;
}


int MyClock::hour() const {
    return _hour;
}
int MyClock::minute() const {
    return _min;
}
int MyClock::second() const {
    return _sec;
}

ostream& operator<<(ostream& os, const MyClock& c) {
    os << c.hour() << ":" << c.minute() << ":" << c.second();
    return os;
}
istream& operator>>(istream& is, MyClock& c) {
    string h, m, s;
    getline(is, h, ':');
    getline(is, m, ':');
    getline(is, s);
    c.SetTime(stoi(h), stoi(m), stoi(s));
    return is;
}