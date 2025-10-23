with open("input.txt", "r") as file:
    lines = file.readlines()

column1 = []
column2 = []

for line in lines:
    num1, num2 = map(int, line.split())
    column1.append(num1)
    column2.append(num2)

column1.sort()
column2.sort()

# prvi del
sum = 0
for el1, el2 in zip(column1, column2):
    sum += abs(el1-el2)

print("Prvi del: ", sum)

# drugi del
sum = 0
for num in column1:
    zmnozek = num * column2.count(num)
    sum += zmnozek
print("Drugi del: ", sum)
