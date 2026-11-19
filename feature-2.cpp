#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void feature2(int total_subject, string subject[], string grade[], int credit_hour[], double grade_point[], double* GPA) {
    double total_GP = 0.0;
    int total_CH = 0;

    cin.ignore();

    for (int i = 0; i < total_subject; i++) {
        cout << "Enter your subject's name: ";
        getline(cin, subject[i]);
    }

    for (int i = 0; i < total_subject; i++) {
        cout << "Enter your grade for " << subject[i] << ": ";
        cin >> grade[i];
        cout << "Enter credit hour for " << subject[i] << ": ";
        cin >> credit_hour[i];
    }

    for (int i = 0; i < total_subject; i++) {
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
        cout << subject[i] << " \t " << grade[i] << " \t\t " << credit_hour[i]
             << " \t\t\t " << fixed << setprecision(2) << grade_point[i] << endl;
    }
    cout << "Your GPA for this semester is " << fixed << setprecision(2) << *GPA << endl;
}