def is_safe(board, row, col, N):
    # Check if a queen can be placed at (row, col) safely
    # Check column
    for i in range(row):
        if board[i][col] == 1:
            return False

    # Check upper left diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check upper right diagonal
    for i, j in zip(range(row, -1, -1), range(col, N)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens(board, row, N, solutions):
    # Base case: if all queens are placed, add the solution to the list
    if row == N:
        solution = [''.join(['Q' if cell == 1 else '.' for cell in row]) for row in board]
        solutions.append(solution)
        return

    for col in range(N):
        if is_safe(board, row, col, N):
            board[row][col] = 1
            solve_nqueens(board, row + 1, N, solutions)
            board[row][col] = 0  # Backtrack


def nqueens(N):
    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []
    solve_nqueens(board, 0, N, solutions)
    return solutions


if __name__ == "__main__":
    N = 4 # Change N to the desired board size
    solutions = nqueens(N)
    for i, solution in enumerate(solutions):
        print(f"Solution {i+1}:")
        for row in solution:
            print(row)
        print()
