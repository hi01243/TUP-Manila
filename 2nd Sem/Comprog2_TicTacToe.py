#FLORES, Earl John C.
import os

def print_board(board):
    print("-"*10)
    for row in board:
        print(" | ".join(row))
        print("-"*10)

def print_Iboard():
    print("\nInstruction board: \n")
    print("-"*10)
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
        if board[0][0] == 'X':
                return 'X'
        else: return 'O'
    if board[0][2] == board[1][1] == board[2][0] !=' ':
        if board[0][2] == 'X':
                return 'X'
        else: return 'O'
    
    return False

def is_full(board):
    return all(cell != ' ' for row in board for cell in row)

def preferred_moves(board):
    preferred_moves = [(1,1),(0,0), (0, 2), (2, 0), (2, 2), (0, 1), (1, 0), (1, 2), (2, 1) ]
    for row,col in preferred_moves:
        if board[row][col] == ' ':
            return (row,col)
    return None
            
def block(board,player):
    for i in range(3):
        
        row = board[i] #checks rows
        if row.count(player) == 2 and row.count(' ') == 1:
            col = board[i].index(' ')
            return (i,col)
        
        col = [board[0][i], board[1][i],board[2][i]] #chceks cols
        if col.count(player) == 2 and col.count(' ') == 1:
            row = col.index(' ')
            return (row,i)
        
    main_diag = [board[0][0],board[1][1],board[2][2]]
    anti_diag = [board[0][2],board[1][1],board[2][0]]

    if main_diag.count(player) == 2 and main_diag.count(' ') == 1:
        idx = main_diag.index(' ')
        return (idx,idx)
    if anti_diag.count(player) == 2 and anti_diag.count(' ') == 1:
        return (idx,2-idx)

    return None

def menu():
    print("")
    print('-'*30)
    print("       Tic-Tac-Toe Game")
    print('-'*30)
    print("Difficulty: Impossible to win")
    print('-'*30)
    print("1. Play as X (first)")
    print("2. Play as O (second)\n3. Exit")
    print('-'*30)
    x = int(input("Input choice: "))
    return x

def play_game(player):
    board = [[' ' for _ in range(3)] for _ in range(3)]
    current_player = 'X' if player == 'X' else 'O'
    print_Iboard()
    os.system('pause')
    os.system('cls')
    while True:
        print_board(board)
        if current_player == 'X':
            try:
                pos = int(input("Enter position 1-9 to put : "))
                row = (pos - 1) // 3
                col = (pos - 1) % 3

            except ValueError:
                print("Please enter valid numbers.")
                os.system('pause')
                os.system('cls')
                continue

            if board[row][col] != ' ':
                print("Cell already taken. Try again.")
                os.system('pause')
                os.system('cls')
                continue

        else:
            move = block(board,'O')
            if not move:
                move = block(board,'X')
            if not move:
                move = preferred_moves(board)
            row,col = move    
            os.system('cls')
            
        board[row][col] = current_player

        if check_winner(board):
            print_board(board)
            print(f"🎉 Player {current_player} wins!")
            os.system('pause')
            break
        elif is_full(board):
            print_board(board)
            print("It's a draw!")
            os.system('pause')
            break 
    
        current_player = 'O' if current_player == 'X' else 'X'

if __name__ == "__main__":
    while True:
        os.system('cls')
        match(menu()):
            case 1:
                play_game('X')
            case 2:
                play_game('O')
            case 3:
                print("Thank you for playing!")
                os.system('pause')
                break
            case _: 
                print("Invalid choice!") 
                os.system('cls')
                

