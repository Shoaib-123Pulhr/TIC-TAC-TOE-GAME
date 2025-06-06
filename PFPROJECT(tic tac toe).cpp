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
int xWins = 0, oWins = 0;
string playerX;
string playerO;

void playermove_board() {
    system("cls");
    cout << endl << endl;
    cout << "      TIC    TAC    TOE   GAME     " << endl;
    cout << "******************************************************" << endl;
    cout << playerX << " [X]  vs  " << playerO << " [O]" << endl;
    cout << "Wins: " << playerX << " = " << xWins << " | " << playerO << " = " << oWins << endl;
    cout << "******************************************************" << endl;

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

void representative_board() {
    if (turn == 'X')
        cout << "Player " << playerX << "'s turn: ";
    else
        cout << "Player " << playerO << "'s turn: ";

    cin >> number;
    // FOR  PLACING THE NUMBER IN TABLE WHICH IS CHOOSED BY THE USER

    switch (number) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
    //  IF USER ENTER A INVALID CHOICE THEN!!!!
        default:
            cout << "You've chosen an invalid number!" << endl;
            cout << "TRY AGAIN!" << endl;
            return;
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Box already filled. Try another!" << endl;
        system("pause");
    }

    playermove_board();
}

bool gameover() {
    // CHACKING FOR WINS IN REGARD OF ROWS AND COLUMNS
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
            return false;
    }

    // CHACKING IN REGARD OF DIAGONAL WINS!!!
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return false;
    // CHECKING FOR INCOMPLETE GAMES
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;
    // IF THER IS NO EMPTY SPACE AND WINNERS IT'S FINALLY A DRW!!!!!!

    draw = true;
    return false;
}

void reset_board() {
    char ch = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ch++;
}

int main() {
    char again;
    // TO GET THE PLAYER NAME FROM USER
    cout << "Enter name for Player X: ";
    getline(cin, playerX);
    cout << "Enter name for Player O: ";
    getline(cin, playerO);

    do {
        reset_board();
        turn = 'X';
        draw = false;
        playermove_board();

        while (gameover()) {
            representative_board();
        }

        if (turn == 'X' && !draw) {
            cout << playerO << " [O] wins!" << endl;
            oWins++;
        } else if (turn == 'O' && !draw) {
            cout << playerX << " [X] wins!" << endl;
            xWins++;
        } else {
            cout << "Game DRAW!" << endl;
        }
        // FOR SCORE-BOARD ABOUT  RECORDS OF WINS 
        cout << "\nSCOREBOARD => " << playerX << ": " << xWins << " | " << playerO << ": " << oWins << endl;
        cout << "\nDo you want to play again? (y/n): ";
        cin >> again;
        cin.ignore();

    } while (again == 'y' || again == 'Y');

    cout << "\nThanks for playing!" << endl;
    return 0;
}
