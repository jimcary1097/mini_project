#include<iostream>
#include<cstdlib>
#include <time.h>
using namespace std;

enum  deficulty { easy = 1, med = 2, hard = 3, mixs = 4 };

enum operation { add = 1, sub = 2, mul = 3, divid = 4, mix = 5 };

struct questionl {
    short number = 0;
    deficulty def;
    operation op;
    char ops [4] = {'+','-','*','/'};
    char opss,opp ;
    string defs;
    short first = 0;
    short second = 0;
    float userResult = 0;
    float result = 0;
    short  CounterrightAnswer =0;
    short  CounterwrongAnswer =0;
};

int RandomNumber(int From, int To){
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int readNumber() {
    int number;
    cout << "how many questions do you want to answer?\n";
    cin >> number;
    return number;
};

int levelNumber() {
    int number;
    do {
        cout << "enter question level [1] easy ,[2] med,[3] hard, [4] mix ? \n";
        cin >> number;
    } while (number < 1 || number>4);
    return number;
};

int operationNumber() {
    int number;
    do {
        cout << "enter operation type [1] add ,[2] sub ,[3] mul,[5] div , [5] mix ? \n";
        cin >> number;
    } while (number < 1 || number>5);
    return number;
};

void ResetScreen() {
    system("cls");
    system("color 0f");
}

float  result(int a, int b, char c) {
    float result;
    switch (c) {
    case '+':
        result = a + b;
        return result;
        break;
    case '-':
        result = a - b;
        return result;
        break;

    case '*':
        result = a * b;
        return result;
        break;
    case '/':
        result = a / b;
        return result;
        break;
    }

}

void printDesign(questionl & q) {

        cout << q.first << endl;
        cout << q.opp << endl;
        cout << q.second << endl;

        cout << "____________________" << endl;
        cin >> q.userResult;
        q.result = result(q.first, q.second, q.opp);
        if (q.result == q.userResult)
        {
            cout<<endl;
            cout << "\n your answer is right :)" << endl;
            system("color 2F");
            q.CounterrightAnswer ++;
        }
        else
        {
            system("color 4F");
            cout << "the right answer is " << q.result << endl;
            q.CounterwrongAnswer ++;
        }
}

void printDesignQuestion(questionl & q) {
  switch (q.def) {
    case  deficulty::easy:
        q.first = RandomNumber(1, 10);
        q.second = RandomNumber(1, 10);
        printDesign(  q);


        break;
    case  deficulty::med:
        q.first = RandomNumber(11, 100);
        q.second = RandomNumber(11, 100);
        printDesign( q);

        break;

    case  deficulty::hard:
        q.first = RandomNumber(100, 1000);
        q.second = RandomNumber(100, 1000);
        printDesign( q);

        break;
    case  deficulty::mixs:
        q.first = RandomNumber(1, 1000);
        q.second = RandomNumber(1, 1000);

        printDesign( q);
        break;}
        };

deficulty def(int number) {
    switch (number) {
    case 1:
        return deficulty::easy;
        break;
    case 2:
        return deficulty::med;
        break;
    case 3:
        return deficulty::hard;
        break;
    case 4:
        return deficulty::mixs;
        break;
    }

}

char op(int op) {
questionl  q;
    switch (op) {
    case  1:
    q.opss=q.ops[0] ;
        return q.opss;
        break;
    case  2:
     q.opss=q.ops[1] ;
        return q.opss ;
        break;

    case  3:
     q.opss=q.ops[2] ;
        return q.opss;
        break;

    case  4:
     q.opss=q.ops[3] ;
         return q.opss;
        break;

    case  5:
     q.opss=q.ops[RandomNumber(1, 4)] ;

        return q.opss;
        break;}}

string diflevel(int n){
questionl  q;
string defd[4]={"easy ", "med ", "hard ", "mixs "};
 q.defs = defd[n-1];
 return q.defs;
}

void final_result(questionl q) {
    cout << "__________final result__________ "<<endl;
    cout<<endl;
    cout << "number of question: " << q.number << endl;
    cout << "type of queston: " << q.opp << endl;

    cout << "question level:  " <<q.defs;
     cout<< endl;
    cout << "number of right answer " << q.CounterrightAnswer<<endl;
    cout << "number of wrong answer " << q.CounterwrongAnswer << endl;

};

void question(questionl q) {
    int j,i;
    q.number = readNumber();
    q.def = def(levelNumber());
    q.defs=diflevel((int)q.def);
    q.opp = op(operationNumber());

    for (j= 1; j <= q.number; j++) {
        cout << "question  " << "[" << q.number << "/"
            << j << "]" << endl;
printDesignQuestion(q);}
final_result(q);}

void  StartProgram(){
    questionl q;   char PlayAgain = 'Y';
    do{ ResetScreen();
        question(q);
        cout << endl << "Do you want to ask again? Y/N? ";
        cin >> PlayAgain;} while (PlayAgain == 'Y' || PlayAgain == 'y');}

int main() {
    srand((unsigned)time(NULL));
    StartProgram();
    return 0;
}
