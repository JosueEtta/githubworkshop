#include <iostream>
#include <string>

using namespace std;


class Course{
   public:
   string courseName;
   int coef;
   float courseMark;

   //Course()
};

class Student{
   public:
    string name;
    int mathScore;
    char grade;
    int courseOffer;
    string gender;
    Course* courses;


    Student(string name={0},int courseOffer=0,string gender={0}){
      this->name = name;
      this->courseOffer = courseOffer;
      this->gender = gender;
    }

    float average(){
     float TotalMark=0;
     int totalSum=0;
      for(int i=0;i<courseOffer;i++){
        TotalMark += courses[i].courseMark * courses[i].coef;
        totalSum += courses[i].coef;
      }
      return TotalMark/totalSum;
    }

};

int main()
{
    int numberOfStudents=0;
    cout << "\t===REPORT CARD===" << endl;
    cout << "Enter the number of students:";
    cin >> numberOfStudents;
    cout << "\n";
    Student* students = new Student[numberOfStudents];


    for(int i=0;i<numberOfStudents;i++){
        cout << "Student " << i+1 <<endl;
        cout << "Enter your name:";
        cin >> students[i].name;
        cout << "Enter the number of course you wish to offer:";
         cout << "Enter your gender:";
        cin >> students[i].gender;
        students[i].courses = new Course[students[i].courseOffer];
        cout << "\n";
        for(int j=0;j < students[i].courseOffer;j++){
            cout << "course" << j+1 << endl;
            cout << "Enter name for course:";
            cin >> students[i].courses[j].courseName;
            cout << students[i].courses[j].courseName;
            cout << "Enter it's coefficient:";
            cin >> students[i].courses[j].coef;
            cout << "Enter mark for the course:";
            cin >> students[i].courses[j].courseMark;
            cout << "\n";
        }
        cout << "\n";
    }
      cout << "Name\tGender\tNumber of Course\tAverage\n";
     for(int i=0;i < numberOfStudents;i++){
           cout<< students[i].name << "\t"<< students[i].gender<<"\t"<< students[i].courseOffer<<"\t"<<students[i].average();
           cout << "\n";
        }
    return 0;
}
