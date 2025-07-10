#include <iostream>
#include <string>

using namespace std;

class Student{
   Course* courses;
   public:
    string name;
    int mathScore;
    char grade;
    int courseOffer;

    Student(string name,int courseOffer){
      this->name = name;
      this->courseOffer = courseOffer;
    }
    void displayInfo(){
      cout << "My name is " << name << endl;



};
class Course{
   public:
   string courseName;
   int courseId;
   int courseMark;

   Course(string courseName,string courseId,int courseMark){
    this->courseName = courseName;
    this->courseId = courseId;
    this->courseMark = courseMark;
   }

};

int main()
{
    cout << "===REPORT CARD===" << endl << endl;
    Student student1("Atabe",2);
    student1.displayInfo();
    return 0;
}
