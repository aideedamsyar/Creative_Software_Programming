#include "calendar.h"

MyCalendar::MyCalendar() : _year(0), _month(1), _day(1) {}

MyCalendar::MyCalendar(int year, int month, int day) : _year(year), _month(month), _day(day) {}

bool MyCalendar::NextDay(int n) {
    int totalDays = ComputeDaysFromYearStart(_year, _month, _day) + n;
    int daysInMonth;

    
    if (n >= 0) {
        while (totalDays > GetDaysInYear(_year)) {
            totalDays -= GetDaysInYear(_year);
            _year++;
        }
    } else {
        while (totalDays <= 0) {
            _year--;
            totalDays += GetDaysInYear(_year);
        }
    }

    _month = 1;
    while (true) {
        daysInMonth = (_month == 2) ? ((GetDaysInYear(_year) == 366) ? 29 : 28) : 
                      (_month == 4 || _month == 6 || _month == 9 || _month == 11) ? 30 : 31;

        if (totalDays > daysInMonth) {
            totalDays -= daysInMonth;
            _month++;
        } else {
            _day = totalDays;
            break;
        }
    }

    return (_year >= 0 && _year <= 9999 && _month >= 1 && _month <= 12 && _day >= 1 && _day <= daysInMonth);
}


bool MyCalendar::SetDate(int year, int month, int day) {
    int daysInMonth = (month == 2) ? ((GetDaysInYear(year) == 366) ? 29 : 28) : 
                      (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;

    if (year >= 0 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth) {
        _year = year;
        _month = month;
        _day = day;
        return true;
    }

    return false;
}

int MyCalendar::year() const { return _year; }

int MyCalendar::month() const { return _month; }

int MyCalendar::day() const { return _day; }

int MyCalendar::GetDaysInYear(int year) {
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) ? 366 : 365;
}

int MyCalendar::ComputeDaysFromYearStart(int year, int month, int day) {
    int days = day;
    for (int m = 1; m < month; ++m) {
        days += (m == 2) ? ((GetDaysInYear(year) == 366) ? 29 : 28) : 
                (m == 4 || m == 6 || m == 9 || m == 11) ? 30 : 31;
    }
    return days;
}

std::ostream& operator<<(std::ostream& out, const MyCalendar& c) {
    out << c.year() << '.' << c.month() << '.' << c.day();
    return out;
}

std::istream& operator>>(std::istream& in, MyCalendar& c) {
    int year, month, day;
    char dot1, dot2;
    if (in >> year >> dot1 >> month >> dot2 >> day && dot1 == '.' && dot2 == '.' && c.SetDate(year, month, day)) {
        return in;
    } else {
        in.setstate(std::ios_base::failbit);
        return in;
    }
}
