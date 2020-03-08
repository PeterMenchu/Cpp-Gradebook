/*
*******************************************************************
* Name:         Peter Menchu                                      *
* Email:        menchupeter@gmail.com                             *
* Class:        section 001                                       *
* Lab:          section 231                                       *
* Description:  This program is a gradebook where the user can    *
*               select from 9 menu options to add and print data. *
*******************************************************************
*/

#include "Gradebook.h"

int addcourse(course courses[], int numofcourses, int coursetracker)
{

    int f;// flag
    char courseinput[9];// initial input var, used to check for duplicates
    // prompt and input for course ID
    cin.ignore();// clears input
    do
    {
        f = 0;// reset flag

        // prompt and read in for ID
        cout << "Enter course ID: ";

        cin.getline(courseinput, 9);

        // search for course
        for(int i = 0; i < numofcourses; i++)
        {
            if(strncmp(courseinput, courses[i].CourseID, 9) == 0)
            {
                f = 1;// sets flag
            }
        }

        if (f == 1)// if the course has already been added
        {
            cout << "Error: " << courseinput << " has already been added.\n";
        }
        else// adds the course
        {
            strncpy(courses[coursetracker].CourseID, courseinput, 9);
        }

    }while(f == 1);// loops while an invalid student is entered


    // prompt and input for course name
    cout << "Enter course name: ";

    cin.getline(courses[coursetracker].Title, 31);


    // prompt and input for department
    cout << "Enter department name: ";

    cin.getline(courses[coursetracker].Department, 31);

    cout << courses[coursetracker].CourseID << " has been added.\n";

    coursetracker = coursetracker++;// adds one to coursetracker to keep track of courses added


    return coursetracker;// returns the updated tracker
}

int addstudent(student students[], int numofstudents, int student_tracker)
{


    int f = 0;// flag declaration
    char nameinput[12];// used to check for duplicate names
    int duplicate;// used to track the duplicate name


    cin.ignore();// clears input
    do
    {
        f = 0;// reset flag

        // prompt and read in for name
        cout << "Enter student's name: ";

        cin.getline(nameinput, 12);

        // search for student
        for(int i = 0; i < numofstudents; i++)
        {
            if(strncmp(nameinput, students[i].name, 12) == 0)
            {
                f = 1;// sets flag
                duplicate = i;// tracks student i
            }
        }

        if (f == 1)// if the student has already been added
        {
            cout << "Error: " << nameinput << " is already enrolled as " << students[duplicate].uID << ".\n";
        }
        else// adds the student
        {
            strncpy(students[student_tracker].name, nameinput, 12);
        }

    }while(f == 1);// loops while an invalid student is entered



    // prompt and input for the student's major
    cout << "Enter student's major: ";

    cin.getline(students[student_tracker].major, 12);


    // ID number generation
    if(student_tracker < 9)// if < 10 students
    {
        char IDnum = static_cast<char>(student_tracker + 49);// sets IDnum by casting an int to a char

        students[student_tracker].uID[0] = 'I';
        students[student_tracker].uID[1] = 'D';
        students[student_tracker].uID[2] = '0';
        students[student_tracker].uID[3] = '0';
        students[student_tracker].uID[4] = IDnum;
        students[student_tracker].uID[5] = '\0';
    }
    else if(student_tracker < 19)// >= 10 students
    {
        char IDnum = static_cast<char>(student_tracker + 39);

        students[student_tracker].uID[0] = 'I';
        students[student_tracker].uID[1] = 'D';
        students[student_tracker].uID[2] = '0';
        students[student_tracker].uID[3] = '1';
        students[student_tracker].uID[4] = IDnum;
        students[student_tracker].uID[5] = '\0';
    }
    else// >= 20
    {
        char IDnum = static_cast<char>(student_tracker + 29);

        students[student_tracker].uID[0] = 'I';
        students[student_tracker].uID[1] = 'D';
        students[student_tracker].uID[2] = '0';
        students[student_tracker].uID[3] = '2';
        students[student_tracker].uID[4] = IDnum;
        students[student_tracker].uID[5] = '\0';
    }

    cout << "Added: " << students[student_tracker].name << " " << students[student_tracker].uID << endl;

    student_tracker++;// adds one to keep track of students added

    return student_tracker;
}

