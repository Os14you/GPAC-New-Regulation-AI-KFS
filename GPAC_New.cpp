#include <iostream>
using namespace std;

const double GPA_NUMERIC[] = {0,1,1.5,2,2.2,2.4,2.6,2.8,3,3.2,3.4,3.7,4};
const string GPA_ALPHA[] = {"F","D-","D","D+","C-","C","C+","B-","B","B+","A-","A","A+"};

int getIndex(string input){
    input[0]=toupper(input[0]);
    int index=-1;
    for(int i=0;i<13;i++){
        if(GPA_ALPHA[i] == input){
            index=i; break;
        }
    }
    return index;
}
struct Grades {
    double numGrades[8]={0};
    int numCreditHours[8]={0};
    int sumOfHours(){
        int sum=0;
        for(int i=0;i<8;i++){
            if(numCreditHours[i]==-1)
                break;
            sum+=numCreditHours[i];
        }
        return sum;
    }
    void getGrades(){
        int numOfSubjects;
        cout << "Enter the number of subjects (exclude non-credits subjects) : ";
        cin>>numOfSubjects;
        for(int i=0;i<numOfSubjects;i++){
            int index=-1;
            string inputGrade;
            cout << "Enter the number of credits for subject "<< (i+1) << " : ";
            cin >> numCreditHours[i];
            cout << "Enter your grade in this subject : ";
            while(index==-1){
                cin>>inputGrade;
                index = getIndex(inputGrade);
                if(index==-1)
                    cout<<"Enter a valid input : ";
            }
            numGrades[i]=GPA_NUMERIC[index];
        }
    }
};

double CalculateGPA_semester(Grades grades){
    double GPA=0;
    for(int i=0;i<8;i++){
        if(grades.numCreditHours[i]==-1)
            break;
        GPA+=grades.numGrades[i]*grades.numCreditHours[i];
    }
    return GPA/grades.sumOfHours();
}

void showGPA(double grade,bool isOneSem=true){
    if(isOneSem)
        cout<<"Your GPA for this semester is "<<grade<<endl;
    else
        cout<<"Your cumulative GPA is "<<grade<<endl;
}

void Instructions(){
    cout<<"************** Instructions **************\n"
        <<"1. Enter the letter grade from the following :\n"
        <<"[ A+ , A , A- , B+ , B , B- , C+ , C , C- , D+ , D , D- , F ] \n"
        <<"2. If there is a non-credits subject skip it \n"
        <<"3. Press Enter to continue \n\n";
}

int menu(){
    static int tries = 0;
    int choice;
    if(!tries++)
        Instructions();
    cout<<"---------------- Options ----------------\n"
        <<"1. Calculate your GPA for a specific semester \n"
        <<"2. Calculate your cumulative GPA (coming soon) \n"
        <<"3. Calculate your age (coming soon) \n"
        <<"4. Exit program\n\n"<<"Enter your choice : "; cin>>choice;
    return choice;
}
void GPA_Calculator_System(){
    while(true){
        Grades grades;
        int choice = menu();
        switch (choice){
            case 1: grades.getGrades(); showGPA(CalculateGPA_semester(grades)); break;
            case 4: return;
            default: return;
        }
    }
}
int main(){
    GPA_Calculator_System();
    return 0;
}