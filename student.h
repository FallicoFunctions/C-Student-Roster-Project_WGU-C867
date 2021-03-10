//
//  student.h
//  Nicholas Fallico - Scripting and Programming - Applications – C867 - Performance Assesment
//
//  Created by Nick on 1/14/21.
//

#ifndef student_h
#define student_h

#include <iostream>
#include <iomanip>
#include "degree.h"

class Student
{
public:
    const static int daysInCourseArraySize = 3;
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[daysInCourseArraySize];
    DegreeProgram degreeProgram;
public:
    Student(); //Paramaterless constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[daysInCourseArraySize], DegreeProgram degreeProgram); //Full constructor
    ~Student(); //Desctructor
    
    //Getters or Accessors
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
    //Setters or Mutators
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastname(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    static void printHeader(); //Displays header for data
    
    void print(); //Displays this student's data
};




#endif /* student_h */