void addtocourse(student students[], int numofstudents, course courses[], int numofcourses)
{

    int studentflag;// tracks the course
    int courseflag;// tracks the student
    int f = 0;// sets flag to 0
    int f2 = 0;
    int f3 =0;
    char nameinput[12];// char array/string for name input
    char courseinput[9];// char array for course input

    do
    {
        f = 0;
        f2 = 0;
        f3 = 0;
        cout << "Enter student name: ";
        cin.ignore();// clears input
        cin.getline(nameinput, 12);
        cout << "Enter course ID: ";
        cin.getline(courseinput, 9);

        // search for student
        for(int i  = 0; i < numofstudents; i++)
        {
            if(strncmp(nameinput, students[i].name, 11) == 0)
            {
                studentflag = i;
                f2 = 1;
            }

        }
//		if (f2 != 1)
//		{
//			cout << "Error: student not found.\n";
//			f = 1;
//		}


        // search for course
        for(int j  = 0; j < numofcourses; j++)
        {
            if(strncmp(courseinput, courses[j].CourseID, 9) == 0)
            {
                courseflag = j;
                f3 = 1;
            }
        }
        if (f3 != 1)
        {
            cout << "Error: course not found.\n";
            f = 1;
        }

        if (f != 1)
        {
            // check if student is already enrolled
            for(int x = 0; x < 10; x++)
            {
                if(strncmp(nameinput, courses[courseflag].enrolled[x].name, 12) == 0)
                {
                    cout << "Error: " << students[studentflag].name << " is already enrolled in " << courseinput << ".\n";
                    f = 1;
                }
            }

            // checks if students has been added to 4 courses
            if(students[studentflag].numofcourses >= 4)
            {
                f = 1;
                cout << "Error: students can only be enrolled in four courses.\n";
            }

            // checks if course is full
            if(courses[courseflag].numenrolled >= 10)
            {
                f = 1;
                cout << "Error: this class is full.\n";
            }
        }

    }while(f == 1);// prompts while input is invalid

    int enrolledstudents = courses[courseflag].numenrolled;

    // copies student to the course
    courses[courseflag].enrolled[enrolledstudents] = students[studentflag];

    cout << "Added " << courses[courseflag].enrolled[enrolledstudents].name << " to " << courses[courseflag].CourseID << ".\n";

    courses[courseflag].numenrolled = courses[courseflag].numenrolled + 1;// keeps track of students enrolled in a course
    students[studentflag].numofcourses = students[studentflag].numofcourses + 1;// keeps track of courses students are enrolled in

    return;
}

void addgrades(course courses[], int numofcourses)
{
    char nameinput[12];// char array/string for name input
    char courseinput[9];// char array/string
    int studentflag;// tracks student
    int courseflag;// tracks course
    int gradeinput;// in for grade input

    cout << "Enter course ID: ";
    cin.ignore();// clear input
    cin.getline(courseinput, 9);
    cout << "Enter student name: ";
    cin.getline(nameinput, 12);

    // search for course
    for(int j  = 0; j < numofcourses; j++)
    {
        if(strncmp(courseinput, courses[j].CourseID, 9) == 0)
        {
            courseflag = j;
        }
    }

    // search for student
    for(int i  = 0; i < courses[courseflag].numenrolled; i++)
    {
        if(strncmp(nameinput, courses[courseflag].enrolled[i].name, 11) == 0)
        {
            studentflag = i;
        }
    }

    // prompt for grades
    cout << "Enter up to five grades for "<< courses[courseflag].enrolled[studentflag].name << ":\n";
    // loops for up to five grades to be entered
    for(int x = 0; x < 5; x++)
    {
        cout << "Enter grade (enter a -1 to end input): ";
        cin >> gradeinput;

        if (gradeinput == -1)// checks for flag input
        {
            break;// breaks the loop, ends input
        }
        else// adds grade
        {
            courses[courseflag].gradelist[studentflag].coursegrades[x] = gradeinput;
            courses[courseflag].gradelist[studentflag].numofgrades++;
        }



    }



    return;
}

void courselist(course courses[], int numofcourses, int coursetracker)
{

    cout << "Courses: \n";
    cout << "--------\n";

    // prints each course
    for (int i = 0; i < coursetracker; i++)
    {
        cout << courses[i].CourseID << "  " << courses[i].Title << "\t" << courses[i].Department << endl;

    }
}

void studentlist(student students[], int numofstudents, int student_tracker)
{
    cout << "Students: \n";
    cout << "---------\n";

    // prints each student
    for (int i = 0; i < student_tracker; i++)
    {
        cout << students[i].uID << "  " << students[i].name << "\t" << students[i].major << endl;

    }
}

void students_in_course(course courses[], int numofcourses, int coursetracker)
{
    char courseinput[9];
    int courseflag;

    // prompt and read in for course
    cout << "Enter course ID: ";
    cin >> courseinput;

    cout << "Students in " << courseinput << ":\n";
    cout << "---------------------\n";

    // search for course
    for(int j  = 0; j < numofcourses; j++)
    {
        if(strncmp(courseinput, courses[j].CourseID, 9) == 0)
        {
            courseflag = j;
        }
    }

    // prints each student
    for (int i = 0; i < courses[courseflag].numenrolled; i++)
    {
        cout << courses[courseflag].enrolled[i].uID << "  " << courses[courseflag].enrolled[i].name << endl;

    }

    return;
}

