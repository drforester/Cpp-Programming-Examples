/*
one way to do it using the STL
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::copy_if

using std::cout;
using std::string;
using std::vector;


class Person {
private:
    string firstname;
    string middlename;
    string lastname;
    int    age;
    string gender;
    bool   isLinuxUser;
public:
    Person (string firstname, string middlename, string lastname,
            int age, string gender, bool isLinuxUser);
    string get_gender() const;
    bool   get_usesLinux() const;
    void   printPerson() const;
    
};

Person::Person(string fn, string mn, string ln, int a, string gd, bool lu) {
    firstname = fn;
    middlename = mn;
    lastname = ln;
    age = a;
    gender = gd;
    isLinuxUser = lu;
}

string Person::get_gender() const {
    return gender;
}

bool Person::get_usesLinux() const {
    return isLinuxUser;
}

void Person::printPerson() const {
    if (middlename != "")
        cout << firstname << " " << middlename << " " << lastname << ", " << age << '\n';
    else
        cout << firstname << " " << lastname << ", " << age << '\n';
        
}


bool is_femaleLinuxUser(Person p);

int main()
{
    Person p1 = Person("Yuko", "", "Oshima", 29, "female", true);
    Person p2 = Person("Andre", "Ali", "Ankrya", 54, "male", true);
    Person p3 = Person("Anushka", "", "Sharma", 41, "female", true);
    Person p4 = Person("Yuki", "", "Hitoshi",33, "male", true);
    Person p5 = Person("Astrid", "Freedom", "Futurix", 5, "female", true);
    Person p6 = Person("Norman", "Nope", "Normal", 77, "male", false);
    Person p7 = Person("Ursula", "Anne", "Blumenthal", 76, "female", false);
    Person p8 = Person("John", "Joel", "Johnson", 53, "male", false);
    Person p9 = Person("Samuel", "Sad", "Samuelson", 41, "male", false);

    vector<Person> people = {p1, p2, p3, p4, p5, p6, p7, p8, p9};

    // copy female Linux users from the vector people to the vector femaleLinuxUsers
    vector<Person> femaleLinuxUsers;
    std::copy_if(people.cbegin(), people.cend(), std::back_inserter(femaleLinuxUsers),
                 is_femaleLinuxUser);
    
    for (auto& e:femaleLinuxUsers)
        e.printPerson();


}


bool is_femaleLinuxUser(Person p) {
    return (p.get_gender() == "female") && (p.get_usesLinux());
}
