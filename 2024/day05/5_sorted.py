file = open("2024/test.txt")

sum = 0
page_prders = False
oreder_sequence = []

for line in file:
    #določimo ali smo pred ali po prazni vrstici
    if line.strip() == "":
        page_prders = True
        dict = {oreder_sequence[i]: i for i in range(len(oreder_sequence))}
        continue

    #shranimo navodila v sezname
    if page_prders == False:
        a, b = map(int, line.split("|"))
        
        if a in oreder_sequence and b in oreder_sequence:
            indx_a = oreder_sequence.index(a)
            indx_b = oreder_sequence.index(b)
            if indx_a < indx_b:
                continue
            else:
                oreder_sequence.remove(a)
                oreder_sequence.insert(indx_b, a)

        elif a in oreder_sequence and b not in oreder_sequence:
            indx_a = oreder_sequence.index(a)
            oreder_sequence.insert(indx_a+1, b)

        elif a not in oreder_sequence and b in oreder_sequence:
            indx_b = oreder_sequence.index(b)
            oreder_sequence.insert(indx_b, a)

        else:
            oreder_sequence.append(a)
            oreder_sequence.append(b)



    else:
        order = list(map(int, line.strip().split(',')))
        len_order = len(order)
        valid = True

        for i in range(len_order-1):
            if dict[order[i]] > dict[order[i+1]]:
                valid = False

        if valid:
            print("ok")
            indx = (len(order)-1)/2
            sum += order[int(indx)]

print(sum)

print(oreder_sequence)
file.close()