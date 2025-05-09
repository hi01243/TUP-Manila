"""""
Study the simple Tic Tac Toe program attached below. Modify the game such that a player (player X) plays against the computer (player 0). The computer must have all of the following features.
Tries to win if possible.
Blocks your winning move.

Takes center if available.

Prefers corners over edges.
"""

def print_board(board):
    print("\n")
    for row in board:
        print(" | ".join(row))
        print("-"*10)
    print("\n")

def print_Iboard():
    print("\nInstruction board: \n")
    for i in range(3):
        row = [str(i *3 + j + 1) for j in range(3)]
        print(" | ".join(row))
        print("-"*10)
def check_winner(board, player):
    # Check rows, columns, and diagonals
    for i in range(3):
        if all([cell == player for cell in board[i]]):  # Rows
            return True
        if all([board[j][i] == player for j in range(3)]):  # Columns
            return True
    if all([board[i][i] == player for i in range(3)]):  # Main diagonal
        return True
    if all([board[i][2 - i] == player for i in range(3)]):  # Anti-diagonal
        return True
    return False

def is_full(board):
    return all(cell != ' ' for row in board for cell in row)

def play_game():
    board = [[' ' for _ in range(3)] for _ in range(3)]
    current_player = 'X'
    print_Iboard()
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

        if check_winner(board, current_player):
            print_board(board)
            print(f"🎉 Player {current_player} wins!")
            break
        elif is_full(board):
            print_board(board)
            print("It's a draw!")
            break

        # Switch player
        comp = computer(board, current_player, row,col)
        if comp == True:
            comp == 'O'
        current_player = 'X' if current_player == comp else 'X'

def computer(board, current_player, row,col):
    if board[1][1] == ' ':
        return True;

# Start the game
play_game()
