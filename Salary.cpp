#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

//Implementation of Hierarchical Inheitance 
//One Base Class Person and two child class Student and Staff

//Base class Person Starts
class Person
{
    //Private Data Members to store the name and address
    private:
    string name;
    string address;
    
    //Public Member Functions
    public:
    	
    //Parameterized constructor to initialize the members
    Person(string name, string address)
    {
        this->name = name;
        this->address = address;
    }
    
    //Accessor Method for Name and address
    string getName()
    {
        return name;
    }
    
    string getAddress()
    {
        return address;
    }
    
    //Mutator Method for Address
    void setAddress(string address)
    {
        this->address = address;
    }
    
    //Display function to display the properties
    void display()
    {
        cout << "The Name of the Person is: " << name << endl;
        cout << "The Address of the Person is: " << address << endl;
    }
};  //end of the Base class

//First child CLass inheriting Base Class
class Student:public Person
{
    //Private Data Members to store the program year & fee
    private:
    	
    string program;
    int year;
    double fee;
    
    //Member Functions
    public:
    	
    //Parameterized constructor to initialize the members
    Student(string name, string address, string program, int year, double fee):Person(name, address)
    {
        this->program = program;
        this->year = year;
        this->fee = fee;
    }
    
    //Accessor & Mutator Method for each of the Properties
    string getProgram()
    {
        return program;
    }
    
    void setProgram(string program)
    {
        this->program = program;
    }
    
    int getYear()
    {
        return year;
    }
    
    void setYear(int year)
    {
        this->year = year;
    }
    
    double getFee()
    {
        return fee;
    }
    
    void setFee(double fee)
    {
        this->fee = fee;
    }
    
    //Display Function to show each of the Properties
    void display()
    {
        Person::display();      //call the display function of Base class
        cout << "The Program Enrolled by the Student : " << program << endl;
        cout << "The Number of Year for the Student : " << year << endl;
        cout << "The Fees of the Course enrolled by Student : " << fixed << setprecision(2) << fee << endl;
    }
};  //End of the child class

//Second child CLass inheriting Base Class
class Staff : public Person
{
    //Private Data Members to store the pay & School Name
    private:
    	
    string school;
    double pay;
    
    //Member Functions
    public:
    	
    //Parameterized constructor to initialize the members
    Staff(string name, string address, string school, double pay):Person(name, address)
    {
        this->school = school;
        this->pay = pay;
    }
    
    //Accessor and Mutator Method for Each of the Fields
    string getSchool()
    {
        return school;
    }
    
    void setSchool(string school)
    {
        this->school = school;
    }
    
    double getPay()
    {
        return pay;
    }
    
    void setPay(double pay)
    {
        this->pay = pay;
    }
    
    //Display function to shoew each of the Properties
    void display()
    {
        Person::display();      //call the display function of Base class
        cout << "The School of the Staff is : " << school << endl;
        cout << "The Pay of the Staff is : " << fixed << setprecision(2) << pay << endl;
    }
};  //end of the Child class

//Driver Code
int main()
{
    //Declare two Objects of Students and call the Parameterized constructor of Student class
    Student stu1("Wendy Miller", "222 S Caroline Street, Middleton", "Artificial Intelligence", 4, 237890.78);
    Student stu2("Liam Johnson", "1824 12th Ave, Port Huron", "Software Development", 3, 0);
    
    //Get the Fees of the First Student;
    double Fees = stu1.getFee();
    //Increment by 10 % to the Fees`
    Fees = Fees + Fees * 0.10;
    //Set the Fees of the Second Student
    stu2.setFee(Fees);
    
    //Print the Details of the Two Students
    cout << "***First Student Details*** " << endl;
    stu1.display();
    cout << "***Second Student Details*** " << endl;
    stu2.display();
    
    cout << endl << endl;
    //Determine which of the two Objects has Greater Fees
    if(stu1.getFee()>=stu2.getFee())
    {
        cout << "The student in the " << stu1.getProgram() << " course has the Highest Fees " << endl;
    }
    else
    {
        cout << "The student in the " << stu2.getProgram() << " course has the Highest Fees " << endl;
    }
    
    
    //Declare Three Object of Staff and call the Parameterized constructor of Staff class
    Staff Staff1("Nicole Crawford", "6680 Yount Street, California", "Charter ", 45000.56);
    Staff Staff2("Gerald Murphy", "61 Franklin Ln, New Jersey", "Indiana ", 35450.34);
    Staff Staff3("Luna White", "6245 Amanda Clearpot Road, Ohio", "Lawrence ", 56897.98);
    
    //Print the Details of the Three Staffs
    cout << endl;
    cout << "***First Staff Details*** " << endl;
    Staff1.display();
    cout << endl;
    cout << "***Second Staff Details*** " << endl;
    Staff2.display();
    cout << endl;
    cout << "***Third Staff Details*** " << endl;
    Staff3.display();
    
    //Determine and display the Average Pay for the three Staff
    double averagePay = (Staff1.getPay() + Staff2.getPay() + Staff3.getPay())/3.0;
    cout << "\nThe Average Pay of the three Staff is : " << fixed << setprecision(2) << averagePay << endl;

    return 0;
}
