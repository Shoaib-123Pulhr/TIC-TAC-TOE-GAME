# TIC-TAC-TOE-GAME
#include <iostream>
using namespace std;
char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};
  char turn = 'X';
int number;
int row, column;
bool draw = false;
void playermove_board()  
{
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "      TIC    TIC    TOE   GAME     " << endl;
    cout << "****************************************************************************************************" << endl;
    cout << "PLAYER1 [X]" << endl;
    cout << "PLAYER2 [O]" << endl;

    cout << "           |     |     " << endl;
    cout << "        " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
    cout << "      _____|_____|_____" << endl;
    cout << "           |     |     " << endl;
    cout << "        " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
    cout << "      _____|_____|_____" << endl;
    cout << "           |     |     " << endl;
    cout << "        " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
    cout << "           |     |     " << endl;
}
 void representative_board() 
 {
    if (turn == 'X')
        cout << "PLAYER1 [X]  turn:" << endl;
    else
        cout << "PLAYER2 [O]  turn:" << endl;

    cin >> number;

    switch (number) 
    {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
        // IF SOME BODY HAVE ENTERED IRRELEVANT NUMBER THEN;
            cout << "You've chosen an invalid number!" << endl;
            cout<<"TRY AGAIN !!!!!!!!!!!!!!!!!!!!" <<endl;
            return;
    }
    // FOR TURN OF PLAYER (1) OR "X"
      if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') 
    {
        board[row][column] = 'X';
        turn = 'O';
    } 
    // FOR TURN OF PLAYER (2) OR "O"
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') 
    {
        board[row][column] = 'O';
        turn = 'X';
    }
     // TO CHECK IF ALREADY FILLED BOX IS AGAIN ATTEMPTED BY PLAYER 
     else 
     {
        cout << " box has  already been  filled. " << endl;
        cout<<"please enter number to another box !!!!!!!!!!"<<endl;
    }

    playermove_board();
}
    // TO CHECK THE GAME IS OVER.
   bool gameover() 
   {
    // Check win - rows and columns
    for (int i = 0; i < 3; i++) 
    {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
            return false;
    }
     // Check diagonals
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return false;
    // Check for incomplete game
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;  // Game is not over yet
        }
    }
    // If no empty space and no winner, it's a draw.
    draw = true;
    return false;
}
     int main() 
     {
    playermove_board();  // Initial display
     while (gameover()) 
     {
        representative_board();
    }
    // IF PLAYER (2) WINS 
    if (turn == 'X' && draw == false) 
    {
        cout << "Player [O] wins!!!!!" << endl;
        cout << "Congrats on winning the game!" << endl;
    }
    // IF PLAYER (1) WINS
     else if (turn == 'O' && draw == false) 
     {
        cout << "Player [X] wins!!!!!" << endl;
        cout << "Congrats on winning the game!" << endl;
    }
    // IF  NO ONE WINS TILL THE END OF GAME(WHEN ALL BOXES ARE COMPLETE)
     else 
     {
        cout << "GAME DRAW!!!!!!" << endl;
    }
    return 0;
}.
