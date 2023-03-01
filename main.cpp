#include<iostream>
using namespace std;
char Array[3][3]={
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
int row;
int coloum;
char token='X';
bool tie=false;
string n1;
string n2;

int CreateBody(){
    
    //create the structure of tic tac toe game
    cout<<"      |   " << "    |      " <<endl;
    cout<<Array[0][0]<<"     |   "<<Array[0][1]<< "   |      "<<Array[0][2] <<endl;
    cout<<"      |   " << "    |      " <<endl;
    cout<<"------|---" << "----|------" <<endl;
    cout<<"      |   " << "    |      " <<endl;
    cout<<Array[1][0]<<"     |   "<<Array[1][1]<< "   |      "<<Array[1][2] <<endl;
    cout<<"      |   " << "    |      " <<endl;
    cout<<"------|---" << "----|------" <<endl;
    cout<<"      |   " << "    |      " <<endl;
    cout<<Array[2][0]<<"     |   "<<Array[2][1]<< "   |      "<<Array[2][2] <<endl;
    cout<<"      |   " << "    |      " <<endl;
    return 0;
}
int EnterValue(){
    int digit;
    if(token=='X'){
        cout<<n1<<" Enter your box number : ";
        cin>>digit;
    }
    if(token=='O'){
        cout<<n2<<" Enter your box number : ";
        cin>>digit;
    }
    if(digit==1){
        row=0;
        coloum=0;
    }
    if(digit==2){
        row=0;
        coloum=1;
    }
    if(digit==3){
        row=0;
        coloum=2;
    }
    if(digit==4){
        row=1;
        coloum=0;
    }
    if(digit==5){
        row=1;
        coloum=1;
    }
    if(digit==6){
        row=1;
        coloum=2;
    }
    if(digit==7){
        row=2;
        coloum=0;
    }
    if(digit==8){
        row=2;
        coloum=1;
    }
    if(digit==9){
        row=2;
        coloum=2;
    }
    else if(digit<1 || digit >9){
        cout<<"invalid entry. "<<endl;
    }

    if(token=='X' && Array[row][coloum] != 'X' && Array[row][coloum] !='O'){
        Array[row][coloum]='X';
        token='O';
    }
    else if(token=='O' && Array[row][coloum] != 'X' && Array[row][coloum] !='O' ){
        Array[row][coloum]='O';
        token='X';
    }
    else{
        cout<< " There is no empty space ."<<endl;
        EnterValue();
    }

}

bool CheckWin(){
    //Player win or not
    for(int i=0;i<3;i++){
        if(Array[i][0]==Array[i][1] && Array[i][0]==Array[i][2] || Array[0][i]==Array[1][i] && Array[0][i]==Array[2][i]){
            return true;
        }
    }
    if(Array[0][0]==Array[1][1] && Array[0][0]==Array[2][2] || Array[0][2]==Array[1][1] && Array[0][2]==Array[2][0]){
        return true;
    }

    //Game is still going on condition
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(Array[i][j]!='X' && Array[i][j]!='O'){
                return false;
            }
        }
    }
    tie=true;
    return true;

}
int main(){
    cout<<"Enter the name of first player : ";
    getline(cin,n1);
    cout<<"Enter the name of second player : ";
    getline(cin,n2);

    cout<<n1<<" is play first in place."<<endl;
    cout<<n2<<" is play second in place."<<endl;

    while( !CheckWin()){
        CreateBody();
        EnterValue();
        CheckWin();
    }

    if( token =='X' && tie==false){
        cout<< n2 << " Wins the Game!!!!!!"<<endl; 
    }
    else if( token == 'O' && tie == false){
        cout<< n1 <<" Wins the Game!!!!!!!"<<endl;
    }
    else{
        cout<<"The match is tie....."<<endl;
    }
    return 0;
}