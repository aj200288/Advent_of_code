file_path = "7.txt"
results = {}
sum = 0

with open(file_path, "r") as file:
    for line in file:
        first_part, second_part = line.split(":")
        first_number = int(first_part.strip())
        numbers_after_colon = list(map(int, second_part.strip().split()))
        results[first_number] = numbers_after_colon

for total, values in results.items():
    print(f"{total}: {values}")
    total2 = total

    for value in reversed(values):
        if total % value == 0:
            total /= value
        else:
            total -= value
    if total == 1:
        sum += total2

print("sum:", sum)
