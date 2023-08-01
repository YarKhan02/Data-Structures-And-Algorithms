def is_safe(board, row, col, N, row_lookup, diag1_lookup, diag2_lookup):
    # Check if a queen can be placed at (row, col) safely
    if row_lookup[col] or diag1_lookup[row + col] or diag2_lookup[row - col]:
        return False
    return True


def solve_nqueens(board, row, N, row_lookup, diag1_lookup, diag2_lookup, solutions):
    # Base case: if all queens are placed, add the solution to the list
    if row == N:
        solution = [''.join(['Q' if cell == 1 else '.' for cell in row]) for row in board]
        solutions.append(solution)
        return

    for col in range(N):
        if is_safe(board, row, col, N, row_lookup, diag1_lookup, diag2_lookup):
            board[row][col] = 1
            row_lookup[col] = True
            diag1_lookup[row + col] = True
            diag2_lookup[row - col] = True
            solve_nqueens(board, row + 1, N, row_lookup, diag1_lookup, diag2_lookup, solutions)
            board[row][col] = 0
            row_lookup[col] = False
            diag1_lookup[row + col] = False
            diag2_lookup[row - col] = False


def nqueens(N):
    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []
    row_lookup = [False] * N
    diag1_lookup = [False] * (2 * N - 1)
    diag2_lookup = [False] * (2 * N - 1)
    solve_nqueens(board, 0, N, row_lookup, diag1_lookup, diag2_lookup, solutions)
    return solutions


if __name__ == "__main__":
    N = 4  # Change N to the desired board size
    solutions = nqueens(N)
    for i, solution in enumerate(solutions):
        print(f"Solution {i+1}:")
        for row in solution:
            print(row)
        print()
