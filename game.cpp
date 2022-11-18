#include<iostream>
#include<string>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//create render
void render(){
     cout<<"-------------"<<endl;
              for(int i=0;i<3;i++){
                cout<<"| ";
                for(int j=0;j<3;j++){
                    cout<<board[i][j]<<" | ";
                }
                cout<<endl<<"-------------"<<endl;
                
              }                                                                                                
}
//get whose next turn
char nextPlayer(){
    int countX=0,countO=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='X')countX++;
            else if(board[i][j]=='O')countO++; 
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
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]&&board[i][0]=='X') return 1;
    }
    //Collumn
    for(int j=0;j<3;j++){
        if(board[0][j]==board[1][j]&&board[0][j]==board[2][j]&&board[0][j]=='X') return 1;
    }
    //Cross
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]=='X') return 1;
    if(board[0][2]==board[1][1]&&board[0][2]==board[2][0]&&board[2][0]=='X') return 1;
    /*O win*/
    //Row
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]&&board[i][0]=='O') return 2;
    }
    //Collumn
    for(int j=0;j<3;j++){
        if(board[0][j]==board[1][j]&&board[0][j]==board[2][j]&&board[0][j]=='O') return 2;
    }
    //Cross
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]=='O') return 2;
    if(board[0][2]==board[1][1]&&board[0][2]==board[2][0]&&board[2][0]=='O') return 2;
    /*not end*/
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]>='1' && board[i][j]<='9') return -1;
        }
    }
    return 0;//draw
}
//select your move
void playgame(char n){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==n){
                if(nextPlayer()=='X') board[i][j]='X';
                else if(nextPlayer()=='O') board[i][j]='O';
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
            cout<<"invalid"<<endl;
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
        else{ playgame(n);
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
