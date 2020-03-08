#ifndef GRADEBOOK_GRADEBOOK_H
#define GRADEBOOK_GRADEBOOK_H
/*
*******************************************************************
* Name:         Peter Menchu                                      *
* Email:        menchupeter@gmail.com                             *
* Class:        section 001                                       *
* Lab:          section 231                                       *
* Description:  This program is a gradebook where the user can    *
*               select from 11 menu options to add and print data.*
*******************************************************************
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// structure used for holding grades of enrolled students
struct grades
{
    int coursegrades[5];
    int numofgrades;
};
// structure for each student
struct student
{
    char uID[6];
    char name[12];
    char major[12];
    int numofcourses;
};
// structure for courses
struct course
{
    char CourseID[9];
    char Title[31];
    char Department[31];
    student enrolled[10];
    int numenrolled;
    grades gradelist[10];
};
// function prototypes
int addcourse(course courses[], int numofcourses, int coursetracker);
int addstudent(student students[], int numofstudents, int student_tracker);
void addtocourse(student students[], int numofstudents, course courses[], int numofcourses);
void addgrades(course courses[], int numofcourses);
void courselist(course courses[], int numofcourses, int coursetracker);
void studentlist(student students[], int numofstudents, int student_tracker);
void students_in_course(course courses[], int numofcourses, int coursetracker);
void average(course courses[], int numofcourses);
void save(course courses[], int numofcourses, int coursetracker, student students[], int numofstudents, int student_tracker);
void load(course courses[], int numofcourses, int& coursetracker, student students[], int numofstudents, int& student_tracker);
#endif //GRADEBOOK_GRADEBOOK_H
