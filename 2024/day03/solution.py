import re

f = open("input.txt", "r")
file = f.read()

# prvi del
x = re.findall(r"mul\((\d{1,3}),(\d{1,3})\)", file)
x = [(int(a), int(b)) for a, b in x]
total = sum(a * b for a, b in x)
print("1. del:", total)


# drugi del
total = 0
bool = True
x = re.findall(r"mul\((\d{1,3}),(\d{1,3})\)|(do\(\))|(don't\(\))", file)

for a, b, do, dont in x:
    if do:
        bool = True
    elif dont:
        bool = False

    if a and b and bool:
        total += int(a) * int(b)

print("2. del:", total)
