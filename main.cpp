//Copyright 2022
#include <cstdlib>
#include <iostream>
#include<string>
#include <vector>
#include <fstream>
#include<sstream>
#include "Appointment.h"
#include "Daily.h"
#include "Onetime.h"
#include "Monthly.h"

using namespace std;

const int SCHEDULE_SIZE = 10;

int main(int argc, char** argv) {

    char x = '?';
    vector <Appointment*> schedule;
    int year, month, day, t1, m1, t2, m2;
    string des, name;
    ifstream infs;
    ofstream fs;

    while (cin >> x) {

        cout << "Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): ";
//        cin>>x;
        cout << x << endl;

        if (x == 'q')
            break;

        else if (x == 'd') {
            Daily* newapp = new Daily();
            newapp->read();
            schedule.push_back(newapp);

        } else if (x == 'm') {

            Monthly* newapp = new Monthly();
            newapp->read();
            schedule.push_back(newapp);

        } else if (x == 'o') {
            Onetime* newapp = new Onetime();
            newapp->read();
            schedule.push_back(newapp);


        } else if (x == 'c') {

            cout << "Enter year month day: ";
            cin >> year >> month>>day;

            cout << "You have these appointments: " << "\n";
            bool no_appointments = true;
            for (int i = 0; i < schedule.size(); i++) {
                if (schedule.at(i)->occurs_on(year, month, day)) {
                    schedule.at(i)->print();
                    no_appointments = false;
                }
            }

            if (no_appointments) {
                cout << "You have no appointments on " << year << " " << month << " " << day << "." << endl;
            }
        } else if (x == 's') {

            cout << "File name: ";
            cin>>name;

            fs.open(name.c_str());

            for (int i = 0; i < schedule.size(); i++) {
                schedule.at(i)->save(fs);

            }

            fs.close();
            fs.clear();
        }
        else if (x == 'l') {
            cout << "File name: ";
            cin>>name;

            infs.open("appt.txt");
            string type;

            while (getline(infs, type)) {

                istringstream s(type);
                if (type.size() > 0) {

                    if (type == "Onetime") {
                        Onetime* newapp = new Onetime();
                        newapp->load(infs);
                        schedule.push_back(newapp);
                    } else if (type == "Monthly") {

                        Monthly* newapp = new Monthly();
                        newapp->load(infs);
                        schedule.push_back(newapp);

                    } else if (type == "Daily") {

                        Daily* newapp = new Daily();
                        newapp->load(infs);
                        schedule.push_back(newapp);


                    }
                }
            }
            infs.close();
            infs.clear();
        }
    }
    return 0;
}
