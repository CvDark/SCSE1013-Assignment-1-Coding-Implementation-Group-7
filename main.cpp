#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int features1(string SubjectName[], int OverallScore[], string grade[], int &subjects) {
    // defining variables for feature 1

    cout << "Please enter totals subject you have registered for this semester: ";
    cin >> subjects;

    const int MAX = subjects;

    int LabToolMark[MAX], LabCodeMark[MAX], Assign1Mark[MAX], Assign2Mark[MAX], QuizMark[MAX], FEMark[MAX], TestMark[MAX];

    for (int i = 0; i < subjects; i++) {
        cout << "Please enter subject's name: ";
        getline(cin >> ws, SubjectName[i]); // Use ws to consume any leading whitespace

        cout << "Please enter student Lab Exercise (Tools) mark (in percentage):";
        cin >> LabToolMark[i];
        
        cout << "Please enter student Lab Exercise (Code) mark (in percentage):";
        cin >> LabCodeMark[i];

        cout << "Please enter student Assignment 1 mark (in percentage):";
        cin >> Assign1Mark[i];

        cout << "Please enter student Assignment 2 mark (in percentage):";
        cin >> Assign2Mark[i];

        cout << "Please enter student total Quiz mark (in percentage):";
        cin >> QuizMark[i];

        cout << "Please enter student total Test mark (in percentage):";
        cin >> TestMark[i];

        cout << "Please enter student Final Exam mark (in percentage):";
        cin >> FEMark[i];

        //calculate overall score
        OverallScore[i] = LabToolMark[i] + LabCodeMark[i] + Assign1Mark[i] + Assign2Mark[i] + QuizMark[i] + TestMark[i] + FEMark[i];

        // START determine grade based on overall score
        if (OverallScore[i] > 100 || OverallScore[i] < 0) {//check whether the overal score is valid or no
            cout << "Error: Please enter a valid mark between 0 and 100\n";
            return 1; // Exit the program with an error code
        } else if (OverallScore[i] >= 90) {
            grade[i] = "A+";
        } else if (OverallScore[i] >= 80) {
            grade[i] = "A";
        } else if (OverallScore[i] >= 75) {
            grade[i] = "A-";
        } else if (OverallScore[i] >= 70) {
            grade[i] = "B+";
        } else if (OverallScore[i] >= 65) {
            grade[i] = "B";
        } else if (OverallScore[i] >= 60) {
            grade[i] = "B-";
        } else if (OverallScore[i] >= 55) {
            grade[i] = "C+";
        } else if (OverallScore[i] >= 50) {
            grade[i] = "C";
        } else if (OverallScore[i] >= 45) {
            grade[i] = "C-";
        } else if (OverallScore[i] >= 40) {
            grade[i] = "D+";
        } else if (OverallScore[i] >= 35) {
            grade[i] = "D";
        } else if (OverallScore[i] >= 30) {
            grade[i] = "D-";
        } else {
            grade[i] = "F";
        }
    }
}

