class Direc:
    def __init__(self, name1, list1, sum1, previous1, direcs):
        self.n = name1
        self.l = list1
        self.s = sum1 
        self.p = previous1 
        self.d = direcs 

def updateSums(directory, finalCounts):
    if(bool(directory.d)): 
        for i in directory.d:
            count = add_under(i,i.s)
            finalCounts.append(count)
            updateSums(i, finalCounts)
    return finalCounts 

def add_under(directory,sum):
    if(bool(directory.d)):
        for i in directory.d:
            sum += i.s 
            sum = add_under(i,sum)
    return sum 

file = open("Day7.txt","r")
r = file.readline() 
Overall = [] 
previous = Direc("Overall",[],0,0,[])
Overall.append(previous)
final = 0 
while(r):
    if(r[2] == 'c'):
        if(r[5] == '.'):
            previous = previous.p
            r = file.readline()
        else: 
            findName = r.split(" ")
            name = findName[2][:-1]
            r = file.readline()
            if(r[2] == 'l'):
                r = file.readline()
                sum = 0 
                directories = []
                while(r[0] != '$'):
                    elements = r.split(" ")
                    if(elements[0] == 'dir'):
                        directories.append(elements[1])
                    else:
                        sum += int(elements[0])
                    r = file.readline()
                    if(r == ''):
                        break
                newDirectory = Direc(name, directories, sum, previous,[])
                previous.d.append(newDirectory)
                previous = newDirectory
                Overall.append(newDirectory)
        
    else:
        r = file.readline()

sums = [] 
mainDirectory = Overall[0].d[0]
listofSums = updateSums(mainDirectory,[])
listofSums.append(add_under(mainDirectory, 0)+mainDirectory.s)

pleaseBeRight = 0
for k in listofSums:
    if k <= 100000:
        pleaseBeRight += k 
print("Output P1: {0}".format(pleaseBeRight))

total = listofSums[-1]
freespace = 70000000-total
Deletion = 30000000-freespace
answers = []
for z in listofSums:
    if z >= Deletion:
        answers.append(z)
answers.sort()

print("Output P2: {0}".format(answers[0]))
