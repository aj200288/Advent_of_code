file = open("2024/test.txt")

list = []
for line in file:
    a, b = map(int, line.split("|"))

    if a in list and b in list:
        indx_a = list.index(a)
        indx_b = list.index(b)
        if indx_a < indx_b:
            continue
        else:
            list.remove(a)
            list.insert(indx_b, a)

    elif a in list and b not in list:
        indx_a = list.index(a)
        list.insert(indx_a+1, b)

    elif a not in list and b in list:
        indx_b = list.index(b)
        list.insert(indx_b, a)

    else:
        list.append(a)
        list.append(b)
        
print(list)

dict = {}
for i in range(len(list)):
    dict[list[i]] = i

print(dict)