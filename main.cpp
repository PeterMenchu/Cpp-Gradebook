/*
*******************************************************************
* Name:         Peter Menchu                                      *
* Email:	menchupeter@gmail.com                                 *
* Class:        section 001                                       *
* Lab:          section 231                                       *
* Description:  This program is a gradebook where the user can    *
*               select from 9 menu options to add and print data. *
*******************************************************************
*/

#include "gradebook2header2.h"

int main()
{

    // ** note that this integer may cause issues with input type validation
    int choice; // integer to hold the menu selection
    // struct variable for 25 students
    int numofstudents = 25;
    student students[numofstudents];
    // initialize course counter to 0
    for(int j = 0; j < numofstudents; j++)
    {
        students[j].numofcourses = 0;
    }
    // struct variable for 10 courses
    int numofcourses = 10;
    course courses[numofcourses];
    // initialize number of enrolled students to 0 for each course
    for (int i = 0; i < numofcourses; i++)
    {
        courses[i].numenrolled = 0;
    }



    // int to keep track of courses added
    int coursetracker = 0;
    // tracks added students
    int student_tracker = 0;

    for (int x = 0; x < numofcourses; x++)
    {

        for (int y = 0; y < 10; y++)
        {
            courses[x].gradelist[y].numofgrades = 0;
        }

    }
    // menu output
    cout << "\t1.  Add a new course\n"
            "\t2.  Add a new student\n"
            "\t3.  Add a student to a course\n"
            "\t4.  Add grades for a student in a course\n"
            "\t5.  Print a list of all courses\n"
            "\t6.  Print a list of all students\n"
            "\t7.  Print a list of all students in a course\n"
            "\t8.  Compute the average for a student in a course\n"
            "\t9.  Load grade book (from a user-specified file)\n"
            "\t10. Store grade book (to a user-specified file)\n"
            "\t11. Exit\n";
    // do while loop used to control the program
    do
    {

        // prompt for menu entry
        cout << "\n";
        cout << "cmd> ";
        cin >> choice;

        switch (choice)// switch statement used to determine what the program will do, depends on menu selection
        {
            case 1:
                if (coursetracker >= 10)
                {
                    cout << "Error: you can only add 10 courses.\n";
                }
                else
                {
                    coursetracker = addcourse(courses, numofcourses, coursetracker);
                }
                break;
            case 2:
                if (student_tracker >= 25)
                {
                    cout << "Error: you can only add 25 students.\n";
                }
                else
                {
                    student_tracker = addstudent(students, numofstudents, student_tracker);
                }
                break;
            case 3:
                addtocourse(students, numofstudents, courses, numofcourses);
                break;
            case 4:
                addgrades(courses, numofcourses);
                break;
            case 5:
                courselist(courses, numofcourses, coursetracker);
                break;
            case 6:
                studentlist(students, numofstudents, student_tracker);
                break;
            case 7:
                students_in_course(courses, numofcourses, coursetracker);
                break;
            case 8:
                average(courses, numofcourses);
                break;
            case 9:
                load(courses, numofcourses, coursetracker, students, numofstudents, student_tracker);
                break;
            case 10:
                save(courses, numofcourses, coursetracker, students, numofstudents, student_tracker);
                break;
            case 11:
                cout << "Goodbye -- Thank you for using my gradebook.\n";
                break;
            default:
                break;

        }

    }while (choice != 11);// loops while the user does not choose to exit

    return 0;
}
