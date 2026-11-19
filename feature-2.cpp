#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {
    int total_subject, total_CH=0;
    double total_GP=0,GPA;
    cout << "Enter your total subject for this semester: ";
    cin >> total_subject;
    cin.ignore();                                                 // To ignore the newline character after reading total_subject

    vector<string> arr(total_subject);                             // Array to store subject names
    vector<string> grade(total_subject);                          // Array to store grades
    vector<int> credit_hour(total_subject);                       // Array to store credit hours
    vector<float>grade_point(total_subject);                      // Array to store grade points
    for (int i = 0; i < total_subject; i++){                        // Loop to get subject names
        cout<<"Enter your subject's name: ";
        getline(cin, arr[i]);                                       // Using getline to read the subject name, allowing for spaces
    }

    for (int i = 0; i < total_subject; i++) {                       // Loop to get grades and credit hours for each subject
        cout<<"Enter your grade for "<<arr[i]<< ": ";
        cin>>grade[i];
        cout<<"Enter credit hour for "<<arr[i]<<": ";
        cin>>credit_hour[i];
    }
    for(int i=0;i<total_subject;i++){
        if(grade[i]=="A+"){grade_point[i]=4.00;}
        else if(grade[i]=="A"){grade_point[i]=4.00;}
        else if(grade[i]=="A-"){grade_point[i]=3.67;}
        else if(grade[i]=="B+"){grade_point[i]=3.33;}
        else if(grade[i]=="B"){grade_point[i]=3.00;}
        else if(grade[i]=="B-"){grade_point[i]=2.67;}
        else if(grade[i]=="C+"){grade_point[i]=2.33;}
        else if(grade[i]=="C"){grade_point[i]=2.00;}
        else if(grade[i]=="C-"){grade_point[i]=1.67;}
        else if(grade[i]=="D+"){grade_point[i]=1.33;}
        else if(grade[i]=="D"){grade_point[i]=1.00;}
        else if(grade[i]=="D-"){grade_point[i]=0.67;}
        else if(grade[i]=="E"){grade_point[i]=0.00;}
        else{cout<<"Invalid Grade!";}
        total_GP=total_GP+(grade_point[i]*credit_hour[i]);
        total_CH=total_CH+credit_hour[i];
    }
    GPA=total_GP/total_CH;
    cout<<"-------------------------------------------"<<endl;                      // Displaying the result
    cout<<"Your GPA for this semester is "<<fixed<<setprecision(2)<<GPA;            // Using fixed and setprecision to format the GPA to 2 decimal places

    return 0;
}