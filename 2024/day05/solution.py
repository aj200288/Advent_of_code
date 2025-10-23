file = open("2024/test.txt")

sum = 0
page_prders = False
dict_before = {} #key: number; value: array of numbers before which key number must occur
dict_after = {} #key: number; value: array of number after whick key value must occur
for line in file:
    #določimo ali smo pred ali po prazni vrstici
    if line.strip() == "":
        page_prders = True
        continue

    #shranimo navodila v sezname
    if page_prders == False:
        a, b = map(int, line.split("|"))

        if a in dict_before.keys():
            dict_before[a].append(b)
        else:
            dict_before[a] = [b]

        if b in dict_after.keys():
            dict_after[b].append(a)
        else:
            dict_after[b] = [a]



    else:
        # perverimo ali je naročilo veljavno ali ne
        order = list(map(int, line.strip().split(',')))
        len_order = len(order)
        valid = True

        for i in range(len_order):
            for j in range(i+1, len_order):
                try:
                    if not(order[j] in dict_before[order[i]]):
                        valid = False
                except KeyError:
                    pass

            for k in range(i):
                try:
                    if not(order[k] in dict_after[order[i]]):
                        valid = False
                except KeyError:
                    pass

        if valid:
            indx = (len(order)-1)/2
            sum += order[int(indx)]
            print(order)
        

print("Sum valid:", sum)
file.close()