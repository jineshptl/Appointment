//Copyright 2022
//
// Created by jinesh patel on 3/28/22.
//

#ifndef CH_10APPOINTMENT_NEWCXXTEST_H
#define CH_10APPOINTMENT_NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "Daily.h"
#include "Date.h"
#include "Monthly.h"
#include "Onetime.h"
#include "Time.h"
#include "Appointment.h"
#include <fstream>
#include <sstream>
#include <string>
class Test : public CxxTest::TestSuite {
public:

    void testTime() { //test time class

        Time t(2, 30, 0); //overloads the constructor
        TS_ASSERT_EQUALS(t.get_hours(), 2);
        TS_ASSERT_EQUALS(t.get_minutes(), 30);
        TS_ASSERT_EQUALS(t.get_seconds(), 0); //compare the outputs

        t.add_seconds(-8);
        TS_ASSERT_EQUALS(t.get_seconds(), 52);

        t.add_seconds(5);
        TS_ASSERT_EQUALS(t.get_seconds(), 57);

        t.seconds_from(Time(1, 1, 1));

    }

    void testTime2() {

        Time t(3, 45, 32); //calls the overload constructor
        TS_ASSERT_EQUALS(t.get_hours(), 3); //compares the outputs
        TS_ASSERT_EQUALS(t.get_minutes(), 45);
        TS_ASSERT_EQUALS(t.get_seconds(), 32);

    }

    void testDate() {

        Date d(2000, 1, 1); //calls the overlod constructor
        TS_ASSERT_EQUALS(d.get_day(), 1);
        TS_ASSERT_EQUALS(d.get_month(), 1);
        TS_ASSERT_EQUALS(d.get_year(), 2000); //compare the outputs

        Date c(2000, 1, 1);

        d = c;
//        d.print();

    }

    void testAppointment() {

        std::string desc = "unknown";
        Appointment *a;
        a = new Daily(); //creates the appointment pointer
        // Time t;
        a->setDescription(desc); //calls the function
        a->setStart(Time(1, 1, 1)); //
        a->setEnd(Time(1, 1, 1));

        TS_ASSERT_EQUALS(a->getDescription(), desc);
        TS_ASSERT_EQUALS(a->getStart().get_hours(), 1); //tests the returns
        TS_ASSERT_EQUALS(a->getStart().get_minutes(), 1);
        TS_ASSERT_EQUALS(a->getEnd().get_hours(), 1);
        TS_ASSERT_EQUALS(a->getEnd().get_minutes(), 1); //tests what the time function returns

        a->print();
        //a->read();

        delete a;
    }

    void testAppointment2() {

        std::string desc = "unknown";
        Appointment *b;
        b = new Daily(desc, Time(1, 1, 1), Time(1, 1, 1));

        std::ostringstream fs;

//        b->occurs_on(2021, 3, 2);
        TS_ASSERT(b->occurs_on(2021, 3, 2));

        b->save(fs);
        std::string str = fs.str();

        TS_ASSERT_EQUALS(str, "Daily\n1 1 1 1 unknown\n");

        std::istringstream infs(str);

        string prefix;
        infs>>prefix;

        b->load(infs);
        b->print();

        delete b;

    }

    void testMonthly() {

        std::string desc = "unknown";

        Monthly* obj1 = new Monthly();
        delete obj1;

        Monthly* obj2 = new Monthly(desc, 1, Time(1, 1, 1), Time(2, 2, 2));
        obj2->occurs_on(2021, 3, 1);

        std::ostringstream fs;

        obj2->save(fs);
        std::string str = fs.str();

        TS_ASSERT_EQUALS(str, "Monthly\n1\n1 1 2 2 unknown\n");

        std::istringstream infs(str);

        string prefix;
        infs>>prefix;
        obj2->load(infs);
        obj2->print();

        infs = std::istringstream();
        infs.str("1 1 2 2 unknown\n1\n");

        cin.rdbuf(infs.rdbuf());
        obj2->read();


        fs = std::ostringstream();

        obj2->save(fs);
        str = fs.str();

        TS_ASSERT_EQUALS(str, "Monthly\n1\n1 1 2 2 unknown\n");


        //obj2->read();

        delete obj2;

    }

    void testDaily() {

        std::string desc = "unknown";

        Daily* obj1 = new Daily();
        delete obj1;

        Daily* obj2 = new Daily(desc, Time(1, 1, 1), Time(2, 2, 2));
//        obj2->occurs_on(2021, 3, 1);

        TS_ASSERT(obj2->occurs_on(2021, 3, 1));


        std::ostringstream fs;

        obj2->save(fs);
        std::string str = fs.str();

        TS_ASSERT_EQUALS(str, "Daily\n1 1 2 2 unknown\n");

        std::istringstream infs(str);

        string prefix;
        infs>>prefix;

        obj2->load(infs);

        obj2->print();
//        infs.clear();
        infs = std::istringstream();
        infs.str("1 1 2 2 unknown\n");

        cin.rdbuf(infs.rdbuf());
        obj2->read();


        fs = std::ostringstream();

        obj2->save(fs);
        str = fs.str();

        TS_ASSERT_EQUALS(str, "Daily\n1 1 2 2 unknown\n");

        delete obj2;

    }

    void testOnetime() {

        std::string desc = "unknown";

        Onetime* obj1 = new Onetime();
        delete obj1;

        Date d(2000, 1, 1);

        Onetime* obj2 = new Onetime(desc, d, Time(1, 1, 1), Time(2, 2, 2));
//        obj2->occurs_on(2021, 3, 1);

        TS_ASSERT(!obj2->occurs_on(2021, 3, 1));

        std::ostringstream fs;

        obj2->save(fs);
        std::string str = fs.str();

        TS_ASSERT_EQUALS(str, "Onetime\n2000 1 1\n1 1 2 2 unknown\n");

        std::istringstream infs(str);

        string prefix;
        infs>>prefix;

        obj2->load(infs);
        obj2->print();

        infs = std::istringstream();
        infs.str("1 1 2 2 unknown\n2000 1 1\n");

        cin.rdbuf(infs.rdbuf());
        obj2->read();


        fs = std::ostringstream();

        obj2->save(fs);
        str = fs.str();

        TS_ASSERT_EQUALS(str, "Onetime\n2000 1 1\n1 1 2 2 unknown\n");

        //obj2->read();

        delete obj2;

    }

//    void testRead () {
//
//    }


};

#endif //CH_10APPOINTMENT_NEWCXXTEST_H
