months = {0:0, 1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}

def is_leap_year(year):
    if year % 100 == 0:
        if year % 400 == 0:
            return True
        else:
            return False
    else:
        if year % 4 == 0:
            return True
        else:
            return False

number = int(input())

for num in range(number):
    string = input().split()

    year = int(string[0])

    day = 0

    for month in range(int(string[1])):
        day += months[month]
        if(month == 2 and is_leap_year(year)):
            day += 1

    day += int(string[2])

    print(day)

