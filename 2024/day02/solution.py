
with open("input.txt", "r") as file:
    lines = file.readlines()

sum1 = 0
sum2 = 0
for line in lines:
    arr1 = list(map(int, line.split()))
    arr2 = arr1.copy()
    arr3 = arr1.copy()
    length = len(arr1)

    # 1 del
    if all((arr1[i] < arr1[i + 1]) and (arr1[i+1] - arr1[i] < 4) for i in range(length - 1)):
        sum1 += 1
    elif all((arr1[i] > arr1[i + 1]) and (arr1[i] - arr1[i+1] < 4) for i in range(length - 1)):
        sum1 += 1

    # 2. del
    # če je narascujoca je True
    # nujno > 3 ker je 3.5 razlika
    nar_n = 0  # naraščujoč napake
    pad_n = 0  # padajoč napake
    for i in range(length-1):
        # za narascujoca zaporedja
        if not (arr1[i] < arr1[i + 1] and arr1[i+1] - arr1[i] < 4):
            nar_n += 1
            if i != 0 or (i == 0 and arr1[i+1] > arr1[i+2]):
                arr1[i+1] = arr1[i]  # ce je prvi element nicesar ne spreminjas

        elif i == 0 and arr1[i+1] > arr1[i+2]:
            arr1[i+1] = arr1[i]

        # za padajoca zaporedja (lahko bi isto kot za narascujoce pa reversas array)
        if not (arr2[i] > arr2[i + 1] and arr2[i] - arr2[i+1] < 4):
            pad_n += 1
            if i != 0 or (i == 0 and arr2[i+1] < arr2[i+2]):
                arr2[i+1] = arr2[i]

        elif i == 0 and arr2[i+1] < arr2[i+2]:
            arr2[i+1] = arr2[i]

    if nar_n in {0, 1} or pad_n in {0, 1}:  # če je samo ena napaka
        sum2 += 1


print("1. del:", sum1, "\n2. del:", sum2)

