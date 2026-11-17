#include <iostream>
#include <iomanip>                                                              //for setprecision() function//
using namespace std;

int main(){
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