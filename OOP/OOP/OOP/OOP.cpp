#include <iostream>
using std::string;

class AbstractEmployee {
public:
    virtual void AskForPromotion() = 0;
    virtual ~AbstractEmployee() = default; // important for cleanup
};

class Employee : public AbstractEmployee {
protected:
    string Name;
    string Company;
    int Age;

public:
    Employee(string Name, string Company, int Age) {
        this->Name = Name;
        this->Company = Company;
        this->Age = Age;
    }

    void Introduce() {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    void setName(string name) { Name = name; }
    string getName() { return Name; }

    void setCompany(string company) { Company = company; }
    string getCompany() { return Company; }

    void setAge(int age) { if (age >= 18) Age = age; }
    int getAge() { return Age; }

    void AskForPromotion() override {
        if (Age > 30)
            std::cout << Name << " got a promotion!" << std::endl;
        else
            std::cout << Name << " didn't get a promotion!" << std::endl;
    }

    virtual void Work() {
        std::cout << Name << " is working..." << std::endl;
    }
};

class Developer : public Employee {
public:
    string favProgLanguage;

    Developer(string name, string company, int age, string favProgLanguage)
        : Employee(name, company, age) {
        this->favProgLanguage = favProgLanguage;
    }

    void Work() override {
        std::cout << Name << " is coding in " << favProgLanguage << std::endl;
    }
};

class Teacher : public Employee {
public:
    string subject;

    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age) {
        this->subject = subject;
    }

    void Work() override {
        std::cout << Name << " is teaching " << subject << std::endl;
    }
};

int main() {
    Teacher e("Balint", "Jane Street", 20, "C#");
    Developer d("John", "Morgan Stanley", 25, "C++");

    Employee* e1 = &e;
    Employee* e2 = &d;

    e1->Work();
    e2->Work();
}
