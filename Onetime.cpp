//Copyright 2022
//
// Created by jinesh patel on 3/28/22.
//
#include "Onetime.h"
#include<iostream>
#include "Monthly.h"

Date w;

Onetime::Onetime() : Appointment() {
}

Onetime::Onetime(std::string desc, Date d, Time s, Time e) : Appointment(desc, s, e) {
    when = d;
}

bool Onetime::occurs_on(int year, int month, int day) const {
    return when == (Date(year, month, day));
}

void Onetime::read() {

    Appointment::read();
    std::cout << "Enter year month day: " << std::endl;
    int year, month, day;
    std::cin >> year >> month>>day;

    Date w(year, month, day);
    when = w;

}

void Onetime::save(std::ostream& out) const {

    out << "Onetime" << std::endl;
    out << when.get_year() << " " << when.get_month() << " " << when.get_day() << std::endl;
    out << this->getStart().get_hours() << " " << this->getStart().get_minutes() << " " << this->getEnd().get_hours() << " " << this->getEnd().get_minutes() << " " << this->getDescription() << std::endl;

}

void Onetime::load(std::istream& in) {

    int t1, m1, t2, m2, y, m, d;
    std::string des;

    in >> y >> m>>d;
    in >> t1 >> m1 >> t2 >> m2>>des;

    when = Date(y, m, d);
    Appointment::setStart(Time(t1, m1, 0));
    Appointment::setEnd(Time(t2, m2, 0));
    Appointment::setDescription(des);
}

