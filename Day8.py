file = open("Day8.txt","r")
r = file.readlines()
array = []
listScores = []
count = 0
tempcountUp = 0 
tempcountDown = 0 
tempcountLeft = 0 
tempcountRight = 0 
for i in r:
    row = list(i)
    row.remove("\n")
    array.append(row)

for i in range(0,99):
    for j in range(0,99):
        if(i==1):
            print("debug")
        tempi = i-1
        scoreUp = 0 
        while(tempi >= 0): ##check for up 
            if(array[i][j] <= array[tempi][j]):
                tempcountUp += 1 
                break
            else:
                scoreUp += 1 
            tempi -= 1
        if(i!=0 and tempi != -1):
            scoreUp += 1
        tempi = i+1
        scoreDown = 0
        while(tempi <= 98): ##check for down
            if(array[i][j] <= array[tempi][j]):
                tempcountDown += 1
                break
            else:
                scoreDown += 1
            tempi += 1
        if(i!=98 and tempi != 99):
            scoreDown += 1 
        tempj = j-1
        scoreLeft = 0
        while(tempj >= 0): ##check for left
            if(array[i][j] <= array[i][tempj]):
                tempcountLeft += 1 
                break
            else:
                scoreLeft += 1
            tempj -= 1
        if(j != 0 and tempj != -1):
            scoreLeft += 1
        scoreRight = 0
        tempj = j+1
        while(tempj <= 98): ##check for right 
            if(array[i][j] <= array[i][tempj]):
                tempcountRight += 1
                break 
            else:
                scoreRight += 1
            tempj += 1
        if(j != 98 and tempj != 99):
            scoreRight += 1
        if(tempcountUp == 0 or tempcountDown == 0 or tempcountLeft == 0 or tempcountRight == 0 or i == 0 or i == 98 or j == 0 or j == 98):
            count += 1
        tempcountUp = 0
        tempcountDown = 0 
        tempcountLeft = 0
        tempcountRight = 0 
        listScores.append(scoreUp*scoreDown*scoreLeft*scoreRight)

listScores.sort()


print("Output for P1: {}".format(count))
print("Output for P2: {}".format(listScores[len(listScores)-1]))