int feature2(){
int total_subject;
        double total_GP=0, total_CH=0; 
        string subject_name="", grade;
        cout<<"\n-------------------------------------------------"<<endl;      //displaying a line for better readability//
        cout<<"Enter your total subject for this semester: ";
        cin>>total_subject;
        if(total_subject<=0){
            cout<<"You did not registered any subject!";                        //if the user enters 0 or negative number, it will display this message and exit the program//
            }
        for(int j=total_subject;j>0;j--){ 
            double credit_hour, GP;
            cout<<"Enter subject name: ";
            cin.ignore();                                                       //cin.ignore() is used to ignore the newline character left in the input buffer from previous input//
            getline(cin, subject_name);                                         //getline() is used to read the subject name with spaces//
            cout<<"Enter your grade for "<<subject_name<<": ";
            cin>>grade;
            cout<<"Enter "<<subject_name<<"'s credit hour: ";
            cin>>credit_hour; 
            if(grade=="A+"){GP=4.00;} 
            else if(grade=="A"){GP=4.00;}
            else if(grade=="A-"){GP=3.67;}
            else if(grade=="B+"){GP=3.33;}
            else if(grade=="B"){GP=3.00;}
            else if(grade=="B-"){GP=2.67;}
            else if(grade=="C+"){GP=2.33;}
            else if(grade=="C"){GP=2.00;}
            else if(grade=="C-"){GP=1.67;}
            else if(grade=="D+"){GP=1.33;}
            else if(grade=="D"){GP=1.00;}
            else if(grade=="D-"){GP=0.67;}
            else if(grade=="E"){GP=0.00;}
            else{cout<<"Invalid Grade!";}
            total_GP=total_GP+(GP*credit_hour);
            total_CH=total_CH+credit_hour;
        }
        double GPA;
        GPA=total_GP/total_CH;
        cout<<"Your GPA for this semester is "<<fixed<<setprecision(2)<<GPA;     //setprecision(2) is used to display the GPA with 2 decimal places//
        return 0;
    }

    void displaySummary()
{
    cout << "\n========================================\n";
    cout << "       ACADEMIC PERFORMANCE SUMMARY\n";
    cout << "========================================\n";

    // Check whether any subject information exists
    if (subjects.empty())
    {
        cout << "\nNo academic records available yet.\n";
        cout << "Please complete Feature 1 or Feature 2 first.\n";
        return;
    }

    // Display subject information
    cout << fixed << setprecision(2);                                                          // set Grade Point to 2 decimal points

    cout << "\n";
    cout << left << setw(20) << "Subject"                                                       // setw() is used to set width for output formatting
         << setw(15) << "Score"
         << setw(10) << "Grade"
         << setw(15) << "Credit Hours"
         << setw(12) << "Grade Point" << endl;

    cout << "-----------------------------------------------------------------------\n";

    double total_GP = 0;
    int total_CH = 0;

    for (int i = 0; i < subjects.size(); i++)
    {
        cout << left << setw(20) << subjects[i].subject_name
             << setw(15) << subjects[i].overallScore
             << setw(10) << subjects[i].grade
             << setw(15) << subjects[i].credit_hours
             << setw(12) << subjects[i].gradePoint << endl;

        // Calculate total weighted grade points
        total_GP +=
            subjects[i].credit_hours * subjects[i].gradePoint;

        total_CH += subjects[i].credit_hours;
    }

    cout << "-----------------------------------------------------------------------\n";

    // Display GPA
    if (total_CH > 0)
    {
        double GPA = total_GP / total_CH;

        cout << "\nTotal Credit Hours: " << total_CH << endl;
        cout << "\nCalculated GPA: " << GPA << endl;
    }
    else
    {
        cout << "\nGPA cannot be calculated because credit hours are unavailable.\n";
    }

    cout << "\n========================================\n";
}
int main()
{
    int totalClass, classAttend;           
    string subject;                        
    double attendance;                     

    cout << "\nPlease enter your subject (END to stop the program): ";                      //Program will end only if the user entered "end"
    getline(cin, subject);                                                                  //Use getline because there are space in the input
    transform(subject.begin(), subject.end(), subject.begin(), ::tolower);                  //To convert user's input into lowercase

    while (subject != "end")                                                                //Use while loop to ensure user's can see all subject's percentage
    {                                                                                       
        if (subject == "fundamental programming concept" ||                                 
            subject == "introduction to cloud computing" ||
            subject == "data engineering ecosystem" ||
            subject == "computer system and organizations" ||
            subject == "discrete structure")
        {
            cout << "Enter total class for this semester: " << endl;
            cin >> totalClass;

            cout << "Enter total class you attend for this semester: " << endl;
            cin >> classAttend;

            if (totalClass > 0 && classAttend >= 0 && classAttend <= totalClass)           
            {
                cout << fixed << setprecision(2);                                          //Convert the percentage into 2 decimal point
                attendance = (static_cast<double>(classAttend) / totalClass) * 100;       //Use static_cast<double> to convert data type int into double
                cout << "Your attendance percentage: " << attendance<<"%"<< endl;

                if (attendance >= 80)
                {
                    cout << "Eligible for Final Exam" << endl;
                }
                else
                {
                    cout << "Not eligible for Final Exam" << endl;
                }
            }
            else
            {
                cout << "Invalid input" << endl;                                         //Display invalid input if totalClass , classAttend is entered in negative number
            }
        }
        else
        {
            cout << "Invalid subject" << endl;                                          //Display invalid subject if the subjects are not listed
        }

        cin.ignore();                                                                       //Clears leftover input before reading the next line
        cout << "\nPlease enter your subject (END to stop the program): ";                  //Let user enter the input to loop the program
        getline(cin, subject);                                                              //Use getline because there are space in the input
        transform(subject.begin(), subject.end(), subject.begin(), ::tolower);              //To convert user's input into lowercase
    }

    return 0;                                                                               //Program ends successfully
}