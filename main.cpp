#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>>& board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool rowCrossed(vector<vector<char>>& board)
{
    for (int i=0; i<board.size(); i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
            return true;
    }
    return false;
}

bool columnCrossed(vector<vector<char>>& board)
{
    for (int i=0; i<board.size(); i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
            return true;
    }
    return false;
}

bool diagonalCrossed(vector<vector<char>>& board)
{
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
        return true;
          
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
        return true;
  
    return false;
}

bool isGameOver(vector<vector<char>>& board)
{
    if(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board)){
        return true;
    }

    return false;
}

bool isBoardFilled(vector<vector<char>>& board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == '-'){
                return false;
            }
        }
    }
    return true;
}

bool playerMove(vector<vector<char>>& board, pair<char, string> currPlayer, int row, int col){
    if(board[row][col] != '-'){
        cout<<"Invalid Move"<<endl<<endl;
        return false;
    }

    board[row][col] = currPlayer.first;  
    printBoard(board); 
    
    if(isGameOver(board)){
        cout<<currPlayer.second<<" won the game."<<endl;
    }

    else if(isBoardFilled(board)){
        cout<<"GameOver"<<endl;
    }
    return true; 
};

void initializeBoard(vector<vector<char>>& board, int boardSize = 3){
    vector<char> temp;
    for(int i=0; i<boardSize; i++){
        temp.push_back('-');
    }
    for(int i=0; i<boardSize; i++){
        board.push_back(temp);
    }
}

int main(){
    int numberOfPlayers;
    cin>>numberOfPlayers;

    deque<pair<char, string>> players;
    for(int i=0; i<numberOfPlayers; i++){
        char piece;
        string playerName;
        cin>>piece>>playerName;
        players.push_back(make_pair(piece, playerName));
    }

    vector<vector<char>> board;
    initializeBoard(board);
    printBoard(board);

    while(true){
        string input;
        cin>>input;
        if(input == "exit"){
            return 0;
        }
        
        int row = stoi(input);
        int col;
        cin>>col;

        if(isGameOver(board) || isBoardFilled(board)){
            continue;
        }

        pair<char, string> currPlayer = players.front();
        bool move = playerMove(board, currPlayer, row-1, col-1);
        if(move){
            players.pop_front();
            players.push_back(currPlayer);
        }
    }
}
