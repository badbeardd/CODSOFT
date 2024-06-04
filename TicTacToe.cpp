#include<iostream>
#include<cstdlib>
using namespace std;

    const int M = 3;
    const int N = 3;
    const char player1 = 'X';
    const char player2 = 'O';
char win_condition(const char (&game_board)[M][N])
{
    for(int i = 0; i < M; ++i) {
    for(int j = 0; j < N; ++j) {
    if (i == 0 && j == 0 && game_board[i][j] == 'X' || i == 0 && j == 0 && game_board[i][j] == 'O'){
    if(game_board[i][j] == game_board[i + 1][j] && game_board[i + 1][j] == game_board[i + 2][j]||
    game_board[i][j] == game_board[i + 1][j + 1] && game_board[i + 1][j + 1] == game_board[i + 2][j + 2]
    ||game_board[i][j] == game_board[i][j + 1] && game_board[i][j + 1] == game_board[i][j + 2]){
        return game_board[i][j];
    }
      }
    if(i == 0 && j == 1 && game_board[i][j] == 'X' || i == 0 && j == 1 && game_board[i][j] == 'O'){
        if(game_board[i][j] == game_board[i + 1][j] && game_board[i + 1][j] == game_board[i + 2][j]){
            return game_board[i][j];
        }
    }
    if(i == 0 && j == 2 && game_board[i][j] == 'X' || i == 0 && j == 2 && game_board[i][j] == 'O'){
        if(game_board[i][j] == game_board[i + 1][j] && game_board[i + 1][j] == game_board[i + 2][j]||
    game_board[i][j] == game_board[i + 1][j - 1] && game_board[i + 1][j - 1] == game_board[i + 2][j - 2]){
        return game_board[i][j];
    }
    }
    if(i == 1 && j == 0 && game_board[i][j] == 'X' || i == 1 && j == 0 && game_board[i][j] == 'O'){
    if(game_board[i][j] == game_board[i][j + 1] && game_board[i][j + 1] == game_board[i][j + 2]){
            return game_board[i][j];
        }
    }
    if (i == 2 && j == 0 && game_board[i][j] == 'X' || i == 2 && j == 0 && game_board[i][j] == 'O'){
    if(game_board[i][j] == game_board[i][j + 1] && game_board[i][j + 1] == game_board[i][j + 2]){
        return game_board[i][j];
    }
    }
}
}
return 0;
}
int main()
{
    while(true){
    char game_board[M][N];

// Initializing each cell to zero
for(int i = 0; i < M; ++i) {
for(int j = 0; j < N; ++j) {
        game_board[i][j] = '_';
}
}

char input,winner,response;
int row,col,countt = 0,turn = 1;

while(true){
cout<<"Game Board"<<endl;
for(int i = 0; i < M; ++i) {
for(int j = 0; j < N; ++j) {
        cout<<game_board[i][j];
}
cout<<endl;
}

cout<<"Give the Player input and respective row and column:";
cin>>input>>row>>col;
if (input == player2 || input == player1){
    if (game_board[row][col] == '_'){
     if (turn == 1 && input == player1){
        game_board[row][col] = input;
        turn = 0;
     }
     if (turn == 0 && input == player2){
        game_board[row][col] = input;
        turn = 1;
     }
        system("cls");
        countt = countt + 1;
        winner = win_condition(game_board);
    }
}


if(countt > 8 || winner != '\0'){
    break;
}

}
if (winner != '\0'){
if (winner == player1){
cout<<"player1 wins"<<endl;
}
else{
    cout<<"player2 wins"<<endl;
}
}
else{
    cout<<"Draw"<<endl;
}
cout<<"Play Again? Y or N: ";
cin>>response;
if(response == 'N'){
    break;
}
else{
    cout<<"Restarted"<<endl;
}
}
return 0;
}
