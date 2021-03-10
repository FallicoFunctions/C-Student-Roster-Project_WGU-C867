//
//  student.cpp
//  Nicholas Fallico - Scripting and Programming - Applications – C867 - Performance Assesment
//
//  Created by Nick on 1/14/21.
//

#include <stdio.h>
#include "student.h"
#include "roster.h"

Student::Student() //Parameterless constructor sets to default values
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    //for (int i = 0; i < 5; i++) this->age = 0;
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
}


Student::~Student() {} //Destructor

std::string Student::getStudentID() { return this->studentID; }
std::string Student::getFirstName() { return this->firstName; }
std::string Student::getLastName() { return this->lastName; }
std::string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(std::string studentID) { this->studentID = studentID; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastname(std::string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[])
{
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::printHeader() //Use to print header
{
    std::cout << "Output format: Student ID|First Name|Last Name|Email Address|Age|Days In Course|Degree Program\n";
}

void Student::print()
{
    std::cout << this->getStudentID() << '\t'; //Tab
    std::cout << this->getFirstName() << '\t'; 
    std::cout << this->getLastName() << '\t';
    std::cout << this->getEmailAddress() << '\t';
    std::cout << this->getAge() << '\t';
    std::cout << this->getDaysInCourse()[0] << ',';
    std::cout << this->getDaysInCourse()[1] << ',';
    std::cout << this->getDaysInCourse()[2] << '\t';
    std::cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; //Degree Program to string
}
