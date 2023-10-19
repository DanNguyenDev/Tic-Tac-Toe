#include <iostream>
#include <string>

using namespace std;

// Create the prototype function for the first player's turn

void firstPlayerturn(char array_board[], string first_name);

// Create the prototype function for the second player's turn

void secondPlayerturn(char array_board[], string second_name);


int main()
{
    string key;
    string first_name;
    string second_name;
    bool decision = true;
    
    // Output to the user to start the game and ask for input
    
    cout << "Pleae enter START to begin the game or QUIT to end the application: ";
    cin >> key;
    
    // Make an if statement if quit is selected
    
    if(key == "QUIT" || key == "quit")
    {
        cout << "Program has ended. Thank you for trying tictactoe by Daniel Nguyen!" << endl;
        return 0;
    }
    
    // Make a while loop is START is not consoled in
    
    if(key != "START" && key != "start")
    {
        
        while(decision)
        {
        
        // Output the message to start or quit the game again and ask for input
        
        cout << "Please enter START to begin the game or QUIT to end the application: ";
        cin >> key;
        
        // Make an if statement if quit is selected
        
        if(key == "QUIT" || key == "quit")
        {
            cout << "Program has ended. Thank you for trying tictactoe by Daniel Nguyen!" << endl;
            return 0;
        }
        
        // Make an if statement if the key is == to start
        
        if(key == "START" || key == "start")
        {
            decision = false;
        }
            
        }
        
    }
    
    // Ask the 2 players to input their names and which player is representing what O or X
    
    cout << "Please enter the player representing the X's on the tictactoe board: " << endl;
    cin >> first_name;
    
    
    cout << "Please enter the player representing the O's on the tictactoe board: " << endl;
    cin >> second_name;
    cout << endl;
    
    // Make an array displaying the tictactoe board
    
    char array_board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    // Display the first row
    
    cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
    cout << "__________" << endl << endl;
    
    // Display the second row
    
    cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
    cout << "__________" << endl << endl;
    
    // Display the third row
    
    cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
    cout << endl;
    
    // Call out the function for the first player and the second player
    // Use a loop to make it repeat the functions until a person wins or a tie breaks out
    
    int turn = 0;
    while(turn < 10)
    {
        
    // Call out the first player's turn and increase the turn level after function is done
        
    firstPlayerturn(array_board, first_name);
    
    turn = turn + 1;
        
        // Make an if statement that will break out of the loop if the player gets
        // 3 in a row (Horizontal combinations to win)
        
        
        if((array_board[0] == 'O' && array_board[1] == 'O' && array_board[2] == 'O')
           || (array_board[3] == 'O' && array_board[4] == 'O' && array_board[5] == 'O')
           || (array_board[6] == 'O' && array_board[7] == 'O' && array_board[8] == 'O')
           
           // Vertical combinations to win
           
           || (array_board[0] == 'O' && array_board[3] == 'O' && array_board[6] == 'O')
           || (array_board[1] == 'O' && array_board[4] == 'O' && array_board[7] == 'O')
           || (array_board[2] == 'O' && array_board[5] == 'O' && array_board[8] == 'O')
            
           // Diagonal combinations to win
           
           || (array_board[0] == 'O' && array_board[4] == 'O' && array_board[8] == 'O')
           || (array_board[2] == 'O' && array_board[4] == 'O' && array_board[6] == 'O'))
        {
            cout << first_name << " wins! " << first_name <<  " got 3 in a row!" << endl;
            cout << "Thanks for playing!" << endl;
            break;
        }
        
    if(turn == 9)
    {
            
        cout << "A tie! Neither " << first_name << " or " << second_name
             << " wins! Thanks for playing!" << endl;
        break;
    }
      
    // Call out the second player's turn and increase the turn level after function is done
            
    secondPlayerturn(array_board, second_name);
            
    turn = turn + 1;
        
        // Make an if statement that will break out of the loop if the player gets
        // 3 in a row (Horizontal combinations to win)
        
        
        if((array_board[0] == 'X' && array_board[1] == 'X' && array_board[2] == 'X')
           || (array_board[3] == 'X' && array_board[4] == 'X' && array_board[5] == 'X')
           || (array_board[6] == 'X' && array_board[7] == 'X' && array_board[8] == 'X')
           
           // Vertical combinations to win
           
           || (array_board[0] == 'X' && array_board[3] == 'X' && array_board[6] == 'X')
           || (array_board[1] == 'X' && array_board[4] == 'X' && array_board[7] == 'X')
           || (array_board[2] == 'X' && array_board[5] == 'X' && array_board[8] == 'X')
            
           // Diagonal combinations to win
           
           || (array_board[0] == 'X' && array_board[4] == 'X' && array_board[8] == 'X')
           || (array_board[2] == 'X' && array_board[4] == 'X' && array_board[6] == 'X'))
        {
            cout << second_name << " wins! " << second_name <<  " got 3 in a row!" << endl;
            cout << "Thanks for playing!" << endl;
            break;
        }
        
    if(turn == 9)
    {
        
        cout << "A tie! Neither " << first_name << " " << second_name
             << " wins! Thanks for playing@" << endl;
        break;
    }
        
    }
    
    return 0;
}

