file1 = open('Day5.txt', 'r')
r = file1.readlines()
list = []
list1,list2,list3,list4,list5,list6,list7,list8,list9 = ([] for i in range(9))
Overall = [list1, list2, list3,list4,list5,list6,list7,list8,list9]
Overall2 = [[], [], [],[], [], [],[] , [], []]

for i in r:
    if i[1] != '1':
        list = list.clear()
        list = []
        for idx, j in enumerate(i):
            list.append(i[idx])
        counter = 1
        listnum = 0
        while(counter < len(i)):
            if i[counter] != ' ' and i[counter] != ']' and i[counter] != '[':
                Overall[listnum].append(i[counter])
                Overall2[listnum].append(i[counter])
            listnum += 1
            counter += 4
    else: 
        break 
#print(Overall)
for j in r: 
    if(j[0] == 'm'):
        lisT = j.split(" ")
        amount = int(lisT[1])
        froM = int(lisT[3])
        to = int(lisT[5])
        for i in range(amount):
            Overall[to-1].insert(0,Overall[froM-1].pop(0))

for k in range(9): ##first letters in each list are the letters on the top of stack for part 1 
    print(Overall[k])

print()
for z in r: 
    if(z[0] == 'm'):
        listD2 = z.split(" ")
        amountD2 = int(listD2[1])
        fromD2 = int(listD2[3])
        toD2 = int(listD2[5])
        copy = amountD2
        for i in range(amountD2):
            Overall2[toD2-1].insert(0,Overall2[fromD2-1].pop(copy-1))
            copy -= 1

for yur in range(9): ##first letters in each list are the letters on the top of stack for part 2 
    print(Overall2[yur])
