file = open("Day6.txt",'r')
r = file.read()
list = []
num = 0 
for i in range(len(r)): 
    if(i>13):  ##change 13 to 3 for P1 
        num += 1
        list.pop(0)
        list.append(r[i])
        if(len(list) == len(set(list))):
            print(num)
            break 
    else:
        num += 1
        list.append(r[i])
        if(i == 13): ##change 13 to 3 for P1 
            if(len(list) == len(set(list))):
                print(num)
                break 

            
