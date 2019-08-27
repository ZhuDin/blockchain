data = input().split('\\')

year = int(data[0])

month = int(data[1])

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

months = {0:0, 1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}

days = months[month]

if is_leap_year(year) and month==2:
    print(days+1)
else:
    print(days)
    
