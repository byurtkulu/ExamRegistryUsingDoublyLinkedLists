//
//  StudentList.cpp
//  ExamRegistryUsingDoublyLinkedLists
//
//  Created by Bahadır Yurtkulu on 11/03/2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
#include "strutils.h"
#include "StudentList.h"


StudentList::StudentList() {
    
    head = new studentNode;
    tail = head;
}

bool StudentList::isExist(string studentName) {
    
    studentNode * temp;
    temp = head;
    while (temp != NULL) {
        if (temp->userName == studentName) {
            return true;
        }
        
        temp = temp->down;
    }
    
    return false;
}

void StudentList::addExam(string userName, string courseName, int grade) {
    
    studentNode * tempStu;
    tempStu = head;
    if (isExist(userName)) {
        
        while (tempStu != NULL) {
            if (tempStu->userName == userName) {
                examNode * tempExamLead;
                examNode * tempExamTail = nullptr;
                tempExamLead = tempStu->headExamList;
                
                if (tempExamLead == NULL) {
                    tempStu->headExamList = new examNode(courseName, grade, NULL);
                    cout << "Exam for " << courseName << " with grade " << grade << " is added for " << userName << ".\n";
                    return;
                }
                
                while (tempExamLead != NULL) {
                    tempExamTail = tempExamLead;
                    tempExamLead = tempExamLead->next;
                }
                tempExamTail->next = new examNode(courseName, grade, NULL);
                cout << "Exam for " << courseName << " with grade " << grade << " is added for " << userName << ".\n";
                return;
            }
            tempStu = tempStu->down;
        }
    }
    
    else {
        while (tempStu->down != NULL) {
            if (userName.compare(tempStu->down->userName) < 0) {
                studentNode * newNodePtr;
                newNodePtr = new studentNode(userName, NULL, tempStu->down, tempStu);
                tempStu->down->up = newNodePtr;
                tempStu->down = newNodePtr;
                cout << "A new student with user name " << userName << " has been added.\n";
                
                // add exams
                newNodePtr->headExamList = new examNode(courseName, grade, NULL);
                cout << "Exam for " << courseName << " with grade " << grade << " is added for " << userName << ".\n";
                return;
            }
            tempStu = tempStu->down;
        }
        
        tempStu->down = new studentNode(userName, NULL, NULL, tempStu);
        cout << "A new student with user name " << userName << " has been added.\n";
        tempStu = tempStu->down;
        tail = tempStu;
        
        // add exams
        tempStu->headExamList = new examNode(courseName, grade, NULL);
        cout << "Exam for " << courseName << " with grade " << grade << " is added for " << userName << ".\n";
    }
}

void StudentList::deleteStudent(string userName) {
    
    studentNode * tempLead;
    studentNode * tempTail;
    
    tempTail = head;
    tempLead = head;
    tempLead = tempLead->down;
    
    while (tempLead != NULL) {
        
        if (tempLead->userName == userName && tempLead->down != NULL) {
            
            tempTail->down = tempLead->down;
            tempLead->down->up = tempTail;
            tempLead->up = NULL;
            tempLead->down = NULL;
            cout << "Student " << userName << " is succesfully removed.\n";
            return;
        }
        
        else if (tempLead->userName == userName && tempLead->down == NULL) {
            
            tail = tempTail;
            tempLead->up = NULL;
            tempTail->down = NULL;
            cout << "Student " << userName << " is succesfully removed.\n";
            return;
        }
        
        tempTail = tempTail->down;
        tempLead = tempLead->down;
    }
    
    cout << "Student does not exist!\n";
    
}

void StudentList::printStudent(string userName) {
    
    studentNode * tempStu;
    examNode * tempExam;
    
    tempStu = head;
    
    while (tempStu != NULL) {
        
        if (tempStu->userName == userName) {
            
            cout << "\n" << userName << '\n';
            cout << "---------------\n";
            
            tempExam = tempStu->headExamList;
            while (tempExam != NULL) {
                cout << tempExam->courseName << ": " << tempExam->grade << '\n';
                tempExam = tempExam->next;
            }
            return;
        }
        
        tempStu = tempStu->down;
    }
    cout << "\nStudent '" << userName << "' does not exist.\n";
    
}

void StudentList::printAllAZ() {
    
    if (head->down == NULL) {
        cout << "\nStudent list is empty.\n";
        return;
    }
    
    studentNode * tempStu = head;
    tempStu = tempStu->down;
    while (tempStu != NULL) {
        printStudent(tempStu->userName);
        tempStu = tempStu->down;
    }
}

void StudentList::printAllZA() {
    
    studentNode * tempStu = tail;
    
    while (tempStu->up != NULL) {
        printStudent(tempStu->userName);
        tempStu = tempStu->up;
    }
}

void StudentList::deleteAll() {
    
    while (tail->up != NULL) {
        tail = tail->up;
        delete tail->down;
    }
    tail = NULL;
    delete head;
}





