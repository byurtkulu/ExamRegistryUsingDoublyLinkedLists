//
//  StudentList.hpp
//  ExamRegistryUsingDoublyLinkedLists
//
//  Created by Bahadır Yurtkulu on 11/03/2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//

#ifndef StudentList_h
#define StudentList_h

#include <stdio.h>
#include <iostream>
#include <string>


struct examNode
{
    string courseName;
    int grade;
    examNode * next;
    
    // Constructor
    examNode(string str, int i, examNode * n)
        :courseName(str), grade(i), next(n)
    {}
};

struct studentNode
{
    string userName;
    examNode * headExamList;
    studentNode * down;
    studentNode * up;
    
    // Default Constructor
    studentNode()
        :userName("@Mr. Nobody"), headExamList(NULL), down(NULL), up(NULL)
    {}
    
    // Constructor
    studentNode(string str, examNode * a, studentNode * d, studentNode * u)
        :userName(str), headExamList(a), down(d), up(u)
    {}
};

class StudentList
{
public:
    StudentList();
    void addExam(string userName, string courseName, int grade);
    void deleteStudent(string userName);
    void printStudent(string userName);
    void printAllAZ(); //alphabetical order display
    void printAllZA(); //reverse alphabetical order display
    
    void deleteAll(); //to deallocate all dynamic data
private:
    studentNode * head;
    studentNode * tail;
    bool isExist(string studentName);
    // any helper functions you see necessary
    // ...
};


#endif /* StudentList_h */
