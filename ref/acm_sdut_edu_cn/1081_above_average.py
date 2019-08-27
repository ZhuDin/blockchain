cases = int(input())

for case in range(cases):
    data = input().split()
    peoples = int(data[0])
    
    total = 0
    average = 0
    for grade in data[1:]:
        total += int(grade)
        average = total / peoples

    above = 0
    for grade in data[1:]:
        if(average < int(grade)):
            above += 1
    
    percent = above/peoples*100
    print("%.3f" % percent, end='%')
    print()
