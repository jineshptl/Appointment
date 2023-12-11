//Copyright 2022
//
// Created by jinesh patel on 3/28/22.
//
#include <iostream>
#include "Date.h"

Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int y, int m, int d) {
    day = d;
    month = m;
    year = y;
}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}

bool Date::operator==(Date other) const {
    return day == other.day && month == other.month && year == other.year;
}
