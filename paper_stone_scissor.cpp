
#include<iostream>
#include<cstdlib>
#include<string>
#include<stdlib.h>
#include <time.h>
#include<bits/stdc++.h>
using namespace std;
int ReadPositiveNumber(string Message){
  int Number = 0;
  do    {
     cout << Message << endl;
     cin >> Number;     }
  while (Number <= 0);
     return Number; }
int RandomNumber(int From, int To) {
  int randNum = rand() % (To - From + 1) + From;
  return randNum; }
  int Number, n , again=1;char play;
  int Player_won=0,Computer_won=0,Draw_times=0;string Final_winner;
  string as ="no winner"  ,b="player win"  ,c= "computer win";
  int counter=0, counters=0, counterss=0;
  enum GameNames{Paper=1, Stone=2, Scissor=3};
  enum win {nowinner=1,playerwin=2,computerwin=3};
int ChoicePlayer (int Number){
   switch (Number){
    case  1:
     return 1;break;
    case  2:
     return 2;break;
    case  3:
     return 3;break;}}
int ComputerChoice (int Number ){
  switch (Number){
    case  1:
     return 1;break;
    case  2:
     return 2;break;
    case  3:
     return 3;break;}}
string RoundWinner(int Number,int n){
 if (ChoicePlayer(Number)== 1&& ComputerChoice(n)== 1   )
        {return as;}
   else if ( ChoicePlayer(Number)== 1&& ComputerChoice(n)==2  )
        {return b;}
   else if ( ChoicePlayer(Number)== 1 && ComputerChoice(n)==3 )
        {return c;}
   else if (ChoicePlayer(Number)==2&&ComputerChoice(n)== 3 )
         {return b;}
   else if ( ChoicePlayer(Number)==2&&ComputerChoice(n)==2 )
         {return as;}
   else if ( ChoicePlayer(Number)==2&&ComputerChoice(n)==1 )
         {return c;}
   else if (ChoicePlayer(Number)==3&&ComputerChoice(n)==1)
        {return b;}
   else if (ChoicePlayer(Number)==3&& ComputerChoice(n)==2 )
        {return c;}
   else if ( ChoicePlayer(Number)==3&&ComputerChoice(n)==3 )
        {return as;}
}
int playerswin(string x){
   counter=0;
  if (x==b)
    counter ++;return counter;}
int computerswin(string x){
   counters=0;
  if (x==c)
    counters ++;return counters;}
int drawswin(string x){
   counterss=0;
  if (x==as)
    counterss ++;return counterss;}
int PlayGameAgain(){
  cin >> play;
  if (play=='y'||play=='Y')
    {again++;return again;}
  else
   return 0;
  }
string final_result(int player,int computer,int no ){
   if (player>computer)
   {return "player";}
   if (player<computer)
   {return "Computer";}
   if (player==computer)
   {return "Draw";}}

int playerswins=0, computerswins=0, drawswins=0;

int main(){
  srand((unsigned)time(NULL));
  do{
  string a="How many round from 1 to 10 ?";
  string s="Your Choice:[1]:Paper,[2]:Stone,[3]:Scissor? \n";
  int Round=ReadPositiveNumber(a);
for (int i=1;i<=Round;i++){
    int Number=ReadPositiveNumber(s);
    int Numbers=RandomNumber(1,  3);
    string Roundwin=RoundWinner(ChoicePlayer(Number),ComputerChoice(Numbers));
    cout<< "Round ["<< i<<"] begins :"<<"\n";
    cout<< "player choice :  " << ChoicePlayer(Number)<<"\n";
    cout<< "computer choice :  " <<ComputerChoice(Numbers)<<"\n";
    cout<< "round winner is  " <<Roundwin<<"\n";
  if (Roundwin==as)
     drawswins++;
     else if (Roundwin==b)
     playerswins++;
     else if( Roundwin==c)
     computerswins++;};
 cout << "_________________________________"<<"\n";
 cout << "                    ___________________________________________\n";
 cout <<"\n";
 cout <<"                                   +++Game over+++              \n";
 cout <<"                     ___________________________________________\n";
 cout << "                     \n";
 cout << "                      __________   [Game Result]   _____________\n";
 cout <<"                      Game round             : "<<Round<<  "\n";
 cout <<"                      Player won times       : "<<playerswins<<  "\n";
 cout<<"                       Computer won times     : "<<computerswins <<  "\n";
 cout <<"                      Draw times             : "<<drawswins<<  "\n";
 cout<<"                       Final winner           : "<<final_result( playerswins,computerswins, drawswins)<<  "\n";
 cout <<"                     ___________________________________________\n";
 cout << "                     \n";


  cout<< "Do you want to play again? Y/N\n";
  PlayGameAgain();
  again--;

  drawswins=0;
  computerswins=0;
  playerswins=0;
  }while (again>0);

  }





