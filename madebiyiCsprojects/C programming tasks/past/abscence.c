// Includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: attendance.c
Functions: main, count_absence, check_absence.
Parameters: Array of strings.
Returns: int.
Description: Reads in an array of student presence records and outputs 0 or 1 depending on their absence count.
Author: Patricija Shalkauskaite
Date: 11-11-2021
*/

// Initialising function(s).
int count_absence(char *student, int record_length);
int check_absence(int absence_count);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int student_length = argc - 1;  // It's - 1 so program name isn't counted.
    char *students[student_length];  // Pointer to characters (records of student's presence).

    for(int i = 0; i < student_length; ++i)  // Creating array of students' presences.
    {
        students[i] = argv[i + 1];
    }

    for(int i = 0; i < student_length; ++i)  // Iterate through each student and call absence functions.
    {
        int absence_count = count_absence(students[i], strlen(students[i]));
        printf("%d\n", check_absence(absence_count));
    }

    return(0);
}

// Building initialised fuction(s).
int count_absence(char *student, int record_length)
{
    // Defining variables.
    int absence_count = 0;

    for(int i = 0; i < record_length; ++i)  // Iterate through the student's presence record.
    {
        if(student[i] == 'A')  // Check if student has been absent and increment count if so.
        {
            absence_count += 1;
        }
    }

    return absence_count;
}

int check_absence(int absence_count)
{
    if(absence_count > 2)
    {
        return 0;
    }

    else  // Absence count will be less than or equal to 2.
    {
        return 1;
    }
}
