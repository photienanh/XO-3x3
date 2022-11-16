#include<iostream>
#include<string>
using namespace std;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//create render
void render(){
     cout<<"-------------"<<endl;
              for(int i=0;i<3;i++){
                cout<<"| ";
                for(int j=0;j<3;j++){
                    cout<<space[i][j]<<" | ";
                }
                cout<<endl<<"-------------"<<endl;
                
              }                                                                                                
}
//get whose next turn
char nextPlayer(){
    int countX=0,countO=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]=='X')countX++;
            else if(space[i][j]=='O')countO++; 
        }
    }
    if(countX==countO) return 'X';
    else if(countX>countO) return 'O';
}
//check win or draw
int checkEnd(){
    /*X win*/
    //Row
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1]&&space[i][0]==space[i][2]&&space[i][0]=='X') return 1;
    }
    //Collumn
    for(int j=0;j<3;j++){
        if(space[0][j]==space[1][j]&&space[0][j]==space[2][j]&&space[0][j]=='X') return 1;
    }
    //Cross
    if(space[0][0]==space[1][1]&&space[0][0]==space[2][2]&&space[0][0]=='X') return 1;
    if(space[0][2]==space[1][1]&&space[0][2]==space[2][0]&&space[2][0]=='X') return 1;
    /*O win*/
    //Row
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1]&&space[i][0]==space[i][2]&&space[i][0]=='O') return 2;
    }
    //Collumn
    for(int j=0;j<3;j++){
        if(space[0][j]==space[1][j]&&space[0][j]==space[2][j]&&space[0][j]=='O') return 2;
    }
    //Cross
    if(space[0][0]==space[1][1]&&space[0][0]==space[2][2]&&space[0][0]=='O') return 2;
    if(space[0][2]==space[1][1]&&space[0][2]==space[2][0]&&space[2][0]=='O') return 2;
    /*not end*/
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]>='1' && space[i][j]<='9') return -1;
        }
    }
    return 0;//draw
}
//enter X or O in the state
void playgame(char n){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]==n){
                if(nextPlayer()=='X') space[i][j]='X';
                else if(nextPlayer()=='O') space[i][j]='O';
            }
        }
    }
}
int main(){
    char n;
    //enter players' names
    string name1; 
    string name2;
    cout<<"Enter first player's name: "<<endl;;
    getline(cin,name1);
    cout<<"Enter second player's name: "<<endl;
    getline(cin,name2);
    cout<<name1<<" :X"<<endl<<name2<<" :O"<<endl<<endl;
    render();
    //start game
    for(int i=1;i<=9;i++){
        if(nextPlayer()=='X') cout<<"It's "<<name1<<"'s turn, please choose your move: ";;
        if(nextPlayer()=='O') cout<<"It's "<<name2<<"'s turn, please choose your move: ";
        cin>>n;
        if(n<'1'||n>'9') {
            cout<<"invalid";
            break;
        }
        else{
        playgame(n);
        render();
        if(checkEnd()==1){
            cout<<name1<<" win";
            return 0;
        }
        if(checkEnd()==2){
            cout<<name2<<" win";
            return 0;
        }
        if(checkEnd()==0){
            cout<<"A draw";
            return 0;
        }
        }
    }
    
}
