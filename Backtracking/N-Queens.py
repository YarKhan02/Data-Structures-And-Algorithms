def n_queens(n):
    column = set()
    positiveDiognal = set()
    negativeDiognal = set()

    result = []
    board = [["."] * n for _ in range(n)]

    def backtrack(r):
        if r == n:
            copy = ["".join(row) for row in board]
            result.append(copy)
            return

        for c in range(n):
            if c in column or (r + c) in positiveDiognal or (r - c) in negativeDiognal:
                continue

            column.add(c)
            positiveDiognal.add(r + c)
            negativeDiognal.add(r - c)
            board[r][c] = "Q"

            backtrack(r + 1)

            column.remove(c)
            positiveDiognal.remove(r + c)
            negativeDiognal.remove(r - c)
            board[r][c] = "."

    backtrack(0)

    return result

print(n_queens(4)) 