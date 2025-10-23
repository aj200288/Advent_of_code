filename = "input.txt"

# Read the data from the file
with open(filename, "r") as file:
    data = file.read()

# Split the data into lines and create a 2D array
arr = [list(line) for line in data.splitlines()]

num_rows = len(arr)
num_char = len(arr[0])
# ------------------------

# 1. del


def checkM(row, char, arr):
    # vrne seznam pozicij M relativno na X
    posM = []
    il, jl = -1, -1
    iu, ju = 2, 2

    if row < 3:
        il = 0
    if row > num_rows-4:
        iu = 1
    if char < 3:
        jl = 0
    if char > num_char-4:
        ju = 1

    for i in range(il, iu):
        for j in range(jl, ju):
            if arr[row+i][char+j] == 'M':
                posM.append((i, j))

    return (posM)


sum1 = 0
posM = []
for row in range(num_rows):
    for char in range(num_char):
        if arr[row][char] == 'X':
            posM = checkM(row, char, arr)

            for tuple in posM:
                if arr[row+tuple[0]*2][char+tuple[1]*2] == 'A' and arr[row+tuple[0]*3][char+tuple[1]*3] == 'S':
                    sum1 += 1

print("Prvi del:", sum1)


# 2.del


def X(row, char, arr):
    if not (row == 0 or char == 0 or row == num_rows-1 or char == num_char-1):
        word1 = [0, 'A', 0]
        word2 = [0, 'A', 0]

        word1[0] = arr[row-1][char-1]
        word1[2] = arr[row+1][char+1]
        word2[0] = arr[row-1][char+1]
        word2[2] = arr[row+1][char-1]

        word1 = ''.join(word1)
        word2 = ''.join(word2)

        legal = ("SAM", "MAS")
        if word1 in legal and word2 in legal:
            return True

    else:
        return False


sum2 = 0
for row in range(num_rows):
    for char in range(num_char):
        if arr[row][char] == 'A':
            if X(row, char, arr):
                sum2 += 1

print("Drugi del:", sum2)
