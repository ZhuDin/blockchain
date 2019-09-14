numbers = int(input())
unprocessed_telephone = []

for number in range(numbers):
    unprocessed_telephone.append(input())

processed_telephone = []
dictionary = {'0':'0', '1':'1', '2':'2', '3':'3', '4':'4',
              '5':'5', '6':'6', '7':'7', '8':'8', '9':'9',
              'A':'2', 'B':'2', 'C':'2', 'D':'3', 'E':'3', 'F':'3', 
              'G':'4', 'H':'4', 'I':'4', 'J':'5', 'K':'5', 'L':'5', 
              'M':'6', 'N':'6', 'O':'6', 'P':'7', 'R':'7', 'S':'7', 
              'T':'8', 'U':'8', 'V':'8', 'W':'9', 'X':'9', 'Y':'9'}

duplicate = 0
telephone_dict = {}
telephone_set = set()

for number in range(numbers):
    processed_telephone.append('')
    for num in range(len(unprocessed_telephone[number])):
        if(unprocessed_telephone[number][num] != '-'):
            processed_telephone[number] += dictionary[unprocessed_telephone[number][num]]
    if(processed_telephone[number] in telephone_dict):
        telephone_dict[processed_telephone[number]] += 1
        duplicate = 1
        telephone_set.add(processed_telephone[number])
    else:
        telephone_dict[processed_telephone[number]] = 1

telephone_set = sorted(telephone_set)
if(duplicate == 0):
    print('No duplicates.')
else:
    for tel in telephone_set:
        print(tel[:3] + '-' + tel[3:] + ' ' + str(telephone_dict[tel]))
