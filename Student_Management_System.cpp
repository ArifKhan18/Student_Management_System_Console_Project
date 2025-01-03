#include <bits/stdc++.h>
#include <conio.h>
#include<fstream>
#include<windows.h>
using namespace std;
void mainlogin();
void cgpacal();
void view_all_cgpa();
/// -----------------------------------------------------------------Student Class------------------------------------------------------------------------
class Student
{
public:
    string Student_Name;
    string Student_Id;
    string Student_Section;
    string Student_Intake;
    string Student_Father_Name;
    string Student_Mother_Name;
    string Student_Mobile_Number;
    string Student_Present_address;
    vector<Student> students;
    void inputStudentData();
    void displayStudentData();
    void inputStudentDatacgpa();
    double calculateCGPA();
    vector<string> subject_names;
    vector<double> subject_cgpa;
    vector<double> subject_credit;

    bool operator==(const string &id) const
    {
        return Student_Id == id;
    }
};
/// -----------------------------------------------------------------Bool number function-----------------------------------------------------------------
bool isNumber(string &str)
{
    for (char &c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}
/// -----------------------------------------------------------------Input StudentData Function-----------------------------------------------------------
void Student::inputStudentData()
{

    cout << "\t\tEnter Student Name:\t";
    getline(cin, Student_Name);

    bool idExists = false;

    do
    {
        idExists = false;

        do
        {
            cout << "\t\tEnter Student ID:(only digits allowed):\t";
            getline(cin, Student_Id);

            if (!isNumber(Student_Id))
            {
                cout<<endl;
                cout << "Error:student id should contain only digits. Please enter a valid number." << endl;
                cout<<endl;
            }
        }
        while (!isNumber(Student_Id));
        ifstream inputFile("student_data.txt");
        if (inputFile.is_open())
        {
            string line;
            while (getline(inputFile, line))
            {
                if (line == Student_Id)
                {
                    idExists = true;
                    cout<<endl;
                    cout << "Error: Student ID already exists. Please provide a new ID." << endl;
                    cout<<endl;
                    break;
                }
            }
            inputFile.close();
        }
        else
        {
            ofstream createFile("student_data.txt");
            createFile.close();
        }

        if (!idExists)
        {
            cout << "\t\tEnter Student Section:\t";
            getline(cin, Student_Section);
            cout << "\t\tEnter Student Intake:\t";
            getline(cin, Student_Intake);

            cout << "\t\tEnter Father's Name:\t";
            getline(cin, Student_Father_Name);

            cout << "\t\tEnter Mother's Name:\t";
            getline(cin, Student_Mother_Name);

            do
            {
                cout << "\t\tEnter Mobile Number (only digits allowed):\t";
                getline(cin, Student_Mobile_Number);

                if (!isNumber(Student_Mobile_Number))
                {
                    cout<<endl;
                    cout << "Error: Mobile Number should contain only digits. Please enter a valid number." << endl;
                    cout<<endl;
                }
            }
            while (!isNumber(Student_Mobile_Number));

            cout << "\t\tEnter Present Address:\t";
            getline(cin, Student_Present_address);

            cout << endl;

            ofstream outputFile("student_data.txt", ios::app);
            if (outputFile.is_open())
            {
                outputFile << Student_Name << endl
                           << Student_Id << endl
                           << Student_Section << endl
                           << Student_Intake << endl
                           << Student_Father_Name << endl
                           << Student_Mother_Name << endl
                           << Student_Mobile_Number << endl
                           << Student_Present_address << endl
                           << endl;
                outputFile.close();
                cout << "Data saved to file." << endl << endl;
            }
            else
            {
                cout << "Error: Unable to open the file for writing." << endl;
            }
        }
    }
    while (idExists);
}
/// -----------------------------------------------------------------Display StudentData Function---------------------------------------------------------
void Student::displayStudentData()
{
    cout << "Student Name:    " << Student_Name << "\t\t";
    cout << "Student ID:      " << Student_Id << endl;
    cout << "Student Section: " << Student_Section << "\t\t\t";
    cout << "Student Intake:  " << Student_Intake << endl;
    cout << "Father's Name:   " << Student_Father_Name << "\t\t";
    cout << "Mother's Name:   " << Student_Mother_Name << endl;
    cout << "Mobile Number:   " << Student_Mobile_Number << "\t\t";
    cout << "Present Address: " << Student_Present_address << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}
/// -----------------------------------------------------------------Input StudentData cgpa Function------------------------------------------------------
void Student::inputStudentDatacgpa()
{

    int subject_number;
    cout << "Enter the number of subjects: ";
    cin >> subject_number;
    cout<<endl;
    for (int i = 0; i < subject_number; i++)
    {
        string subject_name;
        double subject_gpa, credit;

        cout << "Enter subject name for subject " << i + 1 << ": ";
        cin >> subject_name;
        subject_names.push_back(subject_name);

        cout << "Enter CGPA for subject " << i + 1 << ": ";
        cin >> subject_gpa;
        subject_cgpa.push_back(subject_gpa);

        cout << "Enter credit for subject " << i + 1 << ": ";
        cin >> credit;
        cout<<endl;
        subject_credit.push_back(credit);
    }
}
/// -----------------------------------------------------------------calculate CGPA Function--------------------------------------------------------------
double Student::calculateCGPA()
{
    double totalPoints = 0;
    double totalCredits = 0;

    for (int i = 0; i < subject_names.size(); i++)
    {
        totalPoints += subject_credit[i] * subject_cgpa[i];
        totalCredits += subject_credit[i];
    }

    if (totalCredits > 0)
    {
        double cgpa = totalPoints / totalCredits;
        return cgpa;
    }
    else
    {
        cout << "Total credits cannot be zero. CGPA calculation failed." << endl;
        return 0.0;
    }
}
/// -----------------------------------------------------------------Teacher Class------------------------------------------------------------------------
class Teacher
{
public:
    string Teacher_Name;
    string Teacher_Id;
    string Teacher_Mobile_Number;
    string Teacher_Present_address;
    vector<Teacher>teacher;
    void inputTeacherData();
    void displayTeacherData();
    bool operator==(const string &id) const
    {
        return Teacher_Id == id;
    }
};
/// -----------------------------------------------------------------Input TeacherData Function-----------------------------------------------------------
void Teacher::inputTeacherData()
{
    cout << "\t\tEnter Teacher Name:\t";
    getline(cin, Teacher_Name);

    bool idExists = false;

    do
    {
        idExists = false;

        do
        {
            cout << "\t\tEnter Teacher ID:(only digits allowed):\t";
            getline(cin, Teacher_Id);

            if (!isNumber(Teacher_Id))
            {
                cout<<endl;
                cout << "Error:Teacher id should contain only digits. Please enter a valid number." << endl;
                cout<<endl;
            }
        }
        while (!isNumber(Teacher_Id));
        ifstream inputFile("teacher_data.txt");
        if (inputFile.is_open())
        {
            string line;
            while (getline(inputFile, line))
            {
                if (line == Teacher_Id)
                {
                    idExists = true;
                    cout<<endl;
                    cout << "Error: Teacher ID already exists. Please provide a new ID." << endl;
                    cout<<endl;
                    break;
                }
            }
            inputFile.close();
        }
        else
        {
            ofstream createFile("teacher_data.txt");
            createFile.close();
        }

        if (!idExists)
        {
            do
            {
                cout << "\t\tEnter Mobile Number (only digits allowed):\t";
                getline(cin, Teacher_Mobile_Number);

                if (!isNumber(Teacher_Mobile_Number))
                {
                    cout<<endl;
                    cout << "Error: Mobile Number should contain only digits. Please enter a valid number." << endl;
                    cout<<endl;
                }
            }
            while (!isNumber(Teacher_Mobile_Number));

            cout << "\t\tEnter Present Address:\t";
            getline(cin, Teacher_Present_address);

            cout << endl;

            ofstream outputFile("teacher_data.txt", ios::app);
            if (outputFile.is_open())
            {
                outputFile << Teacher_Name << endl
                           << Teacher_Id << endl
                           << Teacher_Mobile_Number << endl
                           << Teacher_Present_address << endl
                           << endl;
                outputFile.close();
                cout << "Data saved to file." << endl << endl;
            }
            else
            {
                cout << "Error: Unable to open the file for writing." << endl;
            }
        }
    }
    while (idExists);
}
/// -----------------------------------------------------------------Display TeacherData Function---------------------------------------------------------
void Teacher::displayTeacherData()
{
    cout << "Teacher Name:    " << Teacher_Name << "\t\t";
    cout << "Teacher ID:      " << Teacher_Id << endl;
    cout << "Mobile Number:   " << Teacher_Mobile_Number << "\t\t";
    cout << "Present Address: " << Teacher_Present_address << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout<<endl;
}
/// -----------------------------------------------------------------View all cgpa Function---------------------------------------------------------------
void view_all_cgpa()
{
    ifstream cgpaInputFile("cgpa_data.txt");
    if (!cgpaInputFile.is_open())
    {
        cout << "No CGPA data available." << endl;
    }
    else
    {
        system("cls");
        cout << "\t\t\t================================================================\n";
        cout << "\t\t\t|              List of All Students CGPA ==>                   |\n";
        cout << "\t\t\t================================================================\n\n";
        string line;
        while (getline(cgpaInputFile, line))
        {
            cout << "Student Name: " << line << endl;
            getline(cgpaInputFile, line);
            cout << "Student ID: " << line << endl;
            getline(cgpaInputFile, line);
            cout << "CGPA: " << line << endl;
            getline(cgpaInputFile, line);
            cout << "-----------------" << endl;
        }
        cgpaInputFile.close();
    }
}
/// ------------------------------------------------------------------One student cgpa Function------------------------------------------------------------
void one_student_cgpa()
{
    string searchIdStudent;
    cout << "Enter the ID of the student: ";
    cin.ignore();
    getline(cin, searchIdStudent);

    ifstream cgpaInputFile("cgpa_data.txt");
    if (!cgpaInputFile.is_open())
    {
        cout << "No CGPA data available." << endl;
    }
    else
    {
        string studentId;
        string studentName;
        string cgpa;
        system("cls");
        cout << "\t\t\t================================================================\n";
        cout << "\t\t\t|              Student CGPA ==>                                |\n";
        cout << "\t\t\t================================================================\n\n";
        bool found = false;
        char chTemp;
        string StrTemp = "";
        while (getline(cgpaInputFile,  studentName))
        {
            getline(cgpaInputFile, studentId);
            getline(cgpaInputFile, cgpa);
            if(StrTemp[0] >= '0' && StrTemp[0] <= '9') studentName = StrTemp+studentName;
            StrTemp = "";
            cgpaInputFile >> noskipws >> chTemp;
            StrTemp += chTemp;
            if (studentId == searchIdStudent)
            {
                found = true;
                cout << "Student Name: " <<  studentName<< endl;
                cout << "Student ID: " << studentId << endl;
                cout << "CGPA: " << cgpa << endl;

                break;
            }
        }

        if (!found)
        {
            cout << "Student with ID " << searchIdStudent << " not found in CGPA records." << endl;
        }

        cgpaInputFile.close();
    }
}

/// ------------------------------------------------------------------project Function---------------------------------------------------------------------
void project()
{
    vector<Student> students;
    vector<Teacher> Teachers;
    string searchNamestudent;
    string searchNameteacher;
    Student STUDENTS;
    Teacher TEAcher;

    while (true)
    {
        cout<<"\t\t\t...................STUDENT MANAGEMENT SYSTEM....................\n";
        cout<<"\t\t\t================================================================\n";
        cout<<"\t\t\t| Press 1  to Add Student                                      |"<<endl;
        cout<<"\t\t\t| Press 2  to View All Students                                |"<<endl;
        cout<<"\t\t\t| Press 3  to Delete Student Data                              |"<<endl;
        cout<<"\t\t\t| Press 4  to Search Student                                   |"<<endl;
        cout<<"\t\t\t| Press 5  to CGPA Calculation                                 |"<<endl;
        cout<<"\t\t\t| Press 6  to View All Students with CGPA                      |"<<endl;
        cout<<"\t\t\t| Press 7  to Search Student with CGPA                         |"<<endl;
        cout<<"\t\t\t| Press 8  to Add Teacher Info                                 |"<<endl;
        cout<<"\t\t\t| Press 9  to View All Teachers Info                           |"<<endl;
        cout<<"\t\t\t| Press 10 to Delete Teacher                                   |"<<endl;
        cout<<"\t\t\t| Press 11 to Search Teacher                                   |"<<endl;
        cout<<"\t\t\t| Press 12 to Exit                                             |"<<endl;
        cout<<"\t\t\t================================================================\n\n";
        cout << "Enter your choice: ";

        string schoice;
        cin >> schoice;
        int choice;
        if (schoice != "1" && schoice != "2" && schoice != "3" && schoice != "4" && schoice != "5" && schoice != "6"
                && schoice != "7" && schoice != "8" && schoice != "9" && schoice != "10" && schoice != "11" && schoice != "12")
        {
            choice = 13;
        }
        else
        {
            if (schoice.length() == 1)
            {
                choice = schoice[0] - '0';
            }
            else
            {
                if (schoice == "10")
                {
                    choice = 10;
                }
                else if (schoice == "11")
                {
                    choice = 11;
                }
                else if (schoice == "12")
                {
                    choice = 12;
                }
            }
        }

        cout<<endl;

        switch (choice)
        {
        case 1:
        {
            cout << "how many added Number of Students: ";

            int number_of_students;
            cin>>number_of_students;
            cin.ignore();
            Student newStudent[number_of_students];
            for(int i=0; i<number_of_students; i++)
            {
                newStudent[i].inputStudentData();
                students.push_back(newStudent[i]);
            }
            system("cls");
            cout<<endl;
            cout<<"\t\t\t================================================================\n";
            cout<<"\t\t\t|               Student added successfully!!!!                 |\n";
            cout<<"\t\t\t================================================================\n\n";
            break;
        }
        case 2:
        {
            ifstream inputFile("student_data.txt");
            if (!inputFile.is_open())
            {
                cout << "No students added yet." << endl;
            }
            else
            {
                system("cls");
                cout << "\t\t\t================================================================\n";
                cout << "\t\t\t|              List of Students ==>                           |\n";
                cout << "\t\t\t================================================================\n\n";

                Student student;
                char chTemp;
                string StrTemp = "";
                while (getline(inputFile, student.Student_Name)
                        && getline(inputFile, student.Student_Id)
                        && getline(inputFile, student.Student_Section)
                        && getline(inputFile, student.Student_Intake)
                        && getline(inputFile, student.Student_Father_Name)
                        && getline(inputFile, student.Student_Mother_Name)
                        && getline(inputFile, student.Student_Mobile_Number)
                        && getline(inputFile, student.Student_Present_address))
                {
                    if(StrTemp[0] >= 'A' && StrTemp[0] <= 'z') student.Student_Name = StrTemp+student.Student_Name;
                    StrTemp = "";
                    inputFile >> noskipws >> chTemp;
                    StrTemp += chTemp;
                    student.displayStudentData();
                    cout << endl;
                }
                inputFile.close();
            }
            break;
        }
        case 3:
        {
            cout<<endl;
            cout << "Enter Student ID to Delete: ";
            string id;
            cin.ignore();
            getline(cin,id);
            cout << endl;

            ifstream inputFile("student_data.txt");
            ofstream tempFile("temp.txt");

            bool found = false;

            if (!inputFile.is_open())
            {
                cout << "No student data found." << endl;
            }
            else
            {
                Student student;
                char chTemp;
                string StrTemp = "";
                while (getline(inputFile, student.Student_Name)
                        && getline(inputFile, student.Student_Id)
                        && getline(inputFile, student.Student_Section)
                        && getline(inputFile, student.Student_Intake)
                        && getline(inputFile, student.Student_Father_Name)
                        && getline(inputFile, student.Student_Mother_Name)
                        && getline(inputFile, student.Student_Mobile_Number)
                        && getline(inputFile, student.Student_Present_address))
                {
                    if(StrTemp[0] >= '0' && StrTemp[0] <= '9') student.Student_Id = StrTemp+student.Student_Id;
                    StrTemp = "";
                    inputFile >> noskipws >> chTemp;
                    StrTemp += chTemp;
                    if (student.Student_Id != id)
                    {
                        tempFile << student.Student_Name << endl
                                 << student.Student_Id << endl
                                 << student.Student_Section << endl
                                 << student.Student_Intake << endl
                                 << student.Student_Father_Name << endl
                                 << student.Student_Mother_Name << endl
                                 << student.Student_Mobile_Number << endl
                                 << student.Student_Present_address << endl
                                 << endl;
                    }
                    else
                    {
                        found = true;
                    }
                }

                inputFile.close();
                tempFile.close();
            }

            remove("student_data.txt");
            rename("temp.txt", "student_data.txt");

            if (found)
            {
                system("cls");
                cout<<endl;
                cout<<"\t\t\t================================================================\n";
                cout << "\t\t\t             Student with ID " << id << " deleted                " << endl;
                cout<<"\t\t\t================================================================\n\n\n";

            }
            else
            {
                system("cls");
                cout<<endl;
                cout << "Student with ID " << id << " not found." << endl;

            }

            break;
        }
        case 4:
        {
            cout<<"\n";
            cout << "Enter the ID of the student you want to search: ";
            string searchStudentId;
            cin.ignore();
            getline(cin, searchStudentId);

            ifstream inputFile("student_data.txt");
            if (!inputFile.is_open())
            {
                cout << "No student data found." << endl;
            }
            else
            {
                Student student;
                bool found = false;
                char chTemp;
                string StrTemp = "";
                while (getline(inputFile, student.Student_Name)
                        && getline(inputFile, student.Student_Id)
                        && getline(inputFile, student.Student_Section)
                        && getline(inputFile, student.Student_Intake)
                        && getline(inputFile, student.Student_Father_Name)
                        && getline(inputFile, student.Student_Mother_Name)
                        && getline(inputFile, student.Student_Mobile_Number)
                        && getline(inputFile, student.Student_Present_address))
                {
                    if(StrTemp[0] >= '0' && StrTemp[0] <= '9') student.Student_Id = StrTemp+student.Student_Id;
                    StrTemp = "";
                    inputFile >> noskipws >> chTemp;
                    StrTemp += chTemp;
                    if (student.Student_Id == searchStudentId)
                    {
                        system("cls");
                        found = true;
                        cout << "\t\t\t================================================================\n";
                        cout << "\t\t\t|                   Student Information     ==>                |\n";
                        cout << "\t\t\t================================================================\n\n";
                        student.displayStudentData();
                    }
                }

                inputFile.close();

                if (!found)
                {
                    cout << "Student not found." << endl;
                }
            }
            break;
        }
        case 5:
        {
            ifstream inputFile("student_data.txt");
            if (!inputFile.is_open())
            {
                system("cls");
                cout << "No students to calculate CGPA for." << endl;
            }
            else
            {
                int number_of_students_to_calculate;
                cout<<endl;
                cout << "Enter the number of students you want to calculate CGPA for: ";
                cin >> number_of_students_to_calculate;
                cout<<endl;
                for (int i = 0; i < number_of_students_to_calculate; i++)
                {
                    string searchIdStudent;
                    cout << "Enter the ID of student " << i + 1 << ": ";
                    cin.ignore();
                    getline(cin, searchIdStudent);
                    cout<<endl;
                    bool found = false;
                    char chTemp;
                    string StrTemp = "";
                    Student student;
                    while (getline(inputFile, student.Student_Name)
                            && getline(inputFile, student.Student_Id)
                            && getline(inputFile, student.Student_Section)
                            && getline(inputFile, student.Student_Intake)
                            && getline(inputFile, student.Student_Father_Name)
                            && getline(inputFile, student.Student_Mother_Name)
                            && getline(inputFile, student.Student_Mobile_Number)
                            && getline(inputFile, student.Student_Present_address))
                    {
                        if(StrTemp[0] >= '0' && StrTemp[0] <= '9') student.Student_Id = StrTemp+student.Student_Id;
                        StrTemp = "";
                        inputFile >> noskipws >> chTemp;
                        StrTemp += chTemp;
                        if (student.Student_Id == searchIdStudent)
                        {
                            ifstream cgpaFile("cgpa_data.txt");
                            bool cgpaCalculated = false;
                            string line;
                            while (getline(cgpaFile, line))
                            {
                                if (line == searchIdStudent)
                                {
                                    cgpaCalculated = true;
                                    break;
                                }
                            }
                            cgpaFile.close();

                            if (!cgpaCalculated)
                            {
                                student.inputStudentDatacgpa();
                                double cgpa = student.calculateCGPA();
                                cout << "Student " << student.Student_Name << "'s CGPA: " << cgpa << endl;
                                cout<<endl;
                                found = true;
                                ofstream cgpaOutputFile("cgpa_data.txt", ios::app);
                                if (cgpaOutputFile.is_open())
                                {
                                    cgpaOutputFile << student.Student_Name << endl
                                                   << student.Student_Id << endl
                                                   << cgpa << endl
                                                   << endl;
                                    cgpaOutputFile.close();
                                }

                                break;
                            }
                            else
                            {
                                system("cls");
                                cout << "CGPA already calculated for student with ID: " << searchIdStudent << endl;
                            }

                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        system("cls");
                        cout << "Student with ID " << searchIdStudent << " not found." << endl;
                    }
                    inputFile.clear();
                    inputFile.seekg(0, ios::beg);
                }
            }
            break;
        }
        case 6:
        {
            view_all_cgpa();
            break;
        }
        case 7:
        {
            one_student_cgpa();
            break;
        }
        case 8:
        {
            cout << "Number of Teachers: ";
            int number_of_Teachers;
            cin>>number_of_Teachers;
            cin.ignore();
            Teacher New_Teachers[number_of_Teachers];
            for(int i=0; i<number_of_Teachers; i++)
            {
                New_Teachers[i].inputTeacherData();
                Teachers.push_back(New_Teachers[i]);
            }
            system("cls");
            cout<<endl;
            cout<<"\t\t\t================================================================\n";
            cout<<"\t\t\t|               Teacher added successfully!!!!                 |\n";
            cout<<"\t\t\t================================================================\n\n";
            break;
        }
        case 9:
        {
            ifstream inputFile("teacher_data.txt");
            if (!inputFile.is_open())
            {
                cout << "No teacher data found." << endl;
            }
            else
            {
                system("cls");
                cout << "\t\t\t================================================================\n";
                cout << "\t\t\t|               List of Teachers ==>                           |\n";
                cout << "\t\t\t================================================================\n\n";

                Teacher teacher;
                char chTemp;
                string StrTemp = "";
                while (getline(inputFile, teacher.Teacher_Name)
                        && getline(inputFile, teacher.Teacher_Id)
                        && getline(inputFile, teacher.Teacher_Mobile_Number)
                        && getline(inputFile, teacher.Teacher_Present_address))
                {
                    if(StrTemp[0] >= 'A' && StrTemp[0] <= 'z') teacher.Teacher_Name = StrTemp+teacher.Teacher_Name;
                    StrTemp = "";
                    inputFile >> noskipws >> chTemp;
                    StrTemp += chTemp;
                    teacher.displayTeacherData();
                    cout << endl;
                }

                inputFile.close();
            }
            break;
        }
        case 10:
        {
            cout << "Enter Teacher ID to delete: ";
            string id;
            cin.ignore();
            getline(cin,id);

            ifstream inputFile("teacher_data.txt");
            ofstream tempFile("temp.txt");

            bool found = false;

            if (!inputFile.is_open())
            {
                system("cls");
                cout << "No teacher data found." << endl;
            }
            else
            {
                Teacher teacher;
                char chTemp;
                string StrTemp = "";
                while (getline(inputFile, teacher.Teacher_Name)
                        && getline(inputFile, teacher.Teacher_Id)
                        && getline(inputFile, teacher.Teacher_Mobile_Number)
                        && getline(inputFile, teacher.Teacher_Present_address))
                {
                    if(StrTemp[0] >= '0' && StrTemp[0] <= '9') teacher.Teacher_Id = StrTemp+teacher.Teacher_Id;
                    StrTemp = "";
                    inputFile >> noskipws >> chTemp;
                    StrTemp += chTemp;
                    if (teacher.Teacher_Id != id)
                    {
                        tempFile << teacher.Teacher_Name << endl
                                 << teacher.Teacher_Id << endl
                                 << teacher.Teacher_Mobile_Number << endl
                                 << teacher.Teacher_Present_address << endl
                                 << endl;
                    }
                    else
                    {
                        found = true;
                    }
                }

                inputFile.close();
                tempFile.close();
            }

            remove("teacher_data.txt");
            rename("temp.txt", "teacher_data.txt");

            if (found)
            {
                system("cls");
                cout<<endl;
                cout<<"\t\t\t================================================================\n";
                cout << "\t\t\t             Teacher with ID " << id << " deleted                " << endl;
                cout<<"\t\t\t================================================================\n\n\n";
            }
            else
            {
                system("cls");
                cout << "Teacher with ID " << id << " not found." << endl;
            }

            break;
        }
        case 11:
        {
            cout << "Enter the id of the Teacher you want to search: ";
            string searchTeacherid;
            cin.ignore();
            getline(cin, searchTeacherid);

            ifstream inputFile("teacher_data.txt");

            if (!inputFile.is_open())
            {
                system("cls");
                cout << "No teacher data found." << endl;
            }
            else
            {
                Teacher teacher;
                bool found = false;
                char chTemp;
                string StrTemp = "";
                while (getline(inputFile, teacher.Teacher_Name)
                        && getline(inputFile, teacher.Teacher_Id)
                        && getline(inputFile, teacher.Teacher_Mobile_Number)
                        && getline(inputFile, teacher.Teacher_Present_address))
                {
                    if(StrTemp[0] >= '0' && StrTemp[0] <= '9') teacher.Teacher_Id = StrTemp+teacher.Teacher_Id;
                    StrTemp = "";
                    inputFile >> noskipws >> chTemp;
                    StrTemp += chTemp;
                    if (teacher.Teacher_Id == searchTeacherid)
                    {
                        system("cls");
                        found = true;
                        cout << "\t\t\t================================================================\n";
                        cout << "\t\t\t|                   Teacher Informetion     ==>                |\n";
                        cout << "\t\t\t================================================================\n\n";

                        teacher.displayTeacherData();
                    }
                }

                inputFile.close();

                if (!found)
                {
                    system("cls");
                    cout << "Teacher not found." << endl;
                }
            }
            break;
        }

        case 12:
            system("cls");
            cout << "Exiting the program." << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

}
/// ---------------------------------------------------------------Registration Function part--------------------------------------------------------------
void registration()
{
    system("cls");
    cout<<endl;
    cout<<"\t\t\t================================================================\n";
    cout<<"\t\t\t|                  Registration Page                           |\n";
    cout<<"\t\t\t================================================================\n\n";
    string ruserId,rpassword,rid,rpass;
    cout<<"\t\t\t Enter The Username : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter The Password : ";
    cin>>rpassword;

    ofstream f1("record.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t================================================================\n";
    cout<<"\t\t\t|                  Registration Successfully!                  |\n";
    cout<<"\t\t\t================================================================\n\n";
    Sleep(600);
    mainlogin();

}
/// -------------------------------------------------------------------Login Function part-----------------------------------------------------------------
void login()
{
    int counts=0;
    string userId,password,id,pass;
    system("cls");
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t  Please enter the username and password : "<<endl;
    cout<<"\t\t\t ___________________________________________\n\n";
    cout<<"\t\t\t  USERNAME =>  ";
    cin>>userId;
    cout<<"\t\t\t  PASSWORD =>  ";
    cin>>password;


    ifstream input("record.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            counts = 1;
            system("cls");
        }
        system("cls");
    }
    input.close();
    system("cls");
    if (counts == 1)
    {
        system("cls");
        cout<<"\t\t\t _______________________________________________________________\n";
        cout <<"\t\t\t                   LOGIN is successfully                     \n\n";
        cout <<"\t\t\t                    Thanks for login !                         \n";
        cout<<"\t\t\t _______________________________________________________________\n\n";
        if (counts == 1)
        {
            project();
        }
    }
    else
    {
        cout<<"\n\n\n\n\n";
        cout<<"\n\t\t\t                   LOGIN ERROR\n\n";
        cout<<"\t\t\t        Please check your username and password\n\n";
        cout << "Press any key to continue...";
        getch();
        mainlogin();
    }
}
/// ------------------------------------------------------------------Forgot Function part-----------------------------------------------------------------
void forgot()
{
    string soption;
    system("cls");
    cout<<"\t\t\t _______________________________________________________________\n";
    cout <<"\t\t\t                  Forgot Password?  No worries                 \n";
    cout<<"\t\t\t _______________________________________________________________\n\n";
    cout <<"\t\t\t              Press 1 to search your id by username            \n";
    cout <<"\t\t\t              Press 2 to go back to the main menu              \n";
    cout<<"\t\t\t _______________________________________________________________\n\n";
    cout<<"\t\t\t Enter Your Choice :";
    cin>>soption;
    int option;
    if(soption != "1" && soption!= "2") option = 3;
    else option =soption[0]-'0';
    switch(option)
    {

    case 1:
    {
        int counts=0;
        string suserId,sId,spass;
        cout<<"\n\t\t\t Enter the username which you remembered :";
        cin>>suserId;

        ifstream f2("record.txt");
        while(f2>>sId>>spass)
        {
            if(sId==suserId)
            {
                counts=1;
                break;
            }
        }
        f2.close();
        if(counts==1)
        {
            cout<<"\n\n Your account is found! \n";
            cout<<"\n\n\t\t\t Your Password is :  "<<spass<<endl<<"\n";
            cout << "Press any key to continue...";
            getch();
            mainlogin();
        }
        else
        {
            cout<<"\n\n Your account is not found! Please try again \n";
            getch();
            forgot();
        }
        break;
    }
    case 2:
    {
        mainlogin();
    }
    default :
        cout<<"\t\t\t Wrong choice ! Please try again "<<endl;
        getch();
        forgot();
    }
}
/// ----------------------------------------------------------login---registration---forgot--part----------------------------------------------------------
void mainlogin()
{
    system("cls");
    string cc;
    cout<<"\t\t\t _______________________________________________________________\n\n\n";
    cout<<"\t\t\t                Welcome to the Admin Login page                       \n\n\n";
    cout<<"\t\t\t ______________________________MENU_____________________________\n\n";
    cout<<"                                                                       \n\n";
    cout<<"\t| Press 1 to LOGIN                       |"<<endl;
    cout<<"\t| Press 2 to REGISTRATION                |"<<endl;
    cout<<"\t| Press 3 to FORGET PASSWORD             |"<<endl;
    cout<<"\t| Press 4 to EXIT                        |"<<endl;
    cout<<"\n\t\t\t  Please enter your choice :  ";
    cin>>cc;
    cout<<endl;
    int c;
    if(cc != "1" &&cc != "2" &&cc != "3" &&cc != "4") c = 5;
    else c = cc[0]-'0';

    switch(c)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout<<"\t\t\t  Thank you!  \n\n";
        break;

    default:
        cout<<"\t\t\t Please select from the options given above. click Enter to return...\n"<<endl;
        getch();
        mainlogin();
    }
}
///-----------------------------------------------------------------loading part---------------------------------------------------------------------------
void loadingBar()
{
    system("color f1");
    char a = 219;
    cout << "\n\n\n\n";
    cout << "\n\n\n\n\t\t\t\t\t\t System Loading.....\n";
    cout<<"\t\t\t\t\t\t====================\n\n";
    cout << "\t\t\t\t";
    for (int i = 0; i < 100; i++)
    {
        int progress = (i * 100) / 99;

        int pos = (i * 50) / 99;

        for (int j = 0; j < 50; j++)
        {
            if (j < pos)
                cout << a;
            else
                cout << " ";
        }

        cout <<" "<< progress << "%" << "\r";
        cout << "\t\t\t\t";

        Sleep(5);
    }

    cout << endl;
    system("cls");
}
/// ---------------------------------------------------------------Main function part----------------------------------------------------------------------
int main()
{
    loadingBar();
    mainlogin();
    return 0;
}







