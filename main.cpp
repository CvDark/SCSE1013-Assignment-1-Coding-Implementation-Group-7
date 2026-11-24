#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

const int MAX = 15;

int feature1(string SubjectName1[], int OverallScore[], string grade[], int &total_subject1) {
    // defining variables for feature 1

    cout << "Please enter totals subject you have registered for this semester: ";
    cin >> total_subject1;

    int LabToolMark[MAX], LabCodeMark[MAX], Assign1Mark[MAX], Assign2Mark[MAX], QuizMark[MAX], FEMark[MAX], TestMark[MAX];

    for (int i = 0; i < total_subject1; i++) {
        cout << "Please enter subject's name: ";
        getline(cin >> ws, SubjectName1[i]); // Use ws to consume any leading whitespace

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
    return 0;
}

int feature2(int total_subject2, string SubjectName2[], string grade2[], int credit_hour[], double grade_point[], double* GPA) { // Function to calculate GPA based on user input
    double total_GP = 0.0;
    int total_CH = 0;

    cin.ignore();                                                   // Clear the input buffer to avoid issues with getline after cin

    for (int i = 0; i < total_subject2; i++) {
        cout << "Enter your subject's name: ";
        getline(cin, SubjectName2[i]);                                   // Get the subject name from user input
    }

    for (int i = 0; i < total_subject2; i++) {                        // Loop to get grades and credit hours for each subject
        cout << "Enter your grade for " << SubjectName2[i] << ": ";
        cin >> grade2[i];
        cout << "Enter credit hour for " << SubjectName2[i] << ": ";
        cin >> credit_hour[i];
    }

    for (int i = 0; i < total_subject2; i++) {                       // Loop to convert grades to grade points and calculate total grade points and credit hours
        if (grade2[i] == "A+" || grade2[i] == "A") {
            grade_point[i] = 4.00;
        } else if (grade2[i] == "A-") {
            grade_point[i] = 3.67;
        } else if (grade2[i] == "B+") {
            grade_point[i] = 3.33;
        } else if (grade2[i] == "B") {
            grade_point[i] = 3.00;
        } else if (grade2[i] == "B-") {
            grade_point[i] = 2.67;
        } else if (grade2[i] == "C+") {
            grade_point[i] = 2.33;
        } else if (grade2[i] == "C") {
            grade_point[i] = 2.00;
        } else if (grade2[i] == "C-") {
            grade_point[i] = 1.67;
        } else if (grade2[i] == "D+") {
            grade_point[i] = 1.33;
        } else if (grade2[i] == "D") {
            grade_point[i] = 1.00;
        } else if (grade2[i] == "D-") {
            grade_point[i] = 0.67;
        } else if (grade2[i] == "E") {
            grade_point[i] = 0.00;
        } else {
            cout << "Invalid Grade!" << endl;
            grade_point[i] = 0.00;
        }

        total_GP += grade_point[i] * credit_hour[i];
        total_CH += credit_hour[i];
    }

    *GPA = total_GP / total_CH;
}

    void displaySummary(string subject1[], int OverallScore[], string grade1[], int subjects1,string total_subject2[], string grade2[], int credit_hour[], double grade_point[], int subjects2)
{
    cout << "\n=======================================================================\n";
    cout << "                     ACADEMIC PERFORMANCE SUMMARY\n";
    cout << "=======================================================================\n";

    // Check if BOTH Feature 1 and Feature 2 have no records yet
    if (subjects1 <= 0 && subjects2 <= 0)
    {
        cout << "\nNo academic records available yet.\n";
        cout << "Please complete Feature 1 or Feature 2 first.\n";
        cout << "\n=======================================================================\n";
        return;
    }

    // ---------------------------------------------------------
    // PART 1: Display Feature 1 Summary
    // ---------------------------------------------------------
    if (subjects1 > 0)
    {
        cout << "\n[ FEATURE 1: SUBJECT MARKS & GRADES ]\n\n";
        cout << left << setw(25) << "Subject"
             << setw(18) << "Overall Score"
             << setw(10) << "Grade" << endl;
        cout << "-----------------------------------------------------\n";

        for (int i = 0; i < subjects1; i++)
        {
            cout << left << setw(25) << subject1[i]
                 << setw(18) << OverallScore[i]
                 << setw(10) << grade1[i] << endl;
        }
        cout << "-----------------------------------------------------\n";
    }

    // ---------------------------------------------------------
    // PART 2: Display Feature 2 Summary (only if completed)
    // ---------------------------------------------------------
    if (subjects2 > 0)
    {
        cout << "\n[ FEATURE 2: SEMESTER GPA SUMMARY ]\n\n";
        cout << fixed << setprecision(2);

        cout << left << setw(25) << "Subject"
             << setw(10) << "Grade"
             << setw(15) << "Credit Hour"
             << setw(12) << "Grade Point" << endl;
        cout << "--------------------------------------------------------------\n";

        double total_GP = 0;
        int total_CH = 0;

        for (int i = 0; i < subjects2; i++)
        {
            cout << left << setw(25) << total_subject2[i]
                 << setw(10) << grade2[i]
                 << setw(15) << credit_hour[i]
                 << setw(12) << grade_point[i] << endl;

            total_GP += credit_hour[i] * grade_point[i];
            total_CH += credit_hour[i];
        }

        cout << "--------------------------------------------------------------\n";
        //Display total credit hours and GPA
        if (total_CH > 0)
        {
            double GPA = total_GP / total_CH;
            cout << "Total Credit Hours : " << total_CH << endl;
            cout << "Calculated GPA     : " << GPA << endl;
        }
        else
        {
            cout << "GPA cannot be calculated because credit hours are unavailable.\n";
        }
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
    string SubjectName1[MAX];
    string grade1[MAX];
    int OverallScore[MAX] = {0};
    int total_subject1 = 0;

    // Separate storage for Feature 2
    string SubjectName2[MAX];
    string grade2[MAX];
    int credit_hour[MAX] = {0};
    double grade_point[MAX] = {0.0};
    int total_subject2 = 0;
    double GPA = 0.0;
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
                feature1(SubjectName1, OverallScore, grade1, total_subject1);
                break;
            case 2: 
                feature2(total_subject2, SubjectName2, grade2, credit_hour, grade_point, &GPA);
                break;
            case 3:
                displaySummary(SubjectName1, OverallScore, grade1, total_subject1,SubjectName2, grade2, credit_hour, grade_point, total_subject2);
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