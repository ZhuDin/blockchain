data = input().split()

for num in range(len(data)):
    data[num] = int(data[num])

data.sort()

'''
example:
string = 'abaacb'
------------------
#1 from right to left find two consecutive letters: small and large
(small < large) (small on the left)
'aba<ac>b'
'small'=a | large='c'
------------------
#2 from right to left find the replace letters large than small
'abaac<b>'
replace = b
------------------
#3 exchange the small and replace
'aba<b>c<a>'
------------------
#4 sorted string[large:] get the next_permutation
'abab<ca>' sorted<ca> ==> 'ababac'
'''


def arrange(data):
    result = []
    result.append(data[:])
    index = 1
    while(1):
        if result[0][::-1] == data:
            break
        result.append([])  
        
        label = len(data)-1
        small = 0
        for num in data[::-1][1:]:
            if num < data[label]:
                small = num
                break
            label -= 1
        for num in range(len(data)):
            if data[len(data)-1-num] > small:
                temp = small
                data[label-1] = data[len(data)-1-num]
                data[len(data)-1-num] = temp
                break
        result[index].extend(data[:label])
        result[index].extend(sorted(data[label:]))
        data = result[index][:]
        index += 1

    return result

result = []
temp = data[:]
temp.remove(data[3])
result.extend(arrange(temp))

temp = data[:]
temp.remove(data[2])
result.extend(arrange(temp))

temp = data[:]
temp.remove(data[1])
result.extend(arrange(temp))

temp = data[:]
temp.remove(data[0])
result.extend(arrange(temp))

for res in result:
    print('{} {} {}'.format(res[0], res[1], res[2]))

