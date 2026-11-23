void displaySummary(string subject1[], int OverallScore[], string grade1[], int subjects1,string subject2[], string grade2[], int credit_hour[], double grade_point[], int subjects2)
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
            cout << left << setw(25) << subject2[i]
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