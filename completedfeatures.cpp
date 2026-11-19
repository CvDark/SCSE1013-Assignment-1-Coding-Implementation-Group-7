#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

// Shared structure to store subject records across Feature 1, Feature 2, and Feature 3
struct SubjectRecord {
    string subject_name;
    double overallScore;
    string grade;
    double credit_hours;
    double gradePoint;
};

vector<SubjectRecord> subjects;

// Helper function to convert a grade string to its corresponding grade point
double getGradePoint(const string& grade) {
    if (grade == "A+" || grade == "A") return 4.00;
    else if (grade == "A-") return 3.67;
    else if (grade == "B+") return 3.33;
    else if (grade == "B") return 3.00;
    else if (grade == "B-") return 2.67;
    else if (grade == "C+") return 2.33;
    else if (grade == "C") return 2.00;
    else if (grade == "C-") return 1.67;
    else if (grade == "D+") return 1.33;
    else if (grade == "D") return 1.00;
    else if (grade == "D-") return 0.67;
    else if (grade == "E" || grade == "F") return 0.00;
    return -1.0; // Indicates invalid grade
}

// ============================================================================
// feature 1
// ============================================================================
void feature1() {
    // defining variables for feature 1
    string grade;
    int LabToolMark, LabCodeMark, Assign1Mark, Assign2Mark, QuizMark, FEMark, TestMark;
    float FLabToolMark, FLabCodeMark, FAssign1Mark, FAssign2Mark, FQuizMark, TFEMark, FTestMark, OverallScore;

    // START getting input from user
    cout << "Please enter student Lab Exercise (Tools) mark (out of 100):" << '\n';
    cin >> LabToolMark;
    FLabToolMark = LabToolMark * 0.1;

    cout << "Please enter student Lab Exercise (Code) mark (out of 100):" << '\n';
    cin >> LabCodeMark;
    FLabCodeMark = LabCodeMark * 0.1;

    cout << "Please enter student Assignment 1 mark (out of 100):" << '\n';
    cin >> Assign1Mark;
    FAssign1Mark = Assign1Mark * 0.1;

    cout << "Please enter student Assignment 2 mark (out of 100):" << '\n';
    cin >> Assign2Mark;
    FAssign2Mark = Assign2Mark * 0.1;

    cout << "Please enter student total Quiz mark (out of 100):" << '\n';
    cin >> QuizMark;
    FQuizMark = QuizMark * 0.1;

    cout << "Please enter student total Test mark (out of 100):" << '\n';
    cin >> TestMark;
    FTestMark = TestMark * 0.2;

    cout << "Please enter student Final Exam mark (out of 100):" << '\n';
    cin >> FEMark;
    TFEMark = FEMark * 0.3;
    // STOP getting input from user

    //calculate overall score
    OverallScore = FLabToolMark + FLabCodeMark + FAssign1Mark + FAssign2Mark + FQuizMark + FTestMark + TFEMark;
    // START determine grade based on overall score
    if (OverallScore > 100 || OverallScore < 0) {//check whether the overal score is valid or no
        cout << "Error: Please enter a valid mark between 0 and 100\n";
        return;
    } else if (OverallScore >= 90) {
        grade = "A+";
    } else if (OverallScore >= 80) {
        grade = "A";
    } else if (OverallScore >= 75) {
        grade = "A-";
    } else if (OverallScore >= 70) {
        grade = "B+";
    } else if (OverallScore >= 65) {
        grade = "B";
    } else if (OverallScore >= 60) {
        grade = "B-";
    } else if (OverallScore >= 55) {
        grade = "C+";
    } else if (OverallScore >= 50) {
        grade = "C";
    } else if (OverallScore >= 45) {
        grade = "C-";
    } else if (OverallScore >= 40) {
        grade = "D+";
    } else if (OverallScore >= 35) {
        grade = "D";
    } else if (OverallScore >= 30) {
        grade = "D-";
    } else {
        grade = "F";
    }
    // END determine grade
    //display grade 
    cout <<" | Grade: " << grade << '\n';

    // Save record so Feature 3 can display it
    subjects.push_back({"",OverallScore,grade,0.0, getGradePoint(grade)});
}

// ============================================================================
// feature 2
// ============================================================================
void feature2() {
    int total_subject;
    double total_GP = 0, total_CH = 0;
    string subject_name = "", grade;

    cout << "\n-------------------------------------------------" << endl;
    cout << "Enter your total subject for this semester: ";
    cin >> total_subject;

    if (total_subject <= 0) {
        cout << "You did not register any subject!" << endl;
        return;
    }

    for (int j = total_subject; j > 0; j--) {
        double credit_hour, GP;
        cout << "Enter subject name: ";
        cin.ignore();
        getline(cin, subject_name);

        cout << "Enter your grade for " << subject_name << ": ";
        cin >> grade;

        cout << "Enter " << subject_name << "'s credit hour: ";
        cin >> credit_hour;

        GP = getGradePoint(grade);
        if (GP < 0) {
            cout << "Invalid Grade!" << endl;
            GP = 0.00;
        }

        total_GP = total_GP + (GP * credit_hour);
        total_CH = total_CH + credit_hour;

        // Save record so Feature 3 can display it (-1.0 indicates raw score was not entered)
        subjects.push_back({subject_name, -1.0, grade, credit_hour, GP});
    }

    if (total_CH > 0) {
        double GPA = total_GP / total_CH;
        cout << "Your GPA for this semester is " << fixed << setprecision(2) << GPA << endl;
    }
}