void average(course courses[], int numofcourses)
{

    char studentinput[6];// var for uID input
    char courseinput[9];// var for course ID input
    int studentflag;// tracks student
    int courseflag;// tracks course
    double average;// var to store the average
    double sum = 0;// int to hold the sum

    cout << "Enter course ID: ";
    cin >> courseinput;
    cout << "Enter student ID: ";
    cin >> studentinput;

    // search for course
    for(int j  = 0; j < numofcourses; j++)
    {
        if(strncmp(courseinput, courses[j].CourseID, 9) == 0)
        {
            courseflag = j;
        }
    }

    // search for student
    for(int i  = 0; i < courses[courseflag].numenrolled; i++)
    {
        if(strncmp(studentinput, courses[courseflag].enrolled[i].uID, 6) == 0)
        {
            studentflag = i;
        }
    }

    cout << "Average:  ";

    // computes sum and lists grades
    for (int x = 0; x < courses[courseflag].gradelist[studentflag].numofgrades; x++)
    {
        cout << courses[courseflag].gradelist[studentflag].coursegrades[x] << "  ";
        sum = sum + courses[courseflag].gradelist[studentflag].coursegrades[x];
    }




    average = sum/courses[courseflag].gradelist[studentflag].numofgrades;// computes average

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << "=  " << average << endl;// prints average

    return;
}

void save(course courses[], int numofcourses, int coursetracker, student students[], int numofstudents, int student_tracker)
{

    ofstream fout;// declaration of output file
    char outfile_name[40];// to store the name

    // prompt and read in for name
    cout << "Enter file name: ";
    cin >> outfile_name;
    fout.open(outfile_name);// opens the file
    cout << "Output file opened: " << outfile_name << endl;

    // prints out my trackers for the for loops first
    fout << coursetracker << endl;
    fout << student_tracker << endl;

    // prints out all course variables
    for (int i = 0; i < coursetracker; i++)
    {
        fout << courses[i].CourseID << endl;
        fout << courses[i].Title << endl;
        fout << courses[i].Department << endl;
        fout << courses[i].numenrolled << endl;
        // adds enrolled students
        for (int x = 0; x < courses[i].numenrolled; x++)
        {
            fout << courses[i].enrolled[x].uID << endl;
            fout << courses[i].enrolled[x].name << endl;
            fout << courses[i].enrolled[x].major << endl;
            fout << courses[i].gradelist[x].numofgrades << endl;
            // writes the grades for each student
            for (int y = 0; y < courses[i].gradelist[x].numofgrades; y++)
            {
                fout << courses[i].gradelist[x].coursegrades[y] << endl;
            }

        }
    }

    //prints out all student variables
    for (int j = 0; j < student_tracker; j++)
    {
        fout << students[j].uID << endl;
        fout << students[j].name << endl;
        fout << students[j].major << endl;
        fout << students[j].numofcourses << endl;
    }

    cout << "Data successfully stored in " << outfile_name << endl;

    fout.close();// closes the file

    cout << "Output file closed: " << outfile_name << endl;

    return;
}
void load(course courses[], int numofcourses, int& coursetracker, student students[], int numofstudents, int& student_tracker)
{

    ifstream fin;// input file
    char infile_name[40];// file name
    // prompt and read in for file name
    cout << "Enter file name: ";
    cin >> infile_name;
    fin.open(infile_name);// opens the file
    if (fin.fail())// checks if the file failed to open
    {
        cout << "Error: file could not be opened\n";
        return;
    }
    // reads in trackers for the loops
    fin >> coursetracker;
    fin >> student_tracker;
    fin.ignore();
    // read in course variables
    for (int i = 0; i < coursetracker; i++)
    {
        fin.getline(courses[i].CourseID, 9);
        fin.getline(courses[i].Title, 31);
        fin.getline(courses[i].Department, 31);
        fin >> courses[i].numenrolled;
        fin.ignore();
        //reads in enrolled students
        for (int x = 0; x < courses[i].numenrolled; x++)
        {
            fin.getline(courses[i].enrolled[x].uID, 6);
            fin.getline(courses[i].enrolled[x].name, 12);
            fin.getline(courses[i].enrolled[x].major, 12);
            fin >> courses[i].gradelist[x].numofgrades;
            fin.ignore();
            // reads in each grade for each student
            for (int y = 0; y < courses[i].gradelist[x].numofgrades; y++)
            {
                fin >> courses[i].gradelist[x].coursegrades[y];
            }
            fin.ignore();

        }


    }

    // reads in the student variables
    for (int j = 0; j < student_tracker; j++)
    {
        fin.getline(students[j].uID, 6);
        fin.getline(students[j].name, 12);
        fin.getline(students[j].major, 12);
        fin >> students[j].numofcourses;
        fin.ignore();
    }

    cout << "Data successfully initialized from: " << infile_name << endl;
    fin.close();// closes the file
    cout << "Input file closed: " << infile_name << endl;
    return;
}

