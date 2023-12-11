//Copyright 2022
//
// Created by jinesh patel on 3/28/22.
//
#include<iostream>
#include "Monthly.h"
#include "Appointment.h"

Monthly::Monthly() : Appointment() {
}

Monthly::Monthly(std::string desc, int d, Time s, Time e)
        : Appointment(desc, s, e) {
    day = d;
}

bool Monthly::occurs_on(int year, int month, int d) const {
    return day == d;
}

void Monthly::read() {
    int d;
    Appointment::read();
    std::cout << "Enter day: ";
    std::cin>>d;

    day = d;
}

void Monthly::save(std::ostream& out) const {

    out << "Monthly" << std::endl;
    out << day << std::endl;
    out << this->getStart().get_hours() << " " << this->getStart().get_minutes() << " " << this->getEnd().get_hours() << " " << this->getEnd().get_minutes() << " " << this->getDescription() << std::endl;

}

void Monthly::load(std::istream& in) {
    int t1, m1, t2, m2, d;
    std::string des;

    in >> d >> t1 >> m1 >> t2 >> m2>>des;

    day = d;
    Appointment::setStart(Time(t1, m1, 0));
    Appointment::setEnd(Time(t2, m2, 0));
    Appointment::setDescription(des);
}
