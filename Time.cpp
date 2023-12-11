//Copyright 2022
//
// Created by jinesh patel on 3/28/22.
//

#include "Time.h"

Time::Time(int hour, int min, int sec) {
    time_in_secs = (60 * 60 * hour) + (60 * min) + sec;
}

Time::Time() {
    time_in_secs = 0;
}

int Time::get_hours() const {
    return (time_in_secs / (60 * 60));
}

int Time::get_minutes() const {
    return (time_in_secs / 60) % 60;
}

int Time::get_seconds() const {
    return (time_in_secs % 60);
}

int Time::seconds_from(Time t) const {
    return (time_in_secs - t.time_in_secs);
}

int remainder(int a, int n) {
    if (a >= 0) {
        return a % n;
    } else {
        return n - 1 - (-a - 1) % n;
    }
}

void Time::add_seconds(int s) {
    const int SECONDS_PER_DAY = (60 * 60 * 24);
    time_in_secs = remainder(time_in_secs + s, SECONDS_PER_DAY);
}

