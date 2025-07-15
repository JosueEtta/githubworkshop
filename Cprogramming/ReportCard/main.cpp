
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Course {
public:
    string courseName;
    int coef;
    float courseMark;
};

class Student {
public:
    string name;
    int courseOffer;
    string gender;
    Course* courses;

    // Constructor
    Student(string name = "", int courseOffer = 0, string gender = "") {
        this->name = name;
        this->courseOffer = courseOffer;
        this->gender = gender;
        courses = nullptr; // Initialize courses to nullptr
    }

    // Destructor to free dynamically allocated memory
    ~Student() {
        delete[] courses;
    }

    // Function to calculate the average
    float average() {
        float totalMark = 0;
        int totalCoef = 0;

        for (int i = 0; i < courseOffer; i++) {
            totalMark += courses[i].courseMark * courses[i].coef;
            totalCoef += courses[i].coef;
        }

        // Avoid division by zero
        if (totalCoef == 0) {
            return 0;
        }

        return totalMark / totalCoef;
    }
    //Creat csv file for the student
    void writeDefaultTemplate(){
       ofstream file;
       file.open(this->name + ".csv");

       if(file.is_open()){
         file << "Report CARD" << endl;
         file << "Name:" << "," << this->name << endl;
         file << "Gender:" << "," << this->gender <<endl;
         file << "Number of course:" << "," <<this->courseOffer << endl << endl;
         file << "Course" << "," << "Coefficient" << "mark" << endl;
          for(int i=0;i<this->courseOffer;i++){
           file << courses[i].courseName << "," << courses[i].coef << "," << courses[i].courseMark << endl;
          }
         file << "\n";
         file << "Average:" << "," << this->average() << endl;
          }
        else{
            cout << "Unable to open file";
        }
       }
};


int main() {
    int numberOfStudents = 0;

    cout << "\t=== REPORT CARD ===" << endl;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    // Dynamically allocate memory for students
    Student* students = new Student[numberOfStudents];

    for (int i = 0; i < numberOfStudents; i++) {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Enter your name: ";
        cin >> students[i].name;

        cout << "Enter your gender: ";
        cin >> students[i].gender;

        cout << "Enter the number of courses you wish to offer: ";
        cin >> students[i].courseOffer;

        // Dynamically allocate memory for courses
        students[i].courses = new Course[students[i].courseOffer];

        for (int j = 0; j < students[i].courseOffer; j++) {
            cout << "\nCourse " << j + 1 << endl;

            cout << "Enter name for course: ";
            cin >> students[i].courses[j].courseName;

            cout << "Enter its coefficient: ";
            cin >> students[i].courses[j].coef;

            cout << "Enter mark for the course: ";
            cin >> students[i].courses[j].courseMark;
        }
        students[i].writeDefaultTemplate();
    }
    /*ofstream result;
    result.open("result.csv");*/
    // Display report card
    cout << "\nName\tGender\tNumber of Courses\tAverage\n";
    for (int i = 0; i < numberOfStudents; i++) {
        cout << students[i].name << "\t" << students[i].gender << "\t" << students[i].courseOffer
             << "\t\t" << students[i].average() << endl;
        //result << students[i].name << "," << students[i].gender << "," <<  students[i].courseOffer << "," << students[i].average()  << endl;
    }

    // Free dynamically allocated memory
    delete[] students;

    return 0;
}
