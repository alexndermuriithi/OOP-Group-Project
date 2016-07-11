#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert> // assert()
class Humanbody{
public:
  enum BPart{HEAD, ABDOMEN, LIMBS, NPARTS};
  Humanbody(BPart id) : id(id){}
  friend std::ostream&
  operator<<(std::ostream&, const Humanbody&);
private:
  static std::string parts[NPARTS];
  BPart id;
};
//!NOTE: note the two constructs below and compare them in
//       `class personPart' above.
std::string Humanbody::parts[NPARTS] = {"Head","Abdomen", "Limbs"};
std::ostream&
operator<<(std::ostream& out, const Humanbody& person){
  return out << person.parts[person.id];
}
class Person{
  std::vector<Humanbody*> parts;
public:
  ~Person();
  void addPart(Humanbody* prt){ parts.push_back(prt); }
  friend std::ostream&
  operator<<(std::ostream&, const Person&);
};
//!NOTE: compare with above declaration
std::ostream&
operator<<(std::ostream& out, const Person& person){
  out << " has [";
  for(auto prt: person.parts) out << (*prt) << ' ';
  return out << ']';
}
class Birth{ //!NOTE: the `builder' class.
protected:
  Person* person;
public:
  Birth(): person(0){}
  void createPerson(){ person = new Person; }
  //!NOTE: below, we have pure virtual functions :)
  virtual void createHead() = 0;
  virtual void createAbdomen() = 0;
  virtual void createLimbs() = 0;
  virtual std::string getPersonName() const = 0;
  Person* getPerson(){
    Person* newperson = person;
    person = 0;
    return newperson;
  }
};
class Male : public Birth{
public:
  void createLimbs(){
    person->addPart(new Person(Person::LIMBS));
  }
  void createAbdomen(){}  //!NOTE: cups without lids
  void createHead(){}//!NOTE: cups without snouts
  std::string getPersonName() const{
    return "John";
  }
};
class BirthAfrican : public Birth{
  void createHead(){
    person->addPart(new Person(Person::HEAD));
  }
  void createAbdomen(){
    person->addPart(new Person(Person::ABDOMEN));
  }
  void buildSnout(){
    person->addPart(new Person(Person::LIMBS));
  }
  std::string getPersonName() const{
    return "Kimani";
  }
};
class Creator{
  Birth* builder;
public:
  Creator() : builder(0){}
  void setBuilder(Person* builder){
    this->builder = builder;
  }
  void make(){
    assert(builder);
    builder->createPerson();
    builder->createHead();
    builder->createAbdomen();
    builder->createLimbs();
  }
};
using namespace std;
Person *
makeAPerson(Creator& creator, Birth* pattern){
  creator.setBuilder(pattern);
  creator.make();
  Person* person = pattern->getPerson();
  cout << "Made a " << pattern->getPersonName() << endl;
  return person;
}
int main(){
  map<string, int> kitchen;
  kitchen["tumblers"] = 4;
  kitchen["persons"]     = 2;

  vector<Person*> containers;
  BirthAfrican* ba = new BirthAfrican;
  Male* m = new Male;
  Creator creator;
  map<string, int>::const_iterator cit = kitchen.begin();
  while(cit != kitchen.end()){
    Birth* pattern;
    if(cit->first == "tumblers")
      pattern = m;
    else if(cit->first == "persons")
      pattern = ba;
    for(int i = 0; i < cit->second; ++i)
      containers.push_back(makeAPerson(creator, pattern));
    ++cit;
  }
  delete m;
  delete ba;
  int i = 0;
  for(auto container: containers)
    cout << "Container " << i++
         << " " << (*container) << endl;
}
