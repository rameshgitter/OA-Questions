/*
employee has to work exactly as many hours as they are told to each week. 
scheduling no more than a given daily maximum number of hours. 
On some days, the number of hours worked will be given. 
The employee gets to choose the remainder of their schedule, within the given limits.

A completed schedule consists of exactly 7 digits in the range 0 to 8 that represent each day's work hours. 
A pattern string similar to the schedule is given, but some of its digits are replaced by a question mark, ?, (ascii 63 decimal). 
Given a maximum number of hours that can be worked in a day, replace the question marks with digits so that the sum of the scheduled hours is exactly the hours that must be worked in a week.

Determine all possible work schedules that meet the requirements and return them as a list of strings, sorted ascending. 

Example

pattern = '0877840'

work hours = 24

day_hours = 4

There are two days on which they must work 24-20 = 4 more hours for the week. 
All of the possible schedules are listed below: 
*/

