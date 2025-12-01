#include<iostream>
#include<string>
using namespace std;
    
    const int MAX_EMP = 100;
    int ids[MAX_EMP];
    string names[MAX_EMP];
    string depts[MAX_EMP];
    int countEmp= 0;

void insertEmployee(int id, string name, string dept){
    if(countEmp >= MAX_EMP){
        cout<<"System full ! Cannot insert more employees."<<endl;
        return;
    }
    else{
        for (int i = 0; i < countEmp; i++)
        {
           if (ids[i] ==  id)
           {
             cout<<"Employee with ID "<<id<<"already exists...";
             return;
           }
        }
        ids[countEmp]= id;
        names[countEmp]= name;
        depts[countEmp] = dept;
        countEmp++;
        cout<<"Employee "<< countEmp<< " Inserted: ID "<<id <<", name=" <<name <<", Dept= "<<dept<<endl<<endl;
    }

}
void displayEmployees(){
    if(countEmp == 0){
        cout<<"          ==========    No Employee in the system   ========          "<<endl;
        return;
    }

    for (int i = 0; i < countEmp - 1; i++)
    {
        for (int j = 0; j < countEmp - i - 1; j++)
        {
           if (ids[j]> ids[j+1])
           {
             swap(ids[j] , ids[j+1]);
             swap(names[j] , names[j+1]);
             swap(depts[j] , depts[j+1]);
           }
           
        }
        
    }
    cout<<"            Employee in the system  "<<endl<<endl;
    for (int i = 0; i < countEmp; i++)
    {
        cout<<"ID: "<<ids[i]
        <<", Name: "<<names[i]
        <<", Department: "<<depts[i]
        <<endl<<endl;
    }
    cout<<"                 -------------------------------------------------"<<endl<<endl;
}

void SearchById(int id){
    for (int i = 0; i < countEmp; i++)
    {
        if (ids[i] == id)
        {
            cout<<"Employee Found: ID: "<<ids[i]
            <<", Name: "<<names[i]
            <<", Department: "<<depts[i]
            <<endl<<endl;
            return;
        }
        
    }
    cout<<"Employee with ID: "<<id<<" not found..."<<endl;
    
}

void SearchByName(string name){
    for (int i = 0; i < countEmp; i++)
    {
       if (names[i] == name)
       {
         cout<<"Employee Found: ID= "<<ids[i]
         <<", Name= "<<names[i]
         <<", Department: "<<depts[i]<<endl<<endl;
         return;
       }
       
    }
    cout<<"Employee with name: "<<name<<" not found..."<<endl<<endl;
    
}

void DeleteEmployee(int id){
    for (int i = 0; i < countEmp; i++)
    {
        if (ids[i] == id)
        {
            for (int j = 0; j < countEmp -1 ; j++)
            {
                ids[j] = ids[j+1];
            }
            countEmp--;
            cout<<"Employee with ID= "<<id<<" Deleted Successfully...."<<endl;
            return; 
        }
        
    }
    cout<<"Employee with ID= "<<id <<"Not found...."<<endl;
}
int main(){
    system("cls");
    cout<<"             EMPLOYEE MANAGEMENT SYSTEM: "<<endl<<endl<<endl;
cout<<"     .....INSERTION....."<<endl<<endl<<endl;
insertEmployee(101, "Ahmed", "HR");
insertEmployee(102, "Ilsa", "HR");
insertEmployee(103, "Furqan", "Finance");

displayEmployees();

cout<<"    ....Search By ID....."<<endl<<endl;
SearchById(102);
cout<<"     ....Search By Name....."<<endl<<endl;
SearchByName("Hassan");

cout<<"     ....Delete with ID....."<<endl<<endl;
DeleteEmployee(101);
displayEmployees();
return 0;
}