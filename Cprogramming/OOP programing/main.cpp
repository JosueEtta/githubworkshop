#include <iostream>

using namespace std;

class Animal{
  public:
      string name;
      string family;
      Animal(string name,string family){
      this->name = name;
      this->family = family;
      }
      void info(){
        cout << "name :" << name << endl;
        cout << "family :" << family << endl;
      }
};

class wildAnimal : public Animal{
 public:
    wildAnimal(string name,string family= "Wild animal") : Animal(name,family){
    }

};

int main()
{
    wildAnimal wolf("wolf","canidae");
    wolf.info();
    return 0;
}
