//
//  roster.h
//  Nicholas Fallico - Scripting and Programming - Applications – C867 - Performance Assesment
//
//  Created by Nick on 1/14/21.
//

#ifndef roster_h
#define roster_h

#pragma once
#include "degree.h"
#include "student.h"

class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 5;
    
public:
    Student* classRosterArray[numStudents];
    void parse(std::string row);
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};


#endif /* roster_h */
