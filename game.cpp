#include<iostream>
#include<string>
using namespace std;
int main()
{
char board[3][3]={
{' ',' ',' '},
{' ',' ',' '},
{' ',' ',' '}
};
const char playerx='x';
const char playero='o';
char currentPlayer=playerx;
int r=-1;
int c=-1;
char winner=' ';
for(int i=0;i<9;i++){
// print game board
cout<<"   |   |   "<<endl;
cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
cout<<"___|___|___"<<endl;
cout<<"   |   |   "<<endl;
cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
cout<<"___|___|___"<<endl;
cout<<"   |   |   "<<endl;
cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
cout<<"   |   |   "<<endl;

if(winner!=' '){
break;
}
// get player input
cout<<"current player is :"<<currentPlayer<<endl;
while(true){
cout<<"Enter r c from 0-2 for row and column:";
cin>>r>>c;
if(r<0 || r>2 ||c<0 ||c>2){
cout<<"Invalid input,try again."<<endl;
}
else if (board[r][c]!=' ')
{
cout<<"Tile is full,try again."<<endl;
}
else {
break;
}
r=-1;
c=-1;
cin.clear();//clear error flags
cin.ignore(10000,'\n');// discard value
}
board[r][c]=currentPlayer;
currentPlayer=(currentPlayer==playerx)?playero:playerx;
//check winners
// row-horizontal
for(int r=0;r<3;r++){
if(board[r][0]!=' ' && board[r][0] == board[r][1] && board [r][1]==board[r][2]){
winner =board[r][0];
break;
}
}
//columns-vertical
for(int c=0;c<3;c++){
if(board[c][0]!=' ' && board[0][c] == board[1][c] && board [1][c]==board[2][c]){
winner =board[0][c];
break;
}
}
if(board[0][0]!=' '&& board[0][0]==board[1][1]&& board[1][1]==board[2][2]){
winner=board[0][0];
}
else if(board[0][2]!=' '&& board[0][2]==board[1][1]&& board[1][1]==board[2][0]){
winner=board[0][2];
}
}
if(winner!=' '){
cout<<"Player"<<winner<<" is the winner!"<<endl;
}
else {
cout<<"Tie!"<<endl;
}
return 0;
}