void firstPlayerturn(char array_board[], string first_name)
{
    char decision1;
    
    // Display the first player's turn which is X's and ask for input
    
    cout << first_name << "'s turn. Please pick a valid square: ";
    cin >> decision1;
    cout << endl;
    
    // Make a input validation so the player does not input in an already selected square
    
    if(decision1 == '1')
    {
        if(array_board[0] == 'X' || array_board[0] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision1 == '1')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision1;
            }
        }
    }
    
    // Input validation for square 2
    
    if(decision1 == '2')
    {
        if(array_board[1] == 'X' || array_board[1] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision1 == '2')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision1;
            }
        }
    }
    
    // Input validation for square 3
    
    if(decision1 == '3')
    {
        if(array_board[2] == 'X' || array_board[2] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision1 == '3')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision1;
            }
        }
    }
    
    // Input validation for square 4
    
    if(decision1 == '4')
    {
        if(array_board[3] == 'X' || array_board[3] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision1 == '4')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision1;
            }
        }
    }
    
    // Input validation for square 5
    
    if(decision1 == '5')
    {
        if(array_board[4] == 'X' || array_board[4] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision1 == '5')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision1;
            }
        }
    }
    
    // Input validation for square 6
    
    if(decision1 == '6')
    {
        if(array_board[5] == 'X' || array_board[5] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision1 == '6')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision1;
            }
        }
    }
    
    // Input validation for square 7
    
    if(decision1 == '7')
    {
        if(array_board[6] == 'X' || array_board[6] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision1 == '7')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision1;
            }
        }
    }
    
    // Input validation for square 8
    
    if(decision1 == '8')
    {
        if(array_board[7] == 'X' || array_board[7] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision1 == '8')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision1;
            }
        }
    }
    
    // Input validation for square 9
    
    if(decision1 == '9')
    {
        if(array_board[8] == 'X' || array_board[8] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision1 == '9')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision1;
            }
        }
    }
    
    // If the player makes it though the validation the convert the decision to '#' to 'O"
    
    if(decision1 == '1')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[0] = 'O';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision1 == '2')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[1] = 'O';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision1 == '3')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[2] = 'O';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision1 == '4')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[3] = 'O';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision1 == '5')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[4] = 'O';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision1 == '6')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[5] = 'O';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision1 == '7')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[6] = 'O';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision1 == '8')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[7] = 'O';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision1 == '9')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[8] = 'O';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
}


// Create the function for the second player's turn

void secondPlayerturn(char array_board[], string second_name)
{
    char decision2;
    
    // Display the first player's turn which is X's and ask for input
    
    cout << second_name << "'s turn. Please pick a valid square: ";
    cin >> decision2;
    cout << endl;
    
    // Make a input validation so the player does not input in an already selected square
    
    if(decision2 == '1')
    {
        if(array_board[0] == 'X' || array_board[0] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision2 == '1')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision2;
            }
        }
    }
    
    // Input validation for square 2
    
    if(decision2 == '2')
    {
        if(array_board[1] == 'X' || array_board[1] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision2 == '2')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision2;
            }
        }
    }
    
    // Input validation for square 3
    
    if(decision2 == '3')
    {
        if(array_board[2] == 'X' || array_board[2] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision2 == '3')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision2;
            }
        }
    }
    
    // Input validation for square 4
    
    if(decision2 == '4')
    {
        if(array_board[3] == 'X' || array_board[3] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision2 == '4')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision2;
            }
        }
    }
    
    // Input validation for square 5
    
    if(decision2 == '5')
    {
        if(array_board[4] == 'X' || array_board[4] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision2 == '5')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision2;
            }
        }
    }
    
    // Input validation for square 6
    
    if(decision2 == '6')
    {
        if(array_board[5] == 'X' || array_board[5] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision2 == '6')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision2;
            }
        }
    }
    
    // Input validation for square 7
    
    if(decision2 == '7')
    {
        if(array_board[6] == 'X' || array_board[6] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision2 == '7')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision2;
            }
        }
    }
    
    // Input validation for square 8
    
    if(decision2 == '8')
    {
        if(array_board[7] == 'X' || array_board[7] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision2 == '8')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision2;
            }
        }
    }
    
    // Input validation for square 9
    
    if(decision2 == '9')
    {
        if(array_board[8] == 'X' || array_board[8] == 'O')
        {
            // Make a while loop and state that the selection is invalid
            // because it has already been taken
            
            while(decision2 == '9')
            {
                cout << "Invalid Input. That choice has already been selected. Please choose again: ";
                cin >> decision2;
            }
        }
    }
    
    // If the player makes it though the validation the convert the decision to '#' to 'O"
    
    if(decision2 == '1')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[0] = 'X';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision2 == '2')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[1] = 'X';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision2 == '3')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[2] = 'X';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision2 == '4')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[3] = 'X';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision2 == '5')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[4] = 'X';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision2 == '6')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[5] = 'X';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision2 == '7')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[6] = 'X';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision2 == '8')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[7] = 'X';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
    if(decision2 == '9')
    {
        
        // Convert the selected square to a O for the first player
        
        array_board[8] = 'X';
        
        // Diaplay the new converted tictactoe board
        
        cout << array_board[0] << " | " << array_board[1] << " | " << array_board[2] << endl;
        cout << "__________" << endl << endl;
        
        // Display the second row
        
        cout << array_board[3] << " | " << array_board[4] << " | " << array_board[5] << endl;
        cout << "__________" << endl << endl;
        
        // Display the third row
        
        cout << array_board[6] << " | " << array_board[7] << " | " << array_board[8] << endl;
        cout << endl;
        
    }
    
}
