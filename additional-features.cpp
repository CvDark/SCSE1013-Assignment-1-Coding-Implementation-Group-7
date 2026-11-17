
#include <iostream>
#include <string>
#include <algorithm>                       // To convert the user's input into lowercase automatically
#include <cctype>
#include <iomanip>                         // To convert attendance's percentage into 2 decimal point
using namespace std;

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
