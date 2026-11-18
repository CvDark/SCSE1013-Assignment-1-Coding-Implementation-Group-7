
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

        cout << "\nTotal Credit Hours: " << total_CH;
        cout << "\nCalculated GPA: " << GPA << endl;
    }
    else
    {
        cout << "\nGPA cannot be calculated because credit hours are unavailable.\n";
    }

    cout << "\n========================================\n";
}
