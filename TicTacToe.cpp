#include<iostream>

using namespace std;

char win_condition(const char &game_board)
{
    for(int i = 0; i < M; ++i) {
    for(int j = 0; j < N; ++j) {
    if (i == 0 && j == 0){    
    if(game_board[i][j] == game_board[i + 1][j] && game_board[i + 1][j] == game_board[i + 2][j]|| 
    game_board[i][j] == game_board[i + 1][j + 1] && game_board[i + 1][j + 1] == game_board[i + 2][j + 2]
    ||game_board[i][j] == game_board[i][j + 1] && game_board[i][j + 1] == game_board[i][j + 2]){
        return game_board[i][j];
    }
      }
    if(i == 0 && j == 1){
        if(game_board[i][j] == game_board[i + 1][j] && game_board[i + 1][j] == game_board[i + 2][j]){
            return game_board[i][j];
        }
    }
    if(i == 0 && j == 2){
        if(game_board[i][j] == game_board[i + 1][j] && game_board[i + 1][j] == game_board[i + 2][j]|| 
    game_board[i][j] == game_board[i + 1][j - 1] && game_board[i + 1][j - 1] == game_board[i + 2][j - 2]){
        return game_board[i][j];
    }
    }
    if(i == 1 && j == 0){
    if(game_board[i][j] == game_board[i][j + 1] && game_board[i][j + 1] == game_board[i][j + 2]){
            return game_board[i][j];
        }
    }
    if (i == 2 && j == 0){
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
    const int M = 3;
    const int N = 3;
    char game_board[M][N];
    
// Initializing each cell to zero
for(int i = 0; i < M; ++i) {
for(int j = 0; j < N; ++j) {
        game_board[i][j] = '_';
}
}
char input,winner;
int row,col,countt = 0;

while(true){
cin>>input>>row>>col;
if (input == 'O' || input == 'X'){
    if (game_board[row][col] == '_'){
        game_board[row][col] = input;
        countt = countt + 1;
        winner = win_condition()
    }
}

for(int i = 0; i < M; ++i) {
for(int j = 0; j < N; ++j) {
        cout<<game_board[i][j];
}
cout<<endl;
}
if(countt > 8){
    break;
}

}

}
