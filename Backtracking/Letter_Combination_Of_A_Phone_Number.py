def letter_combination(digits):
    result = []
    digitToChar = { '2': 'abc',
                    '3': 'def',
                    '4': 'ghi',
                    '5': 'jkl',
                    '6': 'mno',
                    '7': 'pqrs',
                    '8': 'tuv',
                    '9': 'wxyx'}

    def backtrack(i, current):
        if len(current) == len(digits):
            result.append(current)
            return
        
        for c in digitToChar[digits[i]]:
            backtrack(i + 1, current + c)

    if digits:
        backtrack(0, '')

    return result


digits = ''
print(letter_combination(digits)) 