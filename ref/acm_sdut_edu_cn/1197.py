data = input().split()

number = []
number = list(range(1,int(data[0])+1))
#print(number)
step = int(data[1])

def next(number_list, label):
    if(len(number_list)-1 == label):
        return 0
    else:
        return label+1
'''
1 2 3 4 5
1 2   4 5
  2   4 5 
  2   4
      4
'''
label = 0
while(1):
    if(len(number) == 1):
        break
    for num in range(step-1):
        label = next(number, label)
    temp = number[next(number, label)]
    #print('label:' + str(label) + ' temp:' + str(temp))
    number.remove(number[label])
    #print(number)
    label = number.index(temp)

print(str(number[0]))

