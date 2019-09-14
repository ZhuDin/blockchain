floors = input().split()
total_time = 0
floors.append(0)

while(int(floors[0]) != 0):
    total_time = int(floors[1])*6 + 5
    for stop in range(int(floors[0])-1):
        if(int(floors[stop+1]) < int(floors[stop+2])):
            total_time += (int(floors[stop+2]) - int(floors[stop+1])) * 6 + 5
        else:
            total_time += (int(floors[stop+1]) - int(floors[stop+2])) * 4 + 5
    print(total_time)
    floors = input().split()
    floors.append(0)

