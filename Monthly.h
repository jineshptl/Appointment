//Copyright 2022
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Monthly.h
 * Author: hloi
 *
 * Created on March 19, 2018, 10:52 PM
 */

#ifndef MONTHLY_H
#define MONTHLY_H

#include <iostream>
#include "Appointment.h"
#include "Time.h"
//using std::string;
//using std::ostream;
//using std::istream;

class Monthly : public Appointment
{
public:
   /**
      Constructs a monthly appointment 
   */
   Monthly();
   /* Constructs a month appointment.
      @param desc the description of a daily appointment
      @param d the day of the appointment
      @param s the start time of the appointment
      @param e the end time of the appointment
    * 
    */
   Monthly(std::string desc, int d, Time s, Time e);
   /*
    read in the appointment in the following format
    * Enter start_hours start_mins end_hours end_mins descript:
    * 5 0 6 0 dentist  
    * Enter day:
    * 5
    */
   void read();
    /*
    * save the monthly appointment with a header
    * appointment type
    * day
    * start_hours start_mins end_hours end_mins descript; for example:
    * 
    * Monthly
    * 5
    * 5 0 6 0 dentist    
    */   
   virtual void save(ostream& out) const;
    /*
    * load the monthly appointment with a header
    * appointment type
    * day
    * start_hours start_mins end_hours end_mins descript; for example:
    */   
   virtual void load(istream& in);
   /**
   Determines if the appointment occurs on the given day.
   @param year a year value
   @param month a month value of 1 for Jan, to 12 for Dec
   @param day a day value
   @return true if the appointment occurs on the given day
   */
   virtual bool occurs_on(int year, int month, int day) const;
private:
   int day;  // day of the appointment
};


#endif /* MONTHLY_H */

