//
//  main.cpp
//  ExamRegistryUsingDoublyLinkedLists
//
//  Created by Bahadır Yurtkulu on 10/03/2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include "strutils.h"
#include "StudentList.h"

using namespace std;



void loadFromFile(StudentList &studentList) {
    
    string fileName;
    string line;
    string studentName, courseName;
    int grade;
    ifstream file;
    
    cout << "Enter the File Name: \n";
    cin >> fileName;
    
    file.open(fileName);
    while (file.fail()) {
        cout << "Oops! Could not open. Enter the name again: \n";
        file.clear();
        cin >> fileName;
        file.open(fileName);
    }
    cout << '\n';
    while (getline(file, line)) {
        istringstream iss(line);
        iss >> studentName >> courseName >> grade;
        studentList.addExam(studentName, courseName, grade);
    }
    
    cout << "File has been processed.\n";
}




void printChoiceTable() {
    cout << "Exam Grades\n";
    cout << "--------------------------------\n";
    cout << "Please select one option [1..7]:\n";
    cout << "1. Load information from a file\n";
    cout << "2. Add student and exam manually\n";
    cout << "3. Delete a student\n";
    cout << "4. Display exam grades of a student\n";
    cout << "5. Display exam grades of all students in alphabetical order\n";
    cout << "6. Display exam grades of all students in reverse alphabetical order\n";
    cout << "7. Exit\n";
    cout << "Your choice:\n";
}





int main() {
    
    StudentList studentList;
    
    string studentName, courseName, choiceStr;
    int choice, grade;
    
    printChoiceTable();
    
    cin >> choiceStr;
    choice = atoi(choiceStr);
    
    
    while(true) {
        
        if (choice == 1) {
            loadFromFile(studentList);
            
            cout << '\n';
            cout << '\n';
            printChoiceTable();
            cin >> choiceStr;
            choice = atoi(choiceStr);
        }
        
        else if (choice == 2) {
            cout << "Student Name:\n";
            cin >> studentName;
            cout << "Course Name: \n";
            cin >> courseName;
            cout << "Grade[0-100]: \n";
            cin >> grade;
            while (grade > 100 || grade < 0) {
                cout << "Grade must be between [0-100] range: \n";
                cin >> grade;
            }
            
            studentList.addExam(studentName, courseName, grade);
            
            cout << '\n';
            cout << '\n';
            printChoiceTable();
            cin >> choiceStr;
            choice = atoi(choiceStr);
        }
        
        else if (choice == 3) {
            
            cout << "Student Name: \n";
            cin >> studentName;
            studentList.deleteStudent(studentName);
            
            cout << '\n';
            cout << '\n';
            printChoiceTable();
            cin >> choiceStr;
            choice = atoi(choiceStr);
        }
        
        else if (choice == 4) {
            
            cout << "Student Name: \n";
            cin >> studentName;
            studentList.printStudent(studentName);
            
            cout << '\n';
            cout << '\n';
            printChoiceTable();
            cin >> choiceStr;
            choice = atoi(choiceStr);
        }
        
        else if (choice == 5) {
            
            cout << "Printing all students in reverse alphabetical order.\n";
            studentList.printAllAZ();
            
            cout << '\n';
            cout << '\n';
            printChoiceTable();
            cin >> choiceStr;
            choice = atoi(choiceStr);
        }
        
        else if (choice == 6) {
            
            cout << "Printing all students in reverse alphabetical order.\n";
            studentList.printAllZA();
            
            cout << '\n';
            cout << '\n';
            printChoiceTable();
            cin >> choiceStr;
            choice = atoi(choiceStr);
        }
        
        else if (choice == 7) {
            cout << "Exiting...\n";
            studentList.deleteAll();
            exit(0);
        }
        
        else {
            cout << "Invalid choice! Please choose a valid option:\n";
            
            cin >> choiceStr;
            choice = atoi(choiceStr);
        }
    }
    
    return 0;
}