// ============================================================================
// feature 3
// ============================================================================
void displaySummary() {
    cout << "\n========================================\n";
    cout << "       ACADEMIC PERFORMANCE SUMMARY\n";
    cout << "========================================\n";

    // Check whether any subject information exists
    if (subjects.empty()) {
        cout << "\nNo academic records available yet.\n";
        cout << "Please complete Feature 1 or Feature 2 first.\n";
        return;
    }

    // Display subject information
    cout << fixed << setprecision(2);

    cout << "\n";
    cout << left << setw(25) << "Subject"
         << setw(15) << "Score"
         << setw(10) << "Grade"
         << setw(15) << "Credit Hours"
         << setw(12) << "Grade Point" << endl;

    cout << "-----------------------------------------------------------------------------\n";

    double total_GP = 0;
    double total_CH = 0;

    for (size_t i = 0; i < subjects.size(); i++) {
        cout << left << setw(25) << subjects[i].subject_name;

        if (subjects[i].overallScore >= 0) {
            cout << setw(15) << subjects[i].overallScore;
        } else {
            cout << setw(15) << "N/A";
        }

        cout << setw(10) << subjects[i].grade
             << setw(15) << subjects[i].credit_hours
             << setw(12) << subjects[i].gradePoint << endl;

        // Calculate total weighted grade points
        total_GP += subjects[i].credit_hours * subjects[i].gradePoint;
        total_CH += subjects[i].credit_hours;
    }

    cout << "-----------------------------------------------------------------------------\n";

    // Display GPA
    if (total_CH > 0) {
        double GPA = total_GP / total_CH;

        cout << "\nTotal Credit Hours: " << total_CH << endl;
        cout << "Calculated GPA: " << GPA << endl;
    } else {
        cout << "\nGPA cannot be calculated because credit hours are unavailable.\n";
    }

    cout << "\n======================================================\n";
}

// ============================================================================
// additional feature
// ============================================================================
void additionalFeature() {
    int totalClass, classAttend;
    string subject;
    double attendance;

    cin.ignore(); // Clears leftover newline from menu selection
    cout << "\nPlease enter your subject (END to stop the program): ";
    getline(cin, subject);
    transform(subject.begin(), subject.end(), subject.begin(), ::tolower);

    while (subject != "end") {
        if (subject == "fundamental programming concept" ||
            subject == "introduction to cloud computing" ||
            subject == "data engineering ecosystem" ||
            subject == "computer system and organizations" ||
            subject == "discrete structure") {
            
            cout << "Enter total class for this semester: " << endl;
            cin >> totalClass;

            cout << "Enter total class you attend for this semester: " << endl;
            cin >> classAttend;

            if (totalClass > 0 && classAttend >= 0 && classAttend <= totalClass) {
                cout << fixed << setprecision(2);
                attendance = (static_cast<double>(classAttend) / totalClass) * 100;
                cout << "Your attendance percentage: " << attendance << "%" << endl;

                if (attendance >= 80) {
                    cout << "Eligible for Final Exam" << endl;
                } else {
                    cout << "Not eligible for Final Exam" << endl;
                }
            } else {
                cout << "Invalid input" << endl;
            }
            cin.ignore(); // Clears leftover newline after cin >> classAttend
        } else {
            cout << "Invalid subject" << endl;
        }

        cout << "\nPlease enter your subject (END to stop the program): ";
        getline(cin, subject);
        transform(subject.begin(), subject.end(), subject.begin(), ::tolower);
    }
}
// function to get input subject name and credit hours from user
void DisplaySubject() {
    string subjectName;
    double creditHours;

    cin.ignore();
    cout << "\nEnter subject name: ";
    getline(cin, subjectName);

    cout << "Enter credit hours for " << subjectName << ": ";
    cin >> creditHours;

    subjects.push_back({subjectName, -1.0, "", creditHours, 0.0});

}

// ============================================================================
// Main Menu Controller
// ============================================================================
int main() {
    string subjectName, grade;
    double creditHours;
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
                DisplaySubject();
                feature1();
                break;
            case 2:
                feature2();
                break;
            case 3:
                displaySummary();
                break;
            case 4:
                additionalFeature();
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

