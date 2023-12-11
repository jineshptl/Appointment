//Copyright 2022
//
// Created by jinesh patel on 3/28/22.
//
#include "Appointment.h"

Appointment::Appointment() {
    description = "";
    start = Time(0,0,0);
    end= Time(0,0,0);
}

Appointment::Appointment(std::string desc, Time s, Time e) {
    description = desc;
    start = s;
    end = e;
}

void Appointment::print() const {
    std::cout << " " << start.get_hours() << ":";
    if (start.get_minutes() < 10) std::cout << "0";
    std::cout << start.get_minutes() << " - " << end.get_hours() << ":";
    if (end.get_minutes() < 10) std::cout << "0";
    std::cout << end.get_minutes() << " " << description << "\n";
}

void Appointment::save(ostream &out) const {
    out << start.get_hours() << " " << start.get_minutes() << " " << end.get_hours() << " " << end.get_minutes() << " " << description << endl;
}

void Appointment::load(istream &in) {
    int t1, m1, t2, m2;
    std::string des;
    in >> t1 >> m1 >> t2 >> m2>>des;
    start= Time (t1, m1, 0);
    end = Time(t2, m2, 0);
    description = des;
}

Appointment::~Appointment() {
}

void Appointment::setEnd(Time e) {
    end = e;
}

Time Appointment::getEnd() const {
    return end;
}

void Appointment::setStart(Time s) {
    start = s;
}

Time Appointment::getStart() const {
    return start;
}

void Appointment::setDescription(std::string des) {
    description = des;
}

std::string Appointment::getDescription()const {
    return description;
}

void Appointment::read() {
Appointment::load (cin);
cout <<"Enter start_hours start_mins end_hours end_mins descript:" << endl;
}

