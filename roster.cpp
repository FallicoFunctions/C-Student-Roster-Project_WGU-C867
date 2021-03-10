//
//  roster.cpp
//  Nicholas Fallico - Scripting and Programming - Applications – C867 - Performance Assesment
//
//  Created by Nick on 1/14/21.
//

#include <stdio.h>
#include "roster.h"
#include "student.h"

void Roster::parse(std::string studentData)
{
    DegreeProgram degreeProgram = SECURITY; //Default Value
    if (studentData.back() == 'K') degreeProgram = NETWORK; //Last character in student data string tells us the degree program
    else if (studentData.back() == 'E') degreeProgram = SOFTWARE;
    
    //rhs = right hand side
    int rhs = studentData.find(","); //Find the comma
    std::string studentID = studentData.substr(0, rhs); //Extracting sunstring in front of comma for student ID
    
    //lhs = left hand side
    int lhs = rhs + 1; //Move past the previous comma
    rhs = studentData.find(",", lhs);
    std::string firstName = studentData.substr(lhs, rhs - lhs); //Get first name
    
    lhs = rhs + 1; //Move past the previous comma
    rhs = studentData.find(",", lhs);
    std::string lastName = studentData.substr(lhs, rhs - lhs); //Get last name
    
    lhs = rhs + 1; //Move past the previous comma
    rhs = studentData.find(",", lhs);
    std::string emailAddress = studentData.substr(lhs, rhs - lhs); //Get email address
    
    lhs = rhs + 1; //Move past the previous comma
    rhs = studentData.find(",", lhs);
    int age = stod(studentData.substr(lhs, rhs - lhs)); //Get age
    
    lhs = rhs + 1; //Move past the previous comma
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stod(studentData.substr(lhs, rhs - lhs)); //Get days in course 1
    
    lhs = rhs + 1; //Move past the previous comma
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stod(studentData.substr(lhs, rhs - lhs)); //Get days in course 2
    
    lhs = rhs + 1; //Move past the previous comma
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stod(studentData.substr(lhs, rhs - lhs)); //Get days in course 3
    
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int daysInCourseArray[3] = { daysInCourse1,daysInCourse2,daysInCourse3 }; //Puts days into array for constructor
    
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram); //Create new Student object
}

void Roster::remove(std::string studentID) //Remove student by student ID
{
    bool success = false; //Assume student is not here
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            success = true; //Student found
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[i]; //Swap with last student
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--; //Last student no longer visable
        }
    }
    if (success)
    {
        std::cout << studentID << " removed from roster." << std::endl << std::endl;
        std::cout << "Displaying all students" << std::endl;
        this->printAll(); //Display now current student roster
    }
    else std::cout << studentID << " not found." << std::endl << std::endl;
}

void Roster::printAll() //Display all students and their info
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) //Go through each student's info and print it out then tab over
    {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) //Prints average amount of days a student is in a course
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        std::cout << classRosterArray[i]->getStudentID() << ": ";
        std::cout << (classRosterArray[i]->getDaysInCourse()[0] +
                      classRosterArray[i]->getDaysInCourse()[1] +
                      classRosterArray[i]->getDaysInCourse()[2])/3.0 << std::endl;
    }
    std::cout << std::endl;
}

//Verifies student email addresses and displays all invalid email addresses to the user
void Roster::printInvalidEmails() //A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')
{
    bool any = false; //Assume all emails are valid
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        std::string isValidEmail = (classRosterArray[i]->getEmailAddress()); //Declare isValidEmail to each student's email and then check for validity
        if ((isValidEmail.find('@') == std::string::npos || isValidEmail.find('.') == std::string::npos) || isValidEmail.find(' ') != std::string::npos) //If email has '@' and "." then valid
        {
            {
                any = true;
                std::cout << isValidEmail << ":" << classRosterArray[i]->getStudentID() << std::endl;
            }
        }
    }
    if (any == false) std::cout << "NONE" << std::endl; //If there are no invalid emails print "NONE"
    
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) //Prints out student information for a degree program specified by an enumerated type
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    
    std::cout << std::endl;
}

Roster::~Roster()
{
    std::cout << "DESTRUCTOR CALLED" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        std::cout << "Deleting student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
