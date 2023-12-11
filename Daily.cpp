//Copyright 2022
//
// Created by jinesh patel on 3/28/22.
//
#include<string>
#include<iostream>
#include<sstream>
#include "Daily.h"

Daily::Daily() : Appointment() {
}

Daily::Daily(std::string desc, Time s, Time e) : Appointment(desc, s, e) {
}

bool Daily::occurs_on(int year, int month, int day) const {
    return true;
}

//void Daily::read() {
//    Appointment::read();
//}

void Daily::save(std::ostream& out) const {
    out << "Daily" << std::endl;
//    out << this->getStart().get_hours() << " " << this->getStart().get_minutes() << " " << this->getEnd().get_hours() << " " << this->getEnd().get_minutes() << " " << this->getDescription() << std::endl;
Appointment::save(out);
}

void Daily::load(std::istream& in) {

//    int t1, m1, t2, m2;
//    std::string des, line;
//
//    in >> t1 >> m1 >> t2 >> m2>>des;
//
//    Appointment::setStart(Time(t1, m1, 0));
//    Appointment::setEnd(Time(t2, m2, 0));
//    Appointment::setDescription(des);

    Appointment::load(in);
}

void Daily::read() {
Appointment::read();
}
