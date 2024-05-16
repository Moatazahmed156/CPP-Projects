#include <bits/stdc++.h>
using namespace std;

char board[3][3]; // 3x3 Tic Tac Toe board
// Function to initialize the board
void initBoard()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = ' ';
        }
    }
}
// Function to display the Tic Tac Toe board
void displayBoard()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
// Function to check if a player has won
bool checkWin(char player)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}
// Function to check if the board is full
bool checkDraw()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
int main()
{
    initBoard(); // Initialize the board
    char currentPlayer = 'X';
    while (true)
    {
        displayBoard();
        // Get player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        // Check if the cell is empty and within bounds
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        {
            cout << "Invalid move! Try again." << endl;
            continue;
        }
        // Make the move
        board[row][col] = currentPlayer;
        // Check if the current player has won
        if (checkWin(currentPlayer))
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        // Check for a draw
        if (checkDraw())
        {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }
        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}