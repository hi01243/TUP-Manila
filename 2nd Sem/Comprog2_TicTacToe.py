import os
"""""
Study the simple Tic Tac Toe program attached below. Modify the game such that a player (player X) plays against the computer (player 0). The computer must have all of the following features.
Tries to win if possible.
Blocks your winning move.

Takes center if available.

Prefers corners over edges.
"""

def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-"*10)

def print_Iboard():
    print("\nInstruction board: \n")
    for i in range(3):
        row = [str(i *3 + j + 1) for j in range(3)]
        print(" | ".join(row))
        print("-"*10)
def check_winner(board):
    # Check rows, columns, and diagonals
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] != ' ':
            if board[i][0] == 'X':
                return 'X'
            else: return 'O'
        if board[0][i] == board[1][i] == board[2][i] != ' ':
            if board[i][0] == 'X':
                return 'X'
            else: return 'O'
    if board[0][0] == board[1][1] == board[2][2] != ' ':
        if board[i][0] == 'X':
                return 'X'
        else: return 'O'
    if board[0][2] == board[1][1] == board[2][0] !=' ':
        if board[i][0] == 'X':
                return 'X'
        else: return 'O'
    
    return False

def is_full(board):
    return all(cell != ' ' for row in board for cell in row)

def play_game():
    board = [[' ' for _ in range(3)] for _ in range(3)]
    current_player = 'X'
    print_Iboard()
    os.system('pause')
    os.system('cls')
    while True:
        print_board(board)
        try:
            pos = int(input("Enter position 1-9 to put : "))
            row = (pos - 1) // 3
            col = (pos - 1) % 3

        except ValueError:
            print("Please enter valid numbers.")
            continue

        if board[row][col] != ' ':
            print("Cell already taken. Try again.")
            continue

        board[row][col] = current_player

        if check_winner(board):
            print_board(board)
            print(f"🎉 Player {current_player} wins!")
            break
        elif is_full(board):
            print_board(board)
            print("It's a draw!")
            break 
    preferred_moves = [
        (1, 1), 
        (0, 0), (0, 2), (2, 0), (2, 2),  
        (0, 1), (1, 0), (1, 2), (2, 1)   
    ]

    for row, col in preferred_moves:
        if board[row][col] == ' ':
            board[row][col] = 'O'
    
play_game()
