//Copyright 2022
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: hloi
 *
 * Created on March 19, 2018, 10:27 PM
 */

#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>

//using namespace std;
using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::cin;
const int DAYS_PER_MONTH = 30;
/**
   A class that describes a time of day
   (between 00:00:00 and 23:59:59)
*/
class Time
{
public:
   /**
      Constructs a time of day.
      @param hour the hours
      @param min the minutes
      @param sec the seconds
   */
   Time(int hour, int min, int sec);
   /**
      Constructs a Time object that is set to 
      the time at which the constructor executes.
   */
   Time();

   /**
      Gets the hours of this time.
      @return the hours
   */
   int get_hours() const;
   /**
      Gets the minutes of this time.
      @return the minutes
   */
   int get_minutes() const;
   /**
      Gets the seconds of this time.
      @return the seconds
   */
   int get_seconds() const;

   /**
      Computes the seconds between this time and another.
      @param t the other time
      @return the number of seconds between this time and t
   */
   int seconds_from(Time t) const;
   /**
      Adds a number of seconds to this time.
      @param s the number of seconds to add
   */
   void add_seconds(int s);

private:
   int time_in_secs;
};


#endif /* TIME_H */

