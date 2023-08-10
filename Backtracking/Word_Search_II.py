class TrieNode:
    def __init__(self):
        self.children = {}
        self.isWord = False

    def add_word(self, word):
        current = self
        for c in word:
            if c not in current.children:
                current.children[c] = TrieNode()
            current = current.children[c]
        current.isWord = True

def word_search(board, words):
    root = TrieNode()

    for w in words:
        root.add_word(w)

    rows = len(board)
    columns = len(board[0])
    result = set()
    visit = set()

    def dfs(r, c, node, word):
        if r < 0 or c < 0 or r == rows or c == columns or (r, c) in visit or board[r][c] not in node.children:
            return

        visit.add((r, c))
        node = node.children[board[r][c]]
        word += board[r][c]
        if node.isWord:
            result.add(word)

        dfs(r + 1, c, node, word)
        dfs(r - 1, c, node, word)
        dfs(r, c + 1, node, word)
        dfs(r, c - 1, node, word)

        visit.remove((r, c))

        return result

    for r in range(rows):
        for c in range(columns):
            dfs(r, c, root, '')

    return list(result)