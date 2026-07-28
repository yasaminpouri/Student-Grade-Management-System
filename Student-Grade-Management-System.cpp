#include <iostream>
#include <string>
using namespace std; 

void showMenu()
{
    cout << "=========== Student Grade Management ===========\n";
    cout << "1. Add Student \n";
    cout << "2. Display All Students \n";
    cout << "3. Search Student \n";
    cout << "4. Edit Student \n";
    cout << "5. Delete Student \n";
    cout << "6. Exit \n";
    cout << "=================================================\n";
    cout << "Entewr your choice : \n";
}
struct Student
{
    string name;
    int studentId;
    float gpa;
};

int main()
{
    bool running = true;
    int choice;
    Student student[100];
    int count = 0;
    string searchName;

    while (running)
    {
        showMenu();
        cin >> choice;
        

        switch (choice)
        {
        case 1:
        {
            if (count < 100)
            {
            cout << "Enter name : ";
            cin.ignore();
            getline(cin, student[count].name);

            cout << "Enter student ID : ";
            cin >> student[count].studentId;

            cout << "Enter gpa : ";
            cin >> student[count].gpa;

            ++count;
            cout << "Student added successfully!\n";
            }
            else
            {
                cout << "Cannot add more than 100 student.\n";
            }
        }
            break;
        case 2:
        if(count == 0)
        {
            cout << "No student found.\n";
        }
        else
        {
        for (int i = 0; i < count; i++)
        {
            cout << "name : " << student[i].name << '\n';
            cout << "studentId : " << student[i].studentId << '\n';
            cout << "gpa : " << student[i].gpa << '\n';
        }
        }
            break;
        case 3:
        { 
            cout << "Enter the name : \n";
            cin.ignore();
            getline(cin, searchName);
            bool found = false;
            for (int i = 0; i < count; i++)
            {
            
                if (searchName == student[i].name)
                {
                    found = true;
                    cout << student[i].name << '\n';
                    cout << student[i].studentId << '\n';
                    cout << student[i].gpa << '\n';
                    break;
                }
            
                }
            if (!found)
            {
                cout << "not found!\n";
            }
        }
        
            break;
        case 4:
        {
            cout << "Enter the name : \n";
            cin.ignore();
            getline(cin, searchName);
            bool found = false;
            for (int i = 0; i < count; i++)
            {
            
                if (searchName == student[i].name)
                { 
                    found = true;
                    cout << "===== Edit Student =====\n";
                    cout << "1. Edit Name \n";
                    cout << "2. Edit Student ID \n";
                    cout << "3. Edit GPA \n";
                    cout << "4. Edit All Information\n";
                    cout << "========================\n";
                    cout << "Enter your choice : \n";
                    int yourChoice;
                    cin >> yourChoice;
                    switch (yourChoice)
                {
                case 1:
                {
                    cout << "Enter the name : ";
                    cin.ignore();
                    getline(cin, student[i].name);
                }
                    break;
                case 2:
                {
                   cout << "Enter the ID : ";
                   cin >> student[i].studentId; 
                }
                    break;
                case 3:
                {
                    cout << "Enter the gpa : "; 
                    cin >> student[i].gpa;
                }
                
                    break;
                case 4:
                {
                    cout << "Enter the name : ";
                    cin.ignore();
                    getline(cin, student[i].name);
                
                    cout << "Enter the ID : ";
                    cin >> student[i].studentId;

                    cout << "Enter the gpa : "; 
                    cin >> student[i].gpa;
                }
                    break;

                default:
                cout << "Enter a numper between 1 and 4!";
                    break;
                }
                break;
            }
            
        }
            if (!found)
            {
                cout << "not found!\n";
            }
    
        }

            break;
        case 5:
        { 
            cout << "Enter the name : \n";
            cin.ignore();
            getline(cin, searchName);
            bool found = false;
            for (int i = 0; i < count; i++)
            {
            
                if (searchName == student[i].name)
                {
                    found = true;
                for (int j = i; j < count - 1; j++)
                {
                    student[j] = student[j + 1];
                }
                --count;
                cout << "Student deleted successfully!\n";
                break;
                }
            
            }
            if (!found)
            {
                cout << "not found!\n";
            }

        }

            break;
        case 6:
            running  = false;
            break;

        default:
            cout << "Please enter a number between 1 and 6! \n";
            break;
        }


        
    }
    
}