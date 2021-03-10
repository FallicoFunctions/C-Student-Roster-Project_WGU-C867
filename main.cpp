//
//  main.cpp
//  Nicholas Fallico - Scripting and Programming - Applications – C867 - Performance Assesment
//
//  Created by Nick on 1/14/21.
//

#include <iostream>
#include "roster.h"
#include "student.h"

int main()
{
    // Student Data to parse
    const std::string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Nick,Fallico,nfalli1@wgu.edu,27,40,33,37,SOFTWARE"
    };
        
    const int numStudents = 5;
    Roster roster;
    
    std::cout << "Scripting and Programming - Applications – C867, C++, Student ID: 001305175, Nicholas Fallico." << std::endl << std::endl;
    
    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]); //Display all students
    std::cout << "Displaying all students: " << std::endl;
    roster.printAll();
    std::cout << std::endl;
    
    std::cout << "Displaying students with invalid emails" << std::endl;
    roster.printInvalidEmails();
    std::cout << std::endl;
    
    std::cout << "Displaying averages days in course: " << std::endl;
    roster.printAverageDaysInCourse("");
    std::cout << std::endl;
    
    std::cout << "Displaying by Degree Program: SOFTWARE" << std::endl; //Print students in SOFTWARE program
    roster.printByDegreeProgram(SOFTWARE);
    
    std::cout << "Removing student with ID A3:" << std::endl; //Removing student A3
    roster.remove("A3"); //Print All built into remove function as final command
    std::cout << std::endl;
        
    std::cout << "Removing student with ID A3:" << std::endl; //Attempting to remove student A3 after it has already been removed
    roster.remove("A3");
    std::cout << std::endl;
    
    return 0;
}
