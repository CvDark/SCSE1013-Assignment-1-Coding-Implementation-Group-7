#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int feature1(string SubjectName[], int OverallScore[], string grade[], int &subjects) {
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

int feature2(int total_subject, string subject[], string grade[], int credit_hour[], double grade_point[], double* GPA) { // Function to calculate GPA based on user input
    double total_GP = 0.0;
    int total_CH = 0;

    cin.ignore();                                                   // Clear the input buffer to avoid issues with getline after cin

    for (int i = 0; i < total_subject; i++) {
        cout << "Enter your subject's name: ";
        getline(cin, subject[i]);                                   // Get the subject name from user input
    }

    for (int i = 0; i < total_subject; i++) {                        // Loop to get grades and credit hours for each subject
        cout << "Enter your grade for " << subject[i] << ": ";
        cin >> grade[i];
        cout << "Enter credit hour for " << subject[i] << ": ";
        cin >> credit_hour[i];
    }

    for (int i = 0; i < total_subject; i++) {                       // Loop to convert grades to grade points and calculate total grade points and credit hours
        if (grade[i] == "A+" || grade[i] == "A") {
            grade_point[i] = 4.00;
        } else if (grade[i] == "A-") {
            grade_point[i] = 3.67;
        } else if (grade[i] == "B+") {
            grade_point[i] = 3.33;
        } else if (grade[i] == "B") {
            grade_point[i] = 3.00;
        } else if (grade[i] == "B-") {
            grade_point[i] = 2.67;
        } else if (grade[i] == "C+") {
            grade_point[i] = 2.33;
        } else if (grade[i] == "C") {
            grade_point[i] = 2.00;
        } else if (grade[i] == "C-") {
            grade_point[i] = 1.67;
        } else if (grade[i] == "D+") {
            grade_point[i] = 1.33;
        } else if (grade[i] == "D") {
            grade_point[i] = 1.00;
        } else if (grade[i] == "D-") {
            grade_point[i] = 0.67;
        } else if (grade[i] == "E") {
            grade_point[i] = 0.00;
        } else {
            cout << "Invalid Grade!" << endl;
            grade_point[i] = 0.00;
        }

        total_GP += grade_point[i] * credit_hour[i];
        total_CH += credit_hour[i];
    }

    *GPA = total_GP / total_CH;

    cout << "-------------------------------------------" << endl;
    cout << "Subject \tGrade \tCredit Hour \t\tGrade Point" << endl;
    for (int i = 0; i < total_subject; i++) {
        cout << subject[i] << " \t " << grade[i] << " \t\t " << credit_hour[i]                          // Display the subject name, grade, credit hour, and grade point for each subject
             << " \t\t\t " << fixed << setprecision(2) << grade_point[i] << endl;
    }
    cout << "Your GPA for this semester is " << fixed << setprecision(2) << *GPA << endl;               // Display the calculated GPA with two decimal places
}

    void displaySummary(string subject[], int overallScore[], string grade[], int credit_hour[], double grade_point[], int total_subject)
{
    cout << "\n=======================================================================\n";
    cout << "                     ACADEMIC PERFORMANCE SUMMARY\n";
    cout << "=======================================================================\n";

    // Check whether any subject information exists
    if (total_subject <= 0)
    {
        cout << "\nNo academic records available yet.\n";
        cout << "Please complete Feature 1 or Feature 2 first.\n";
        return;
    }

    cout << fixed << setprecision(2);

    cout << "\n";
    cout << left << setw(20) << "Subject"
         << setw(15) << "Score"
         << setw(10) << "Grade"
         << setw(15) << "Credit Hours"
         << setw(12) << "Grade Point" << endl;

    cout << "-----------------------------------------------------------------------\n";

    double total_GP = 0;
    int total_CH = 0;

    for (int i = 0; i < total_subject; i++)
    {
        cout << left << setw(20) << subject[i]
             << setw(15) << overallScore[i]
             << setw(10) << grade[i]
             << setw(15) << credit_hour[i]
             << setw(12) << grade_point[i] << endl;

        total_GP += credit_hour[i] * grade_point[i];
        total_CH += credit_hour[i];
    }

    cout << "-----------------------------------------------------------------------\n";

    if (total_CH > 0)
    {
        double GPA = total_GP / total_CH;

        cout << "\nTotal Credit Hours: " << total_CH << endl;
        cout << "Calculated GPA: " << GPA << endl;
    }
    else
    {
        cout << "\nGPA cannot be calculated because credit hours are unavailable.\n";
    }

    cout << "\n=======================================================================\n";
}
int additionalfeatures()
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

// ============================================================================
// Main Menu Controller
// ============================================================================
int main() {
    const int MAX = 15; // Maximum capacity for all parallel arrays

    // Variables matching feature1 and feature2
    string SubjectName[MAX];
    string grade[MAX];
    int OverallScore[MAX];
    int credit_hour[MAX];
    double grade_point[MAX];

    int subjects;
    double GPA;
    int choice;

    do {
        cout << "\n===========================================================\n";
        cout << "|            STUDENT ACADEMIC SYSTEM MENU                 |\n";
        cout << "===========================================================\n";
        cout << "|1. Calculate Subject Marks & Grade (Feature 1)           |\n";
        cout << "|2. Calculate Semester GPA (Feature 2)                    |\n";
        cout << "|3. Display Academic Performance Summary (Feature 3)      |\n";
        cout << "|4. Check Exam Attendance Eligibility (Additional Feature)|\n";
        cout << "|5. Exit                                                  |\n";
        cout << "===========================================================\n";
        cout << "Enter your choice (1-5):";
        cin >> choice;

        switch (choice) {
            case 1:
                feature1(SubjectName, OverallScore, grade, subjects);
                break;
            case 2: 
                feature2(subjects, SubjectName, grade, credit_hour, grade_point, &GPA);
                break;
            case 3:
                displaySummary(SubjectName, OverallScore, grade, credit_hour, grade_point, subjects);
                break;
            case 4:
                additionalfeatures();
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
